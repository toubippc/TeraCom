#include "wifiSettings.h"

void scanWifi(void) {

  delay(100);
  int n = WiFi.scanNetworks();
  Serial.println("scan done");
  if (n == 0)
    Serial.println("no networks found");
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      //Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");
  st = "<ol>";
  for (int i = 0; i < n; ++i)
  {
    // Print SSID and RSSI for each network found
    st += "<li>";
    st += WiFi.SSID(i);
    st += " (";
    st += WiFi.RSSI(i);

    st += ")";
    //st += (WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*";
    st += "</li>";
  }
  st += "</ol>";
}

bool setupSTA(void) {
  // Initialize le mode Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  WiFi.begin(esid.c_str(), epass.c_str());
  // Wait connection ..
  int c = 0;
  //Serial.println("Waiting for Wifi to connect");
  while ( c < 30 ) {
    if (WiFi.status() == WL_CONNECTED)
    {
      digitalWrite(pinLedWifiAP, LOW);
      digitalWrite(pinLedWifiSTA, HIGH);
      Serial.print("RRSI: ");
      Serial.println(WiFi.RSSI());
      return true;
    }
    delay(1000);
    digitalWrite(pinLedWifiSTA, !digitalRead(pinLedWifiSTA));
    Serial.print("*");
    c++;
  }
  Serial.println("");
  Serial.println("Try to connection timed out !");
  digitalWrite(pinLedWifiSTA, LOW);
  digitalWrite(pinLedWifiAP, LOW);

  return false;
}

// Functions used for WiFi credentials saving and connecting to it which you do not need to change
bool testWifi(void)
{
  // Initialize le mode Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  WiFi.begin(esid.c_str(), epass.c_str());
  // Wait connection ..
  int c = 0;
  //Serial.println("Waiting for Wifi to connect");
  while ( c < 30 ) {
    if (WiFi.status() == WL_CONNECTED)
    {
      digitalWrite(pinLedWifiAP, LOW);
      digitalWrite(pinLedWifiSTA, HIGH);
      return true;
    }
    delay(1000);
    digitalWrite(pinLedWifiSTA, !digitalRead(pinLedWifiSTA));
    Serial.print("*");
    c++;
  }
  Serial.println("");
  Serial.println("Try to connection timed out, opening AP");
  digitalWrite(pinLedWifiSTA, LOW);
  digitalWrite(pinLedWifiAP, LOW);

  return false;
}

