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


LV_FONT_DECLARE(IPAexGothic)

QueueHandle_t g_event_queue_handle = NULL;
EventGroupHandle_t g_event_group = NULL;
EventGroupHandle_t isr_group = NULL;
bool lenergy = false;
TTGOClass *twatch = nullptr;
static lv_obj_t *test_text = nullptr;

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
        lv_disp_trig_activity(NULL);
        twatch->openBL();
        twatch->bma->enableStepCountInterrupt();
    }
}

lv_obj_t *setupGUI(){
  static lv_style_t cont_style;
  lv_style_init(&cont_style);
  lv_style_set_radius(&cont_style, LV_OBJ_PART_MAIN, 12);
  lv_style_set_bg_color(&cont_style, LV_OBJ_PART_MAIN, LV_COLOR_WHITE);
  lv_style_set_bg_opa(&cont_style, LV_OBJ_PART_MAIN, LV_OPA_COVER);
  lv_style_set_border_width(&cont_style, LV_OBJ_PART_MAIN, 0);
  
  //lv_style_set_text_font(&cont_style, LV_STATE_DEFAULT, &IPAexGothic);
  lv_style_set_text_font(&cont_style, LV_STATE_DEFAULT, &lv_font_montserrat_16);// LV_FONT_MONTSERRAT_16 16 px ASCII + built-in symbol
  //lv_style_set_text_font(&cont_style, LV_STATE_DEFAULT, &lv_font_simsun_16_cjk); // LV_FONT_SIMSUN_16_CJK 16 px 1000 most common CJK radicals
  //  If you want to use LV_FONT_SIMSUN_16_CJK, Modify Arduino\libraries\TTGO_TWatch_Library-master\src\lv_conf.h 
  //  "#define LV_FONT_SIMSUN_16_CJK 1". But it's not include Japanese fonts.
  lv_style_set_text_color(&cont_style, LV_STATE_DEFAULT, LV_COLOR_BLACK);

  static lv_style_t japanese_style;
  lv_style_copy(&japanese_style, &cont_style);
  lv_style_set_text_font(&japanese_style, LV_STATE_DEFAULT, &IPAexGothic);

  lv_obj_t *view = lv_cont_create(lv_scr_act(), nullptr);
  lv_obj_set_size(view, 240, 240);
  lv_obj_add_style(view, LV_OBJ_PART_MAIN, &cont_style);

  //lv_obj_t *test_text = lv_label_create(view, nullptr);
  test_text = lv_label_create(view, nullptr);
  lv_obj_add_style(test_text, LV_OBJ_PART_MAIN, &japanese_style);
  lv_label_set_text(test_text, LV_SYMBOL_OK LV_SYMBOL_WIFI LV_SYMBOL_PLAY "Applyテスト");
  lv_obj_align(test_text,view,LV_ALIGN_CENTER,0,0);

  lv_obj_t *statusBar_text = lv_label_create(view, nullptr);
  lv_obj_add_style(statusBar_text, LV_OBJ_PART_MAIN, &cont_style);
  lv_label_set_text(statusBar_text, LV_SYMBOL_OK LV_SYMBOL_WIFI "Applyテスト");
  lv_obj_align(statusBar_text,view,LV_ALIGN_IN_TOP_LEFT,0,0);

  updateTime();

  lv_task_create(lv_update_task, 1000, LV_TASK_PRIO_LOWEST, NULL);
  return view;
}

static void lv_update_task(struct _lv_task_t *data)
{
    updateTime();
}

static void updateTime() {
  time_t now;
  struct tm  info;
  char buf[64];
  time(&now);
  localtime_r(&now, &info);
  strftime(buf, sizeof(buf), "%H 時 %M 分", &info);
  
  lv_label_set_text(test_text, buf);
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
