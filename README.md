# Firware TeraCom esp32

Version beta : 0.2

## Description

Ce firware charger sur un esp32 permet le controle de températures, de l'éclairage et de la circulation d'air dans un terrarium.

Via un pin/switch on peu le passer en mode station ( hotspot ),de facon a se connecter directement a l'appareil ( il emet son propre signal wifi/ssid ) ou en mode client, en le connectant a son réseaux existant.
Vou devez pour se faire l'initialisé en vous connectant une première fois en mode station.

### 4 sorties relay
- Chauffage / Tapis de sol
- Lumière chauffante ( spot )
- Lumière spéciale ( UV )
- Ventilation / Humidificateur

### Sondes d'entrées
- DHT
- 

D'autre fonction avec de multiple sondes sont a venir ! 
(la liste est trop longue .. )

> [!IMPORTANT]
> Manuel d'utilisation a venir !

## Technique

### Hardware

- Carte : esp32doit-devkit-v1
- Shéma :
- Sondes compatibles :

### Software

Développé avec VSCode

platform = espressif32 \
board = esp32doit-devkit-v1 \
framework = arduino \
lib_deps = 
 - ottowinter/ESPAsyncWebServer-esphome@^3.1.0
 - ottowinter/ESPAsyncTCP-esphome@^1.2.3
 - adafruit/Adafruit Unified Sensor@^1.1.14
 - adafruit/DHT sensor library@^1.4.6
 - paulstoffregen/OneWire@^2.3.8
 - milesburton/DallasTemperature@^3.11.0
 - ayushsharma82/AsyncElegantOTA@^2.2.8