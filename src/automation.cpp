#include "automation.h"


int relay1_timeOn = 0;
int relay1_timeOff = 0;

int relay2_timeOn = 0;
int relay2_timeOff = 0;

int relay3_timeOn = 0;
int relay3_timeOff = 0;

int relay4_timeOn = 0;
int relay4_timeOff = 0;

int temp1min = 0;
int temp1max = 0;

int temp2min = 0;
int temp2max = 0;

int temp3min = 0;
int temp3max = 0;

int humidity1min = 0;
int humidity1max = 0;

std::map<String, int> timesRules;
std::map<String, int> deviceRules;

void automation(void) {
    // Sondes
    dht.humidity().getEvent(&event);
    analog4Value = event.relative_humidity;
    dht.temperature().getEvent(&event);
    analog3Value = event.temperature;
    // Horraire JOUR
    if( 8 <= timeinfo.tm_hour && timeinfo.tm_hour  < 20) {
        
        if (analog3Value < 31 ) { digitalWrite(pinRelay3, HIGH); } // Chauffage ON
        if (analog3Value > 33 ) { digitalWrite(pinRelay3, LOW); } // Chauffage OFF
        
        if (analog3Value >= 29 ) { 
            digitalWrite(pinRelay2, LOW); // UV OFF
        } else {
             digitalWrite(pinRelay2, HIGH); // UV ON
        }
        
        
        if (10 <= timeinfo.tm_hour && timeinfo.tm_hour <= 16) {
            if (analog3Value <= 26 ) { digitalWrite(pinRelay1, HIGH); } // Spot ON
            if (analog3Value >= 28 ) { digitalWrite(pinRelay1, LOW); } // Spot OFF
        }
        else {
            // Ne pas descendre en dessous de 28, au point chaud, en journée
            if (analog3Value <= 25 ) { digitalWrite(pinRelay1, HIGH); } // Spot ON
            if (analog3Value >= 27 ) { digitalWrite(pinRelay1, LOW); } // Spot OFF
        }
        
    }
    else { // Horraire NUIT ET SECURITER
        digitalWrite(pinRelay1, LOW);
        digitalWrite(pinRelay2, LOW);
        // Chauffage Nuit
        if (analog3Value <= 22 ) { digitalWrite(pinRelay3, HIGH); } // Chauffage ON
        if (analog3Value >= 24 ) { digitalWrite(pinRelay3, LOW); } // Chauffage OFF
    } 
       
    Serial.printf("Hour : %d \n", timeinfo.tm_hour);

}