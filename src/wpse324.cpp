#include "wpse324.h"

// Définition des pins
const int oneWireBus1 = 0;
const int oneWireBus2 = 4;

// Création des instances OneWire
OneWire oneWire1(oneWireBus1);
OneWire oneWire2(oneWireBus2);

// Création des instances Dallas Temperature
DallasTemperature sensors1(&oneWire1);
DallasTemperature sensors2(&oneWire2);

// Adresses des capteurs
DeviceAddress sensorAddress1, sensorAddress2;

void wpse324init() {
  Serial.begin(115200);
  
  // Configuration des pull-up internes
  pinMode(oneWireBus1, INPUT_PULLUP);
  pinMode(oneWireBus2, INPUT_PULLUP);
  
  // Initialisation des capteurs
  sensors1.begin();
  sensors2.begin();
  
  // Configuration de la résolution pour chaque capteur
  if(sensors1.getAddress(sensorAddress1, 0)) {
    sensors1.setResolution(sensorAddress1, 12);
    Serial.println("Capteur 1 initialisé");
  }
  
  if(sensors2.getAddress(sensorAddress2, 0)) {
    sensors2.setResolution(sensorAddress2, 12);
    Serial.println("Capteur 2 initialisé");
  }
}

void wpse324() {
  // Demande de lecture des températures
  sensors1.requestTemperatures();
  sensors2.requestTemperatures();
  
  // Lecture capteur 1
  float tempC1 = sensors1.getTempCByIndex(0);
  if(tempC1 != DEVICE_DISCONNECTED_C) {
    Serial.print("Température capteur 1 (Pin 0): ");
    Serial.print(tempC1);
    Serial.println(" °C");
    analog1Value = tempC1;
  }
  
  // Lecture capteur 2
  float tempC2 = sensors2.getTempCByIndex(0);
  if(tempC2 != DEVICE_DISCONNECTED_C) {
    Serial.print("Température capteur 2 (Pin 4): ");
    Serial.print(tempC2);
    Serial.println(" °C");
    analog2Value = tempC2;
  }
  
  Serial.println(); // Ligne vide pour séparer les lectures
  delay(1000);
}