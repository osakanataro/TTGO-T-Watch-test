// Please select the model you want to use in config.h
#include "config.h"

#include <WiFi.h>
#include <soc/rtc.h>

#define G_EVENT_VBUS_PLUGIN         _BV(0)
#define G_EVENT_VBUS_REMOVE         _BV(1)
#define G_EVENT_CHARGE_DONE         _BV(2)

#define G_EVENT_WIFI_SCAN_START     _BV(3)
#define G_EVENT_WIFI_SCAN_DONE      _BV(4)
#define G_EVENT_WIFI_CONNECTED      _BV(5)
#define G_EVENT_WIFI_BEGIN          _BV(6)
#define G_EVENT_WIFI_OFF            _BV(7)

enum {
    Q_EVENT_WIFI_SCAN_DONE,
    Q_EVENT_WIFI_CONNECT,
    Q_EVENT_BMA_INT,
    Q_EVENT_AXP_INT,
} ;
#define DEFAULT_SCREEN_TIMEOUT  30*1000

#define WATCH_FLAG_SLEEP_MODE   _BV(1)
#define WATCH_FLAG_SLEEP_EXIT   _BV(2)
#define WATCH_FLAG_BMA_IRQ      _BV(3)
#define WATCH_FLAG_AXP_IRQ      _BV(4)


LV_FONT_DECLARE(IPAexGothic);
LV_FONT_DECLARE(IPAexGothic_48);
LV_IMG_DECLARE(step);

QueueHandle_t g_event_queue_handle = NULL;
EventGroupHandle_t g_event_group = NULL;
EventGroupHandle_t isr_group = NULL;
bool lenergy = false;
TTGOClass *twatch = nullptr;
static lv_obj_t *clock_text = nullptr;
static lv_obj_t *statusBar_text = nullptr;
static lv_obj_t *battery_text = nullptr;
static lv_obj_t *battery_icon = nullptr;
static lv_obj_t *step_text = nullptr;

void setupNetwork()
{
    WiFi.mode(WIFI_STA);
    WiFi.onEvent([](WiFiEvent_t event, WiFiEventInfo_t info) {
        xEventGroupClearBits(g_event_group, G_EVENT_WIFI_CONNECTED);
    }, WiFiEvent_t::SYSTEM_EVENT_STA_DISCONNECTED);

    WiFi.onEvent([](WiFiEvent_t event, WiFiEventInfo_t info) {
        uint8_t data = Q_EVENT_WIFI_SCAN_DONE;
        xQueueSend(g_event_queue_handle, &data, portMAX_DELAY);
    }, WiFiEvent_t::SYSTEM_EVENT_SCAN_DONE);

    WiFi.onEvent([](WiFiEvent_t event, WiFiEventInfo_t info) {
        xEventGroupSetBits(g_event_group, G_EVENT_WIFI_CONNECTED);
    }, WiFiEvent_t::SYSTEM_EVENT_STA_CONNECTED);

    WiFi.onEvent([](WiFiEvent_t event, WiFiEventInfo_t info) {
        //wifi_connect_status(true);
    }, WiFiEvent_t::SYSTEM_EVENT_STA_GOT_IP);
}


void low_energy()
{
    if (twatch->bl->isOn()) {
        xEventGroupSetBits(isr_group, WATCH_FLAG_SLEEP_MODE);
        twatch->closeBL();
        twatch->stopLvglTick();
        twatch->bma->enableStepCountInterrupt(false);
        twatch->displaySleep();
        if (!WiFi.isConnected()) {
            lenergy = true;
            WiFi.mode(WIFI_OFF);
            setCpuFrequencyMhz(20);
        }
    } else {
        twatch->startLvglTick();
        twatch->displayWakeup();
        twatch->rtc->syncToSystem();
        //updateStepCounter(twatch->bma->getCounter());
        //updateBatteryLevel();
        //updateBatteryIcon(LV_ICON_CALCULATION);
        updateTime();
        updateStatusBar();
        updateStep();
        lv_disp_trig_activity(NULL);
        twatch->openBL();
        twatch->bma->enableStepCountInterrupt();
    }
}

lv_obj_t *setupGUI(){
  // --- スタイルの設定 ---
  // 基本スタイル:cont_style
  static lv_style_t cont_style;
  lv_style_init(&cont_style);
  lv_style_set_radius(&cont_style, LV_OBJ_PART_MAIN, 12);
  lv_style_set_bg_color(&cont_style, LV_OBJ_PART_MAIN, LV_COLOR_WHITE);
  lv_style_set_bg_opa(&cont_style, LV_OBJ_PART_MAIN, LV_OPA_COVER);
  lv_style_set_border_width(&cont_style, LV_OBJ_PART_MAIN, 0);
  lv_style_set_text_font(&cont_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);// LV_FONT_MONTSERRAT_16 16 px ASCII + built-in symbol
  lv_style_set_text_color(&cont_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);

  // 日本語表示用 16pt: japanese_style
  static lv_style_t japanese_style;
  lv_style_copy(&japanese_style, &cont_style);
  lv_style_set_text_font(&japanese_style, LV_STATE_DEFAULT, &IPAexGothic);

  // 時計表示部分用 16pt: clock_style
  static lv_style_t clock_style;
  lv_style_copy(&clock_style, &cont_style);
  lv_style_set_text_font(&clock_style, LV_STATE_DEFAULT, &IPAexGothic_48);

  // --- 各要素の描画枠 ---
  // ベース描画スペース: view
  lv_obj_t *view = lv_cont_create(lv_scr_act(), nullptr);
  lv_obj_set_size(view, TFT_WIDTH, TFT_HEIGHT);
  lv_obj_add_style(view, LV_OBJ_PART_MAIN, &cont_style);

  // 時刻表示部分
  clock_text = lv_label_create(view, nullptr);
  lv_obj_add_style(clock_text, LV_OBJ_PART_MAIN, &clock_style);
  lv_label_set_text(clock_text, "00時 00分");
  lv_obj_align(clock_text,view,LV_ALIGN_CENTER,0,0);

  // 最上部のステータスバー
  statusBar_text = lv_obj_create(view, NULL);
  lv_obj_set_size(statusBar_text,100,24);
  lv_obj_add_style(statusBar_text, LV_OBJ_PART_MAIN, &cont_style);
  lv_obj_align(statusBar_text,view,LV_ALIGN_IN_TOP_LEFT,0,0);

  //足アイコンを出そうとしてうまく行っていない
  //lv_obj_t *step_icon = lv_img_create(statusBar_text, NULL);
  //lv_img_set_src(step_icon, &step);
  //lv_obj_add_style(step_icon, LV_OBJ_PART_MAIN, &cont_style);
  //lv_obj_align(step_icon, statusBar_text, LV_ALIGN_IN_LEFT_MID, 5, 5);
  //lv_obj_set_pos(step_icon,60,60);
  
  step_text = lv_label_create(statusBar_text, NULL);
  lv_label_set_text(step_text,"00000");
  lv_obj_add_style(step_text, LV_OBJ_PART_MAIN, &cont_style);
  lv_obj_align(step_text,statusBar_text,LV_ALIGN_IN_RIGHT_MID,0,0);

  // 最上部左側にバッテリー表示
  lv_obj_t *battery_bar = lv_obj_create(view,NULL);
  lv_obj_set_size(battery_bar, 60, 24);
  lv_obj_align(battery_bar,view,LV_ALIGN_IN_TOP_RIGHT,0,0);
  lv_obj_add_style(battery_bar, LV_OBJ_PART_MAIN, &cont_style);
  
  battery_text = lv_label_create(battery_bar, nullptr);
  lv_obj_add_style(battery_text, LV_OBJ_PART_MAIN, &cont_style);
  lv_label_set_text(battery_text, LV_SYMBOL_MINUS);
  lv_obj_align(battery_text,battery_bar,LV_ALIGN_IN_RIGHT_MID,-16,0);

  battery_icon = lv_label_create(battery_bar, nullptr);
  lv_obj_add_style(battery_icon, LV_OBJ_PART_MAIN, &cont_style);
  lv_label_set_text(battery_icon, LV_SYMBOL_MINUS);
  lv_obj_align(battery_icon,battery_bar,LV_ALIGN_IN_LEFT_MID,8,0);

  // 時刻とバッテリーバーの初回表示
  updateTime();
  updateStatusBar();
  updateStep();

  // 定期更新タスク登録
  lv_task_create(lv_update_task, 1000, LV_TASK_PRIO_LOWEST, NULL);
  lv_task_create(lv_slowupdate_task, 30000, LV_TASK_PRIO_LOWEST, NULL);
  
  return view;
}

static void lv_update_task(struct _lv_task_t *data)
{
    updateTime();
    updateStep();
}

static void lv_slowupdate_task(struct _lv_task_t *data)
{
    updateStatusBar();
}

static void updateTime() {
  time_t now;
  struct tm  info;
  char buf[64];
  time(&now);
  localtime_r(&now, &info);
  strftime(buf, sizeof(buf), "%H時 %M分", &info);
  
  lv_label_set_text(clock_text, buf);
}


static void updateStatusBar() {
  TTGOClass *twatch = TTGOClass::getWatch();
  int p = twatch->power->getBattPercentage();
  char buf[64];
  sprintf(buf,"%d\%",p);
  lv_label_set_text(battery_text, buf);
  
  if(p>90){
    lv_label_set_text(battery_icon, LV_SYMBOL_BATTERY_FULL);
  }else if(p>70){
    lv_label_set_text(battery_icon, LV_SYMBOL_BATTERY_3);
  }else if(p>40){
    lv_label_set_text(battery_icon, LV_SYMBOL_BATTERY_2);
  }else if(p>15){
    lv_label_set_text(battery_icon, LV_SYMBOL_BATTERY_1);
  }else{
    lv_label_set_text(battery_icon, LV_SYMBOL_BATTERY_EMPTY);
  }
}

static void updateStep() {
  TTGOClass *twatch = TTGOClass::getWatch();
  char buf[64];
  int p = twatch->bma->getCounter();
  sprintf(buf,"%d\%",p);
  lv_label_set_text(step_text, buf);
}


void setup() {
  Serial.begin(115200);
  
  //Create a program that allows the required message objects and group flags
  g_event_queue_handle = xQueueCreate(20, sizeof(uint8_t));
  g_event_group = xEventGroupCreate();
  isr_group = xEventGroupCreate();
    
  //Initialize TWatch
  twatch = TTGOClass::getWatch();
  twatch->begin();
  
  // Turn on the IRQ used
  twatch->power->adc1Enable(AXP202_BATT_VOL_ADC1 | AXP202_BATT_CUR_ADC1 | AXP202_VBUS_VOL_ADC1 | AXP202_VBUS_CUR_ADC1, AXP202_ON);
  twatch->power->enableIRQ(AXP202_VBUS_REMOVED_IRQ | AXP202_VBUS_CONNECT_IRQ | AXP202_CHARGING_FINISHED_IRQ, AXP202_ON);
  twatch->power->clearIRQ();
  
  // Turn off unused power
  twatch->power->setPowerOutPut(AXP202_EXTEN, AXP202_OFF);
  twatch->power->setPowerOutPut(AXP202_DCDC2, AXP202_OFF);
  twatch->power->setPowerOutPut(AXP202_LDO3, AXP202_OFF);
  twatch->power->setPowerOutPut(AXP202_LDO4, AXP202_OFF);
  
  //Initialize lvgl
  twatch->lvgl_begin();

  //Initialize bma423
  twatch->bma->begin();
  //Enable BMA423 interrupt
  twatch->bma->attachInterrupt();
  
  //Connection interrupted to the specified pin
  pinMode(BMA423_INT1, INPUT);
  attachInterrupt(BMA423_INT1, [] {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    EventBits_t  bits = xEventGroupGetBitsFromISR(isr_group);
    if (bits & WATCH_FLAG_SLEEP_MODE){
      //! For quick wake up, use the group flag
      xEventGroupSetBitsFromISR(isr_group, WATCH_FLAG_SLEEP_EXIT | WATCH_FLAG_BMA_IRQ, &xHigherPriorityTaskWoken);
    }else{
      uint8_t data = Q_EVENT_BMA_INT;
      xQueueSendFromISR(g_event_queue_handle, &data, &xHigherPriorityTaskWoken);
    }

    if (xHigherPriorityTaskWoken){
      portYIELD_FROM_ISR ();
    }
  }, RISING);

  // Connection interrupted to the specified pin
  pinMode(AXP202_INT, INPUT);
  attachInterrupt(AXP202_INT, [] {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    EventBits_t  bits = xEventGroupGetBitsFromISR(isr_group);
    if (bits & WATCH_FLAG_SLEEP_MODE){
      //! For quick wake up, use the group flag
      xEventGroupSetBitsFromISR(isr_group, WATCH_FLAG_SLEEP_EXIT | WATCH_FLAG_AXP_IRQ, &xHigherPriorityTaskWoken);
    } else {
      uint8_t data = Q_EVENT_AXP_INT;
      xQueueSendFromISR(g_event_queue_handle, &data, &xHigherPriorityTaskWoken);
    }
    if (xHigherPriorityTaskWoken){
      portYIELD_FROM_ISR ();
    }
  }, FALLING);

  //Check if the RTC clock matches, if not, use compile time
  twatch->rtc->check();
  //Synchronize time to system time
  twatch->rtc->syncToSystem();

  //When the initialization is complete, turn on the backlight
  twatch->openBL();

  setupGUI();
}

void loop() {
  bool  rlst;
  uint8_t data;
  //static uint32_t start = 0;
  
  //! Fast response wake-up interrupt
  EventBits_t  bits = xEventGroupGetBits(isr_group);
  if (bits & WATCH_FLAG_SLEEP_EXIT) {
    if (lenergy) {
      lenergy = false;
      setCpuFrequencyMhz(160);
    }
    low_energy();
    if (bits & WATCH_FLAG_BMA_IRQ) {
      do {
        rlst =  twatch->bma->readInterrupt();
      } while (!rlst);
      xEventGroupClearBits(isr_group, WATCH_FLAG_BMA_IRQ);
    }
    if (bits & WATCH_FLAG_AXP_IRQ) {
      twatch->power->readIRQ();
      twatch->power->clearIRQ();
      //TODO: Only accept axp power pek key short press
      xEventGroupClearBits(isr_group, WATCH_FLAG_AXP_IRQ);
    }
    xEventGroupClearBits(isr_group, WATCH_FLAG_SLEEP_EXIT);
    xEventGroupClearBits(isr_group, WATCH_FLAG_SLEEP_MODE);
  }
  if ((bits & WATCH_FLAG_SLEEP_MODE)) {
    //! No event processing after entering the information screen
    return;
  }

  //! Normal polling
  if (xQueueReceive(g_event_queue_handle, &data, 5 / portTICK_RATE_MS) == pdPASS) {
    switch (data) {
      case Q_EVENT_BMA_INT:
        do {
          rlst =  twatch->bma->readInterrupt();
          } while (!rlst);
        //! setp counter
        if (twatch->bma->isStepCounter()) {
          //updateStepCounter(twatch->bma->getCounter());
        }
        break;
      case Q_EVENT_AXP_INT:
        twatch->power->readIRQ();
        if (twatch->power->isVbusPlugInIRQ()) {
          //updateBatteryIcon(LV_ICON_CHARGE);
        }
        if (twatch->power->isVbusRemoveIRQ()) {
          //updateBatteryIcon(LV_ICON_CALCULATION);
        }
        if (twatch->power->isChargingDoneIRQ()) {
          //updateBatteryIcon(LV_ICON_CALCULATION);
        }
        if (twatch->power->isPEKShortPressIRQ()) {
          twatch->power->clearIRQ();
          low_energy();
          return;
        }
        twatch->power->clearIRQ();
        break;
      //case Q_EVENT_WIFI_SCAN_DONE: {
      //  int16_t len =  WiFi.scanComplete();
      //  for (int i = 0; i < len; ++i) {
      //    wifi_list_add(WiFi.SSID(i).c_str());
      //  }
      //  break;
      //}
      default:
        break;
    }

  }
  if (lv_disp_get_inactive_time(NULL) < DEFAULT_SCREEN_TIMEOUT) {
    lv_task_handler();
  } else {
    low_energy();
  }
}
