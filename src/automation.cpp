#include "automation.h"


int relay1_timeOn = 0;
int relay1_timeOff = 0;

int relay2_timeOn = 0;
int relay2_timeOff = 0;

int relay3_timeOn = 0;
int relay3_timeOff = 0;

int relay4_timeOn = 0;
int relay4_timeOff = 0;

//int temp1min = [];
//int temp1max = [];

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
    
    // analog1Value : Zone chaude
    // analog2Value : Zone froide
    // analog3Value : Zone tempérée
    // analog4Value : Humidité
    
    // Si ECU est activé, on coupe tout en urgence et on sort de la fonction !!
    if (ECU_STATE == 1) {
        digitalWrite(pinRelay1, OFF); // Spot OFF
        digitalWrite(pinRelay2, OFF); // UV OFF
        digitalWrite(pinRelay3, OFF); // Chauffage OFF
        return; // Sort de la fonction
    }
    
    // Horraire JOUR
    if( 8 <= timeinfo.tm_hour && timeinfo.tm_hour  < 20) {
        
        // Controle Zone froide entre 24 et 28
        // Sécurité zone froide
        if(analog2Value >= 27) { 
            digitalWrite(pinRelay3, OFF); // Chauffage OFF
            digitalWrite(pinRelay2, OFF); // UV OFF
            digitalWrite(pinRelay1, OFF); // Spot OFF
            digitalWrite(pinRelay0, ON); // Ventilation ON
        }
        else {
            
            // Si la zone chaude est trop froide, on chauffe. Sinon on éteint le chauffage.
            if(analog1Value <= 33 ) { digitalWrite(pinRelay3, ON); } // Chauffage ON
            if(analog1Value >= 35 ) { digitalWrite(pinRelay3, OFF); } // Chauffage OFF
            
            // Controle Zone tempérée ( Ambiante )
                if (analog3Value >= 30 ) { digitalWrite(pinRelay2, OFF); } // UV OFF
                if (analog3Value <= 28 ) { digitalWrite(pinRelay2, ON); } // UV ON
                //if (analog3Value >= 35 ) { digitalWrite(pinRelay0, ON); }
                 analog3Value = (analog3Value >= 33 ) ? ON : OFF; // Ventilation ON
            
                // Controle des spots
                if (10 >= timeinfo.tm_hour && timeinfo.tm_hour <= 16) {
                    if (analog3Value <= 27 ) { digitalWrite(pinRelay1, ON); } // Spot ON
                    if (analog3Value >= 29 ) { digitalWrite(pinRelay1, OFF); } // Spot OFF
                }
                else {
                    // Ne pas descendre en dessous de 28, au point chaud, en journée
                    if (analog3Value <= 27 ) { digitalWrite(pinRelay1, ON); } // Spot ON
                    if (analog3Value >= 28 ) { digitalWrite(pinRelay1, OFF); } // Spot OFF
                }
        }

    }
    else { // Horraire NUIT ET SECURITER
        digitalWrite(pinRelay1, OFF); // Spot OFF
        digitalWrite(pinRelay2, OFF); // UV OFF
        // Chauffage Nuit
        if (analog1Value <= 23 ) { digitalWrite(pinRelay3, ON); } // Chauffage ON
        if (analog1Value >= 25 ) { digitalWrite(pinRelay3, OFF); } // Chauffage OFF
    } 
       
    // Serial.printf("Hour : %d \n", timeinfo.tm_hour);

}