#include "server.h"
#include "wifiSettings.h"
//#include <ElegantOTA.h>

#include "html/style.h"
#include "html/network_html.h"
#include "html/tweak_html.h"
// #include "dc_motors/move.h"
#include "html/update_html.h"
#include "html/index_html.h"
#include "html/program_html.h"
#include "html/settings_html.h"
#include "html/summer_scenario_html.h"

// DEVAULT VALUE
String stateout0 = "OFF";
String stateout1 = "OFF";
String stateout2 = "OFF";
String stateout3 = "OFF";
String analog1 = "0";
String analog2 = "0";
String analog3 = "0";
String analog4 = "0";
String content;
int statusCode;

/*
unsigned long ota_progress_millis = 0;

void onOTAStart() {
  // Log when OTA has started
  Serial.println("OTA update started!");
  // <Add your own code here>
}

void onOTAProgress(size_t current, size_t final) {
  // Log every 1 second
  if (millis() - ota_progress_millis > 1000) {
    ota_progress_millis = millis();
    Serial.printf("OTA Progress Current: %u bytes, Final: %u bytes\n", current, final);
  }
}

void onOTAEnd(bool success) {
  // Log when OTA has finished
  if (success) {
    Serial.println("OTA update finished successfully!");
  } else {
    Serial.println("There was an error during OTA update!");
  }
  // <Add your own code here>
}
*/


// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  
  if (var == "SLIDERVALUE"){
    return sliderValue;
  } else {
    sliderValue = 128;
  }

  if(var == "RELAY0") {return NameRelay0; }
  if(var == "RELAY1") {return NameRelay1; }
  if(var == "RELAY2") {return NameRelay2; }
  if(var == "RELAY3") {return NameRelay3; }

  if(var == "SONDE1") {return NameSensors1; }
  if(var == "SONDE2") {return NameSensors2; }
  if(var == "SONDE3") {return NameSensors3; }
  if(var == "SONDE4") {return NameSensors4; }

  if(var == "STATEOUT0") {
    return stateout0  = ( digitalRead(pinRelay0) == OFF ) ? "OFF" : "ON";
  }
    if(var == "STATEOUT1") {
    return stateout1  = ( digitalRead(pinRelay1) == OFF ) ? "OFF" : "ON";
  }
    if(var == "STATEOUT2") {
    return stateout2  = ( digitalRead(pinRelay2) == OFF ) ? "OFF" : "ON";
  }
    if(var == "STATEOUT3") {
    return stateout3  = ( digitalRead(pinRelay3) == OFF ) ? "OFF" : "ON";
  }

  if(var == "ANALOG1") {
    analog1 = String(analog1Value);
    return analog1;
  }
  if(var == "ANALOG2") {
    analog2 = String(analog2Value);
    return analog2;
  }
  
  if(var == "ANALOG3") {
    analog3 = String(analog3Value);
    return analog1;
  }
  if(var == "ANALOG4") {
    analog4 = String(analog4Value);
    return analog1;
  }
  if(var == "DHT1") {
    
    return String(analog3Value);
  }
  if(var == "HUMIDITY") {
    return String(analog4Value);
  }
  if(var == "TIME") {
    String time = String(timeinfo.tm_hour)+":"+String(timeinfo.tm_min);
    return String(time);
  }
  if(var == "ECU") {
    String ecuState = (ECU_STATE == 0) ? "OFF" : "ON";
    return ecuState;
  }
  
  
  Serial.println(var);
  return String();
}

// Router URL AND GET PARAM
void createWebServer()
{
  {
    /*
    ElegantOTA.begin(&server);    // Start ElegantOTA
    // ElegantOTA callbacks
    ElegantOTA.onStart(onOTAStart);
    ElegantOTA.onProgress(onOTAProgress);
    ElegantOTA.onEnd(onOTAEnd);
    */
    server.begin();
    Serial.println("HTTP server started");
    ElegantOTA.begin(&server);    // Start ElegantOTA
    ElegantOTA.loop();
    
    NameRelay0 = (EEPROM.readString(64) == "") ? "Relay 0" : EEPROM.readString(64);
    NameRelay1 = (EEPROM.readString(128) == "") ? "Relay 1" : EEPROM.readString(128);
    NameRelay2 = (EEPROM.readString(196) == "") ? "Relay 2" : EEPROM.readString(196);
    NameRelay3 = (EEPROM.readString(256) == "") ? "Relay 3" : EEPROM.readString(256);
    
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
    });
    
    // return time
    server.on("/gettime", HTTP_GET, [](AsyncWebServerRequest *request){
      String timeString = String(timeinfo.tm_mon) + " " + String(timeinfo.tm_mday) + " " + String(timeinfo.tm_year) + " " + String(timeinfo.tm_hour) + ":" + String(timeinfo.tm_min) + ":" + String(timeinfo.tm_sec);
      char buff[70];
      strftime(buff, sizeof buff, " %B %d %Y %T ", &timeinfo);
      content = "{\"time\" : \""+ String(buff) +"\"}";
      statusCode = 200;
      request->send(statusCode, "application/json", content);
    });
    
    server.on("/getdht11", HTTP_GET, [](AsyncWebServerRequest *request){
      /* dht.temperature().getEvent(&event);
      String temperature = String(event.temperature);
      dht.humidity().getEvent(&event);
      String humitidty = String(event.relative_humidity); */
      content = "{\"temperature_0\" : "+String(analog1Value)+",\"temperature_1\" : "+String(analog2Value)+",\"dht_1\" : "+String(analog3Value)+", \"humidity_1\" : "+String(analog4Value)+"}";
      statusCode = 200;
      request->send(statusCode, "application/json", content);
    });

  // Send a GET request to <ESP_IP>/slider?value=<inputMessage>
  server.on("/slider", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage;
    // GET input1 value on <ESP_IP>/slider?value=<inputMessage>
    if (request->hasParam(PARAM_INPUT)) {
      inputMessage = request->getParam(PARAM_INPUT)->value();
      sliderValue = inputMessage;
      ledcWrite(ledChannel, sliderValue.toInt());
    }
    // GET input1 value on <ESP_IP>?temp=<inputMessage>
    else if(request->hasParam(HTTP_GET_PARAM)) {
      inputMessage = request->getParam(HTTP_GET_PARAM)->value();
      Relay0_status = inputMessage;
      // TODO : ON/OFF function here
     
      if (Relay0_status == "Fermer"){
         digitalWrite(pinRelay0, HIGH);
         digitalWrite(analogIn1, LOW);
         digitalWrite(analogIn2, HIGH);
         delay(timeMotor1);
      digitalWrite(analogIn1, LOW);
         digitalWrite(analogIn2, LOW);
         digitalWrite(pinRelay0, LOW);
      } else {
          digitalWrite(pinRelay0, HIGH);
          digitalWrite(analogIn2, LOW);
         digitalWrite(analogIn1, HIGH);
         delay(timeMotor1);
          digitalWrite(analogIn1, LOW);
         digitalWrite(analogIn2, LOW);
         digitalWrite(pinRelay0, LOW);
        }
    }



    // GET input1 value on <ESP_IP>/slider?outX=<inputMessage>
    else if(request->hasParam(HTTP_GET_OUT1)) {
      inputMessage = request->getParam(HTTP_GET_OUT1)->value();
      stateout1 = inputMessage;
      // TODO : ON/OFF function here
      
      digitalWrite(pinRelay1, !digitalRead(pinRelay1) );
    }
    else if(request->hasParam(HTTP_GET_OUT2)) {
      inputMessage = request->getParam(HTTP_GET_OUT2)->value();
      stateout2 = inputMessage;
      // TODO : ON/OFF function here
      
      digitalWrite(pinRelay2, !digitalRead(pinRelay2) );
    }
    else if(request->hasParam(HTTP_GET_OUT3)) {
      inputMessage = request->getParam(HTTP_GET_OUT3)->value();
      stateout3 = inputMessage;
      // TODO : ON/OFF function here
      
      digitalWrite(pinRelay3, !digitalRead(pinRelay3) );
    }
    else {
      inputMessage = "No message sent";
    }
    Serial.println(inputMessage);
    request->send(200, "text/plain", "OK");
  });

  // Get Network HTML Settings
    server.on("/network", [] (AsyncWebServerRequest *request) {
        // scanWifi();
      content = style_css();
      content += network_html();
      request->send(200, "text/html", content);
    });
  
  // Get Scan
    server.on("/scan", [] (AsyncWebServerRequest *request) {
      //setupAP();
      IPAddress ip = WiFi.softAPIP();
      String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
      content = style_css();
      content += "<!DOCTYPE HTML>\r\n<html>go back";
      request->send(200, "text/html", content);
    });

  // Put network settings
    server.on("/setting", [] (AsyncWebServerRequest *request) {
      if(!request->authenticate(http_username, http_password))
        return request->requestAuthentication();
      String qsid = request->arg("ssid");
      String qpass = request->arg("pass");
      if (qsid.length() > 0 && qpass.length() > 0) {
        Serial.println("clearing eeprom");
        for (int i = 0; i < 96; ++i) {
          EEPROM.write(i, 0);
        }
        Serial.println(qsid);
        Serial.println("");
        Serial.println(qpass);
        Serial.println("");

        Serial.println("writing eeprom ssid:");
        for (int i = 0; i < qsid.length(); ++i)
        {
          EEPROM.write(i, qsid[i]);
          Serial.print("Wrote: ");
          Serial.println(qsid[i]);
        }
        Serial.println("writing eeprom pass:");
        for (int i = 0; i < qpass.length(); ++i)
        {
          EEPROM.write(32 + i, qpass[i]);
          Serial.print("Wrote: ");
          Serial.println(qpass[i]);
        }
        EEPROM.commit();

        content = "{\"Success\":\"saved to eeprom... reset to boot into new wifi\"}";
        statusCode = 200;
        ESP.restart();
      } else {
        content = "{\"Error\":\"404 not found\"}";
        statusCode = 404;
        Serial.println("Sending 404");
      }
      //request->addHeader("Access-Control-Allow-Origin", "*");
      request->send(statusCode, "application/json", content);

    });

    // Get Tweak HTML settings
    server.on("/tweak", [] (AsyncWebServerRequest *request) {
      if(!request->authenticate(http_username, http_password))
        return request->requestAuthentication();
      if(request->args() != 0) {
        timeMotor1 = request->arg("timeMotor1").toInt();
        NameRelay0 = request->arg("relay0");
        NameRelay1 = request->arg("relay1");
        NameRelay2 = request->arg("relay2");
        NameRelay3 = request->arg("relay3");
        
        // EEPROM WRITE HERE
        EEPROM.writeString(64, NameRelay0);
        EEPROM.writeString(128, NameRelay1);
        EEPROM.writeString(196, NameRelay2);
        EEPROM.writeString(256, NameRelay3);
        EEPROM.commit();

        // sliderValue = request->arg("sliderMotor1");
      }
      content = style_css();
      content += tweak_html();
      request->send(200, "text/html", content);
    });
    
    // ECU Update HTML button
    server.on("/ecu", [] (AsyncWebServerRequest *request) {
      ECU_STATE = !ECU_STATE;
      request->send(200, "text/plain", "OK");
    });
    
    // Settings HTML page
    server.on("/program", [] (AsyncWebServerRequest *request) {
      content = style_css();
      content += "<!DOCTYPE HTML>\r\n<html>";
      content += program_html();
      request->send(200, "text/html", content);
    });
    // Settings summer scenario temperatures HTML page
    server.on("/summer_scenario", [] (AsyncWebServerRequest *request) {
      content = style_css();
      content += "<!DOCTYPE HTML>\r\n<html>";
      content += summer_scenario_html();
      request->send(200, "text/html", content);
    });

    // Save settings from HTML page
    server.on("/setprogram", [] (AsyncWebServerRequest *request) {
      if(!request->authenticate(http_username, http_password))
        return request->requestAuthentication();
      // HERE SAVE SETTINGS TO EEPROM
      if(request->args() != 0) {
        
        // PROGRAM DATES
        program.summer.beginDD = request->arg("summerbeginDD").toInt();
        program.summer.beginMM = request->arg("summerbeginMM").toInt();
        program.winter.beginDD = request->arg("winterbeginDD").toInt();
        program.winter.beginMM = request->arg("winterbeginMM").toInt();

        // DAY/NIGHT BEGIN TIMES
        program.summer.day.beginH = request->arg("summer_day_beginH").toInt();
        program.summer.day.beginM = request->arg("summer_day_beginM").toInt();
        program.summer.night.beginH = request->arg("summer_night_beginH").toInt();
        program.summer.night.beginM = request->arg("summer_night_beginM").toInt();

        program.winter.day.beginH = request->arg("winter_day_beginH").toInt();
        program.winter.day.beginM = request->arg("winter_day_beginM").toInt();
        program.winter.night.beginH = request->arg("winter_night_beginH").toInt();
        program.winter.night.beginM = request->arg("winter_night_beginM").toInt();

        // SUMMER DAY SETTINGS
        program.summer.day.temp1.min = request->arg("summer_day_temp1min").toInt();
        program.summer.day.temp1.max = request->arg("summer_day_temp1max").toInt();

        program.summer.day.temp2.min = request->arg("summer_day_temp2min").toInt();
        program.summer.day.temp2.max = request->arg("summer_day_temp2max").toInt();

        program.summer.day.temp3.min = request->arg("summer_day_temp3min").toInt();
        program.summer.day.temp3.max = request->arg("summer_day_temp3max").toInt();
        
        program.summer.day.humidity1.min = request->arg("summer_day_humidity1min").toInt();
        program.summer.day.humidity1.max = request->arg("summer_day_humidity1max").toInt();

        // SUMMER NIGHT SETTINGS
        program.summer.night.temp1.min = request->arg("summer_night_temp1min").toInt();
        program.summer.night.temp1.max = request->arg("summer_night_temp1max").toInt();
        program.summer.night.temp2.min = request->arg("summer_night_temp2min").toInt();
        program.summer.night.temp2.max = request->arg("summer_night_temp2max").toInt();
        program.summer.night.temp3.min = request->arg("summer_night_temp3min").toInt();
        program.summer.night.temp3.max = request->arg("summer_night_temp3max").toInt();
        program.summer.night.humidity1.min = request->arg("summer_night_humidity1min").toInt();
        program.summer.night.humidity1.max = request->arg("summer_night_humidity1max").toInt();
        // WINTER DAY SETTINGS
        program.winter.day.temp1.min = request->arg("winter_day_temp1min").toInt();
        program.winter.day.temp1.max = request->arg("winter_day_temp1max").toInt();
        program.winter.day.temp2.min = request->arg("winter_day_temp2min").toInt();
        program.winter.day.temp2.max = request->arg("winter_day_temp2max").toInt();
        program.winter.day.temp3.min = request->arg("winter_day_temp3min").toInt();
        program.winter.day.temp3.max = request->arg("winter_day_temp3max").toInt();
        program.winter.day.humidity1.min = request->arg("winter_day_humidity1min").toInt();
        program.winter.day.humidity1.max = request->arg("winter_day_humidity1max").toInt();
        // WINTER NIGHT SETTINGS    
        program.winter.night.temp1.min = request->arg("winter_night_temp1min").toInt();
        program.winter.night.temp1.max = request->arg("winter_night_temp1max").toInt();
        program.winter.night.temp2.min = request->arg("winter_night_temp2min").toInt();
        program.winter.night.temp2.max = request->arg("winter_night_temp2max").toInt();
        program.winter.night.temp3.min = request->arg("winter_night_temp3min").toInt();
        program.winter.night.temp3.max = request->arg("winter_night_temp3max").toInt();
        program.winter.night.humidity1.min = request->arg("winter_night_humidity1min").toInt();
        program.winter.night.humidity1.max = request->arg("winter_night_humidity1max").toInt();
        
        EEPROM.put(1024, program);
        EEPROM.commit();
        
        Serial.println("Settings to save:");
        Serial.println("Summer begin: " + String(program.summer.beginDD) + "/" + String(program.summer.beginMM));
        Serial.println("Winter begin: " + String(program.winter.beginDD) + "/" + String(program.winter.beginMM));
        Serial.println("Day begin: " + String(program.summer.day.beginH) + "h" + String(program.summer.day.beginM));
      }
      request->send(200, "text/plain", "Settings saved!");
    });
  }

   // ESP Settings HTML page
    server.on("/settings", [] (AsyncWebServerRequest *request) {
      content = style_css();
      content += settings_html();
      request->send(200, "text/html", content);
    });

     server.on("/restartesp", [] (AsyncWebServerRequest *request) {
      ESP.restart();
      request->send(200, "text/html", content);
    });
}
