// => Hardware select
// #define LILYGO_WATCH_2019_WITH_TOUCH     // To use T-Watch2019 with touchscreen, please uncomment this line
// #define LILYGO_WATCH_2019_NO_TOUCH          // To use T-Watch2019 Not touchscreen , please uncomment this line
#define LILYGO_WATCH_2020_V1             //To use T-Watch2020, please uncomment this line


// => Function select
#define LILYGO_WATCH_LVGL                   //To use LVGL, you need to enable the macro LVGL

#include <LilyGoWatch.h>

//#define RTC_TIME_ZONE "JST-9"
#define RTC_TIME_ZONE "TZ_Asia_Tokyo"

#define EVERY_1SEC  1000
#define EVERY_2SEC  2000
#define EVERY_5SEC  5000
#define EVERY_10SEC 10000
#define EVERY_30SEC 30000
#define EVERY_1MIN  60000

const char* ssid     = "ssid string";
const char* password = "password string";
