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
const int pinRelay0 = 16; // Ventilation - Climatisation : PIN 16
const int pinRelay1 = 18; // Spot : PIN 18
const int pinRelay2 = 5; // UV : PIN 5
const int pinRelay3 = 17; // Chauffage : PIN 17
const int pinLedWifiAP= 21;
const int pinLedWifiSTA = 19;
const int analogIn1 = 0; // IN1 sonde 1 : PIN 0
const int analogIn2 = 4; // IN2 sonde 2 : PIN 4
const int analogIn3 = 32; // DHT : PIN 32
const int analogIn4 = 35; // FREE : PIN 35

// setting PWM properties
const int freq = 5000;
// const int ledChannel = 0;
const int resolution = 8;


// DEVAULT VALUE
String hostname = "axsiot";
String WIFI_AP_Name = "hackme";
char *http_username = "admin";
char *http_password = "*hackme*";
String ModeIcon = "";

int manualMode = 0;
bool curveMode = 0;
/*
CurveProgram curveProgram = {
    Default coefficients : {0.15f, 0.08f, 0.07f, 0.04f, 0.15f, 0.05f, 180},
    Devault value : {
        Jour ( sert de multiplicateur de coefficient ), 
        Température Point Chaud Sol (Jour), 
        Température Point Chaud Sol (Nuit), 
        Température Point Froid Sol (Jour), 
        Température Point Froid Sol (Nuit), 
        Température Air Ambiant (Jour), 
        Température Air Ambiant (Nuit), 
        Heures.Minutes/jour (12.34 = 12 h 34 min)
    }
};
*/
CurveSeason curveDate = {
    {1, 4},
    {1, 8}
};

CurveProgram curveProgram = {
    {0.15f, 0.08f, 0.07f, 0.04f, 0.15f, 0.05f, 180},
    {1, 35.0f, 25.0f, 24.0f, 20.0f, 35.0f, 22.0f, 14.0f}
};

String NameRelay0 = "Vent / Clim";
String NameRelay1 = "Spot / Lampe chauffante";
String NameRelay2 = "UV / Lampe jour";
String NameRelay3 = "Chauffage";

String NameSensors1 = "Zone chaude";
String NameSensors2 = "Zone froide";
String NameSensors3 = "Ambiante";
String NameSensors4 = "Humidité";

String Relay0_status = "Fermer";
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
// Zone chaude
float analog1Value = 0; // Zone chaude
float analog2Value = 0; // Zone froide
float analog3Value = 0; // Zone tempérée
float analog4Value = 0; // Humidité

const char* PARAM_INPUT = "value";
const int ledChannel = 0;
const char* HTTP_GET_PARAM = "temp";
const char* HTTP_GET_OUT1 = "out1";
const char* HTTP_GET_OUT2 = "out2";
const char* HTTP_GET_OUT3 = "out3";
const char* HTTP_GET_OUT0 = "out0";
const char* HTTP_GET_SaveTweak = "tweakSave";

// GET PARAM FOR WS_ROT
const char* HTTP_GET_PARAM_ROT_UP = "up";
const char* HTTP_GET_PARAM_ROT_DOWN = "down";
const char* HTTP_GET_PARAM_ROT_RIGHT = "right";
const char* HTTP_GET_PARAM_ROT_LEFT = "left";

int ECU_STATE = 0;