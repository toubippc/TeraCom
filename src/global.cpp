#include "global.h"

//Establishing Local server at port 80
AsyncWebServer server(80);

const char* ssid = "Default SSID";
const char* passphrase = "Default passord";

String st;

struct tm timeinfo;
sensors_event_t event;
DHT_Unified dht(DHTPIN, DHTTYPE);

// PINNING
const int output = 2;
const int pinTriggerAP = 15;
const int porteio = 16; // Relay0
const int pinRelay1 = 18;
const int pinRelay2 = 5;
const int pinRelay3 = 17;
const int pinLedWifiAP= 21;
const int pinLedWifiSTA = 19;
const int analogIn1 = 4; // IN1
const int analogIn2 = 0; // IN2
const int analogIn3 = 32;
const int analogIn4 = 33;


// setting PWM properties
const int freq = 5000;
// const int ledChannel = 0;
const int resolution = 8;


// DEVAULT VALUE
String hostname = "axsiot";
String WIFI_AP_Name = "hackme";
char *http_username = "admin";
char *http_password = "*hackme*";
String NameMotor1 = "Relay 0";
String NameRelay1 = "Relay 1";
String NameRelay2 = "Relay 2";
String NameRelay3 = "Relay 3";
String porteState = "Fermer";
String sliderValue = "255";
int timeMotor1 = 1000;

int timer[3][2] = {
    {0,0},
    {8,20},
    {10,16},
};

int termo1[3][2] = {
    {24,24},
    {25,27},
    {26,28}
};

// IN
float analog1Value = 0;
float analog2Value = 0;
float analog3Value = 0;
float analog4Value = 0;

const char* PARAM_INPUT = "value";
const int ledChannel = 0;
const char* HTTP_GET_PARAM = "temp";
const char* HTTP_GET_OUT1 = "out1";
const char* HTTP_GET_OUT2 = "out2";
const char* HTTP_GET_OUT3 = "out3";
const char* HTTP_GET_SaveTweak = "tweakSave";

// GET PARAM FOR WS_ROT
const char* HTTP_GET_PARAM_ROT_UP = "up";
const char* HTTP_GET_PARAM_ROT_DOWN = "down";
const char* HTTP_GET_PARAM_ROT_RIGHT = "right";
const char* HTTP_GET_PARAM_ROT_LEFT = "left";

