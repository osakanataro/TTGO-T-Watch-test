#define LILYGO_TWATCH_2020_V1        // If you are using T-Watch-2020 version, please open this macro definition

#include <TTGO.h>
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

QueueHandle_t g_event_queue_handle = NULL;
EventGroupHandle_t g_event_group = NULL;
EventGroupHandle_t isr_group = NULL;
bool lenergy = false;
TTGOClass *twatch = nullptr;


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
            rtc_clk_cpu_freq_set(RTC_CPU_FREQ_2M);
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

void setup() {
  Serial.begin(115200);

  twatch = TTGOClass::getWatch();
  //Initialize TWatch
  twatch->begin();

}

void loop() {
  // put your main code here, to run repeatedly:

}
