#include <Arduino.h>
#include <DNSServer.h>
#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include "ESPAsyncWebServer.h"
#include <EEPROM.h>


extern AsyncWebServer server;

extern const char* ssid;
extern const char* passphrase;

extern String st;

// PINNING
extern const int output;
extern const int pinTriggerAP;
// const int porteio = 16;
extern const int pinRelay1;
extern const int pinRelay2;
extern const int pinRelay3;
extern const int pinLedWifiAP;
extern const int pinLedWifiSTA;
extern const int porteio;
extern const int analogIn1; // IN1
extern const int analogIn2; // IN2
extern const int analogIn3;
extern const int analogIn4;

// setting PWM properties
extern const int freq;
extern const int ledChannel;
extern const int resolution;


// DEVAULT VALUE
extern String hostname;
extern String WIFI_AP_Name;
extern char *http_username;
extern char *http_password;
extern String NameMotor1;
extern String NameRelay1;
extern String NameRelay2;
extern String NameRelay3;
extern String porteState;
extern String sliderValue;
extern int timeMotor1;
extern String esid;
extern String epass;

// IN
extern int analog1Value;
extern int analog2Value;
extern int analog3Value;
extern int analog4Value;

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
