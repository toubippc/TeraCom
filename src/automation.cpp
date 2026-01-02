#include "automation.h"

int humidity1min = 0;
int humidity1max = 0;


Temp temp1, temp2, temp3, humidity1;
Program program;

std::map<String, int> timesRules;
std::map<String, int> deviceRules;

void automation(void) {
    
    // Zone chaude
    temp1.min = 33;
    temp1.max = 35;
    program.summer.day.temp1 = temp1;

    // Zone froide
    temp2.min = 24;
    temp2.max = 26;
    program.summer.day.temp2 = temp2;

    // Zone tempérée
    temp3.min = 28;
    temp3.max = 30;
    program.summer.day.temp3 = temp3;

    // Humidité
    humidity1.min = 25;
    humidity1.max = 75;
    program.summer.day.humidity1 = humidity1;
        
    // Sondes
    /*
    dht.humidity().getEvent(&event);
    analog4Value = event.relative_humidity;
    dht.temperature().getEvent(&event);
    analog3Value = event.temperature;
    */
   
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
                 digitalWrite(pinRelay0, (analog3Value >= 33 ) ? ON : OFF); // Ventilation ON
            
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