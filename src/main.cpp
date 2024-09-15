#include "global.h"
#include "wifiSettings.h"
#include "server.h"
#include "automation.h"
#include "wpse324.h"


//UPDATE variabls to blink without delay:
const int led = 2;
unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)
int ledState = LOW;             // ledState used to set the LED


//Variables Server
String esid = "";
String epass = "";
int i = 0;
// Get Wifi mode trigger
int switchWifiMode = 3;

// NTP (time.h)
const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 0;
const int   daylightOffset_sec = 0;

// SENSORS delay
uint32_t delayMS;

//Function Decalration
void launchWeb(void);
void setupAP(void);

void setup()
{

  Serial.begin(115200); //Initialising if(DEBUG)Serial Monitor
  Serial.println();
  Serial.println("Disconnecting current wifi connection");
  WiFi.disconnect();
  Serial.println("System Initializing ... ");

  pinMode(porteio, OUTPUT);
  pinMode(pinRelay1, OUTPUT);
  pinMode(pinRelay2, OUTPUT);
  pinMode(pinRelay3, OUTPUT);
  pinMode(pinLedWifiAP, OUTPUT);
  pinMode(pinLedWifiSTA, OUTPUT);
  pinMode(pinTriggerAP, INPUT);

  pinMode(analogIn1, OUTPUT);
  pinMode(analogIn2, OUTPUT);
  //pinMode(analogIn3, INPUT);
  //pinMode(analogIn4, INPUT);

  digitalWrite(porteio, LOW);
  digitalWrite(pinRelay1, LOW);
  digitalWrite(pinRelay2, LOW);
  digitalWrite(pinRelay3, LOW);
  digitalWrite(pinLedWifiAP, LOW);
  digitalWrite(pinLedWifiSTA, LOW);
  digitalWrite(analogIn1, LOW);
  digitalWrite(analogIn2, LOW);

  
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(output, ledChannel);
  
  // configure PWM frequency
  ledcWrite(ledChannel, sliderValue.toInt());

  //Initialasing EEPROM
  EEPROM.begin(512); 
  delay(10);
  

  //---------------------------------------- Read eeprom for ssid and pass
  Serial.println("Reading EEPROM ssid");
  for (int i = 0; i < 32; ++i)
  {
    esid += char(EEPROM.read(i));
  }
  Serial.println();
  Serial.print("SSID: ");
  Serial.println(esid);
  Serial.println("Reading EEPROM pass");

  for (int i = 32; i < 96; ++i)
  {
    epass += char(EEPROM.read(i));
  }
  Serial.print("PASS: ");
  Serial.println(epass);

  // Configure WiFi
  WiFi.mode(WIFI_STA);
  WiFi.config(INADDR_NONE, INADDR_NONE, INADDR_NONE, INADDR_NONE);
  WiFi.setHostname(hostname.c_str()); //define hostname
  WiFi.disconnect();
  delay(100);


  // END initialization, start loop
  Serial.println();
  Serial.println("Startup : ");
  Serial.println(hostname.c_str());
  
  // SENSORS
  
   dht.begin();
   wpse324init();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
         
}


void loop() {

 // analog1Value = analogRead(analogIn1);
 // analog2Value = analogRead(analogIn2);
  // analog3Value = analogRead(analogIn3); // DHT11
  analog4Value = analogRead(analogIn4);

  //String strAnalog1 = "Analogique 34 : "+analog1Value;
  Serial.printf("Analogique 3 : %d \n",analog3Value);
  Serial.printf("Analogique 4 : %d \n", analog4Value);

  // Get Wifi mode trigger
  // Pin trigger LOW && connection false
  if (digitalRead(pinTriggerAP) != 1 && switchWifiMode != digitalRead(pinTriggerAP)) {
    Serial.println(" Wifi station initialization ...");
    switchWifiMode = 0;
    setupSTA();
    if (WiFi.status() == WL_CONNECTED)
      {
          // Init and get the time
        configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        setTimezone("CET-1CEST,M3.5.0,M10.5.0/3");
        launchWeb();
        AsyncElegantOTA.loop();
      }
  } 
  else if(digitalRead(pinTriggerAP) == 1 && switchWifiMode != digitalRead(pinTriggerAP)) {
    Serial.println(" Wifi access point initialization ...");
    setupAP();// Setup HotSpot
    switchWifiMode = 1;
  }
  else {
    // When no connection or lost connection
    if(WiFi.status() != WL_CONNECTED && switchWifiMode == 0 ) {
      // when the connection is lost
      if(WiFi.status() == WL_CONNECTION_LOST ) {
        Serial.println(" Lost connection, reconnect .. ");
        WiFi.reconnect();
      }
      // when disconnected from a network
      else if(WiFi.status() == WL_DISCONNECTED) {
        Serial.println(" Disconnected !");
        switchWifiMode = 1;
      }
      // when the connection fails for all the attempts
      else if(WiFi.status() == WL_CONNECT_FAILED) {
        Serial.println(" Connection failed, switch to Access Point mode !");
        switchWifiMode = 1;
      }
    }
    else if(WiFi.status() == WL_CONNECTED) {
        Serial.println("WiFi connected !");
        printLocalTime();
    }
      // Default
      // switchWifiMode = digitalRead(pinTriggerAP);
      String mode = (switchWifiMode == 1) ? "Access Point" : "Station";
      Serial.printf(" Wifi on : %s \n",mode.c_str());
      IPAddress ip = (switchWifiMode == 1) ? WiFi.softAPIP() : WiFi.localIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      Serial.println(ipStr.c_str());
        // Delay between measurements.
        // delay(delayMS);
        // Get temperature event and print its value.
        
        dht.temperature().getEvent(&event);
        if (isnan(event.temperature)) {
          Serial.println(F("Error reading temperature!"));
        }
        else {
          Serial.print(F("Temperature: "));
          Serial.print(event.temperature);
          Serial.println(F("°C"));
        }
        // Get humidity event and print its value.
        dht.humidity().getEvent(&event);
        if (isnan(event.relative_humidity)) {
          Serial.println(F("Error reading humidity!"));
        }
        else {
          Serial.print(F("Humidity: "));
          Serial.print(event.relative_humidity);
          Serial.println(F("%"));
        }
        wpse324();
        automation();
      delay(2000);
    
  }

}


void launchWeb()
{
  Serial.println("");
  if (WiFi.status() == WL_CONNECTED)
    Serial.println("WiFi connected");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  createWebServer();
  // Start the server
  server.begin();
  Serial.println("Server started");
}


void setupAP(void)
{
  scanWifi();
  WiFi.disconnect();
  delay(100);
  WiFi.softAP(WIFI_AP_Name.c_str(), "");
  Serial.println("Initializing_softap_for_wifi credentials_modification");
  launchWeb();
  digitalWrite(pinLedWifiSTA, LOW);
  digitalWrite(pinLedWifiAP, HIGH);
  Serial.println("over");
}



void printLocalTime(){
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  Serial.print("Day of week: ");
  Serial.println(&timeinfo, "%A");
  Serial.print("Month: ");
  Serial.println(&timeinfo, "%B");
  Serial.print("Day of Month: ");
  Serial.println(&timeinfo, "%d");
  Serial.print("Year: ");
  Serial.println(&timeinfo, "%Y");
  Serial.print("Hour: ");
  Serial.println(&timeinfo, "%H");
  Serial.print("Hour (12 hour format): ");
  Serial.println(&timeinfo, "%I");
  Serial.print("Minute: ");
  Serial.println(&timeinfo, "%M");
  Serial.print("Second: ");
  Serial.println(&timeinfo, "%S");

  Serial.println("Time variables");
  char timeHour[3];
  strftime(timeHour,3, "%H", &timeinfo);
  Serial.println(timeHour);
  char timeWeekDay[10];
  strftime(timeWeekDay,10, "%A", &timeinfo);
  Serial.println(timeWeekDay);
  Serial.println();
}

void setTimezone(String timezone){
  Serial.printf("  Setting Timezone to %s\n",timezone.c_str());
  setenv("TZ",timezone.c_str(),1);  //  Now adjust the TZ.  Clock settings are adjusted to show the new local time
  tzset();
}