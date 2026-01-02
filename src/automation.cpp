#include "automation.h"

int humidity1min = 0;
int humidity1max = 0;


Temp temp1, temp2, temp3, humidity1;
Program program;

std::map<String, int> timesRules;
std::map<String, int> deviceRules;

void automation(void) {
    
    EEPROM.get(1024, program);
    
    if(program.summer.day.temp1.min == 0 && program.summer.day.temp1.max == 0) {
        // Si pas de programme enregistré, on initialise des valeurs par défaut
        programDefaultValues();
    }

        
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

void programDefaultValues() {
    // Valeurs par défaut si pas de programme enregistré
    program.summer.beginDD = 01; // 1
    program.summer.beginMM = 04; // Avril
    program.summer.day.beginH = 8;
    program.summer.day.beginM = 0;
    program.summer.day.endH = 20;
    program.summer.day.endM = 0;
    
    program.summer.day.temp1.min = 28;
    program.summer.day.temp1.max = 34;
    program.summer.day.temp2.min = 24;
    program.summer.day.temp2.max = 28;
    program.summer.day.temp3.min = 20;
    program.summer.day.temp3.max = 26;
    program.summer.day.humidity1.min = 40;
    program.summer.day.humidity1.max = 60;
    
    program.summer.night.beginH = 20;
    program.summer.night.beginM = 0;    
    program.summer.night.temp1.min = 26;
    program.summer.night.temp1.max = 32;
    program.summer.night.temp2.min = 18;
    program.summer.night.temp2.max = 22;
    program.summer.night.temp3.min = 22;
    program.summer.night.temp3.max = 26;
    program.summer.night.humidity1.min = 40;
    program.summer.night.humidity1.max = 60;

    program.winter.beginDD = 21; // 1 Octobre
    program.winter.beginMM = 8;   // 28 Février
    program.winter.day.beginH = 8;
    program.winter.day.beginM = 0;  // 20h00
    program.winter.day.temp1.min = 24;
    program.winter.day.temp1.max = 30;
    program.winter.day.temp2.min = 20;
    program.winter.day.temp2.max = 24;
    program.winter.day.temp3.min = 18;
    program.winter.day.temp3.max = 22;
    program.winter.day.humidity1.min = 40;
    program.winter.day.humidity1.max = 60;
    
    program.winter.night.beginH = 20;
    program.winter.night.beginM = 0;
    program.winter.night.temp1.min = 22;
    program.winter.night.temp1.max = 28;
    program.winter.night.temp2.min = 16;
    program.winter.night.temp2.max = 20;
    program.winter.night.temp3.min = 20;
    program.winter.night.temp3.max = 24;
    program.winter.night.humidity1.min = 40;
    program.winter.night.humidity1.max = 60;
    
    
}