#include <Arduino.h>
#include <DNSServer.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <EEPROM.h>
#include <time.h>

#include "ESPAsyncWebServer.h"


// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>


// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview




extern sensors_event_t event;

extern AsyncWebServer server;

extern const char* ssid;
extern const char* passphrase;

extern String st;

// NTP (time.h)
extern struct tm timeinfo;
void printLocalTime(void);
void setTimezone(String timezone);

// PINNING
extern const int output;
extern const int pinTriggerAP;
// const int porteio = 16;
extern const int pinRelay0;
extern const int pinRelay1;
extern const int pinRelay2;
extern const int pinRelay3;
extern const int pinLedWifiAP;
extern const int pinLedWifiSTA;
extern const int analogIn1; // IN1
extern const int analogIn2; // IN2
extern const int analogIn3; // DHT TEMP/HUMIDTY
extern const int analogIn4; 

#define DHTPIN analogIn3     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)
extern DHT_Unified dht;

// setting PWM properties
extern const int freq;
extern const int ledChannel;
extern const int resolution;

extern int humidity1min;
extern int humidity1max;


// DEVAULT VALUE
extern String hostname;
extern String WIFI_AP_Name;
extern char *http_username;
extern char *http_password;

extern String NameRelay0;
extern String NameRelay1;
extern String NameRelay2;
extern String NameRelay3;

extern String NameSensors1;
extern String NameSensors2;
extern String NameSensors3;
extern String NameSensors4;

extern String Relay0_status;
extern String sliderValue;
extern int timeMotor1;
extern String esid;
extern String epass;

extern String OutputStatus[];

// IN
extern float analog1Value;
extern float analog2Value;
extern float analog3Value;
extern float analog4Value;

extern const char* PARAM_INPUT;
extern const int ledChannel;
extern const char* HTTP_GET_PARAM;
extern const char* HTTP_GET_OUT1;
extern const char* HTTP_GET_OUT2;
extern const char* HTTP_GET_OUT3;
extern const char* HTTP_GET_SaveTweak;

// GET PARAM FOR WS_ROT
extern const char* HTTP_GET_PARAM_ROT_UP;
extern const char* HTTP_GET_PARAM_ROT_DOWN;
extern const char* HTTP_GET_PARAM_ROT_RIGHT;
extern const char* HTTP_GET_PARAM_ROT_LEFT;


// EMERGENCY

extern int ECU_STATE; // 0 = OFF, 1 = ON


