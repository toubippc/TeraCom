#include <HTTPClient.h>
#include <WebServer.h>
#include "server.h"
#include "html/style.h"
#include "html/index_html.h"
#include "html/network_html.h"
#include "html/tweak_html.h"
// #include "dc_motors/move.h"

// DEVAULT VALUE
String stateout1 = "OFF";
String stateout2 = "OFF";
String stateout3 = "OFF";
String analog1 = "0";
String analog2 = "0";
String analog3 = "0";
String analog4 = "0";
String content;
int statusCode;


// Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  if (var == "SLIDERVALUE"){
    return sliderValue;
  } else {
    sliderValue = 128;
  }

  if(var == "NAMEMOTOR1") {
    return NameMotor1;
  }

  if(var == "PORTESTATE") {
    if(porteState == "Ouvert") {
      porteState = "Fermer";
    }
    else {
      porteState = "Ouvert";
    }
    return porteState;
  }

  if(var == "STATEOUT1") {
    if(stateout1 == "OFF") {
      stateout1 = "ON";
    }
    else {
      stateout1 = "OFF";
    }
    return stateout1;
  }

   if(var == "STATEOUT2") {
    if(stateout2 == "OFF") {
      stateout2 = "ON";
    }
    else {
      stateout2 = "OFF";
    }
    return stateout2;
  }

   if(var == "STATEOUT3") {
    if(stateout3 == "OFF") {
      stateout3 = "ON";
    }
    else {
      stateout3 = "OFF";
    }
    return stateout3;
  }
  /*
  if(var == "ANALOG1") {
    analog1 = String(analog1Value);
    return analog1;
  }
  if(var == "ANALOG2") {
    analog1 = String(analog2Value);
    return analog1;
  }
  */
  if(var == "ANALOG3") {
    analog1 = String(analog3Value);
    return analog1;
  }
  if(var == "ANALOG4") {
    analog1 = String(analog4Value);
    return analog1;
  }
  Serial.println(var);
  return String();
}

// Router URL AND GET PARAM
void createWebServer()
{
  {
   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
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
      porteState = inputMessage;
      // TODO : ON/OFF function here
     
      if (porteState == "Fermer"){
         digitalWrite(porteio, HIGH);
         digitalWrite(analogIn1, LOW);
         digitalWrite(analogIn2, HIGH);
         delay(timeMotor1);
      digitalWrite(analogIn1, LOW);
         digitalWrite(analogIn2, LOW);
         digitalWrite(porteio, LOW);
      } else {
          digitalWrite(porteio, HIGH);
          digitalWrite(analogIn2, LOW);
         digitalWrite(analogIn1, HIGH);
         delay(timeMotor1);
          digitalWrite(analogIn1, LOW);
         digitalWrite(analogIn2, LOW);
         digitalWrite(porteio, LOW);
        }
    }

    // GET WS_ROT PARAM
    // GET input1 value on <ESP_IP>?up=<inputMessage>
    // MOTOR move
    /*
    else if(request->hasParam(HTTP_GET_PARAM_ROT_UP)) {
      up(timeMotor1);
    }
    // GET input1 value on <ESP_IP>?down=<inputMessage>
    else if(request->hasParam(HTTP_GET_PARAM_ROT_DOWN)) {
      down(timeMotor1);
    }
    else if(request->hasParam(HTTP_GET_PARAM_ROT_RIGHT)) {
      right(timeMotor1);
    }
    else if(request->hasParam(HTTP_GET_PARAM_ROT_LEFT)) {
      left(timeMotor1);
    }
    */

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
        NameMotor1 = request->arg("nameMotor1");
        NameRelay1 = request->arg("relay1");
        NameRelay2 = request->arg("relay2");
        NameRelay3 = request->arg("relay3");
        // sliderValue = request->arg("sliderMotor1");
      }
      content = style_css();
      content += tweak_html();
      request->send(200, "text/html", content);
    });
  }
}
