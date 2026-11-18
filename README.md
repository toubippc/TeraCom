# Firware Léomatic esp32

Version beta : 3.1

## Description

Ce firware charger sur un esp32 permet le controle de températures, de l'éclairage et de la circulation d'air dans un terrarium.

Via un pin/switch on peu le passer en mode station ( hotspot ),de facon a se connecter directement a l'appareil ( il emet son propre signal wifi/ssid ) ou en mode client, en le connectant a son réseaux existant.
Vou devez pour se faire l'initialisé en vous connectant une première fois en mode station.

## Modes de fonctionnement

### Manuel et automatique

- En mode **manuel**, l'automation est suspendue et les sorties relais peuvent être commandées depuis l'interface.
- En mode **automatique**, le programme est relu depuis l'EEPROM et les sorties sont pilotées selon le mode de programmation choisi.

### Programme saisonnier

Le programme sélectionne les consignes été/hiver selon les dates configurées, puis applique des seuils de température distincts le jour et la nuit. Le chauffage, le spot, les UV et la ventilation sont commandés selon ces seuils et l'heure. La température et l'humidité du DHT11 sont affichées, mais l'humidité n'est pas encore utilisée par l'automation.

### Déclenchement des relais en mode saisonnier

En journée, le chauffage s'allume lorsque la température de la zone chaude atteint ou passe sous son seuil minimum, et s'éteint à son seuil maximum. Les UV suivent les seuils minimum/maximum de la température ambiante. La ventilation s'allume à partir du maximum ambiant et s'éteint en dessous.

Le spot chauffant suit les seuils ambiants jusqu'à 10 h inclus, puis ceux de la zone chaude. La condition horaire actuelle ne couvre donc pas la plage 10 h–16 h suggérée par le commentaire du code. La nuit, spot, UV et ventilation sont éteints; seul le chauffage suit les seuils nuit de la zone chaude. Pour le chauffage, les UV et le spot, entre les seuils minimum et maximum, l'état précédent est conservé.

Les horaires jour/nuit sont comparés à l'heure entière; les minutes configurées ne sont pas prises en compte par l'automation. L'humidité est affichée, mais n'intervient pas dans ces commandes.

### Programme par courbe

Le mode est sélectionnable dans l'interface, mais son traitement dans l'automation n'est pas encore implémenté : il ne pilote donc pas actuellement les relais.

Dans ce mode, aucun nouvel état de relais n'est calculé à partir de la courbe; les derniers états mémorisés sont néanmoins réécrits sur les sorties.

### Sécurités et limites actuelles

- L'état **ECU** est vérifié au début de l'automation et force les quatre sorties à `OFF`. Cette vérification n'est exécutée qu'en mode automatique; les commandes manuelles des relais ne passent pas par cette sécurité.
- La protection de zone froide est censée se déclencher lorsque la température mesurée atteint ou dépasse le maximum de zone froide de jour : elle coupe chauffage, spot et UV, active la ventilation, écrit les relais puis quitte l'automation. Toutefois, le code lit encore ce seuil avant d'initialiser `season_mode`; cette protection n'est donc pas fiable actuellement.

### 4 sorties relay

- Chauffage / Tapis de sol
- Lumière chauffante ( spot / céramique )
- Lumière spéciale ( UVB )
- Ventilation / climatisation

### Sondes d'entrées

- 1 DHT 11 (température / Humidité )
- 2 Sondes de témperatures DS18B20

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