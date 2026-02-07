#include "automation.h"

int humidity1min = 0;
int humidity1max = 0;


Temp temp1, temp2, temp3, humidity1;
Program program;

int ChauffageState = ON;
int VentilationState = ON;
int SpotState = ON;
int UVState = ON;

std::map<String, int> timesRules;
std::map<String, int> deviceRules;

void automation(void) {
    
    EEPROM.get(264, program);
    
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
        digitalWrite(pinRelay0, OFF); // Ventilation ON
        digitalWrite(pinRelay1, OFF); // Spot OFF
        digitalWrite(pinRelay2, OFF); // UV OFF
        digitalWrite(pinRelay3, OFF); // Chauffage OFF
        return; // Sort de la fonction
    }
    
    
    // Détermination saison été/hiver
    Season season_mode;
    //season_mode = program.winter;
    
    if( (timeinfo.tm_mon + 1) > program.winter.beginMM || (timeinfo.tm_mon + 1) < program.summer.beginMM ) {
        season_mode = program.winter;
        Mode = "&#10054;";
    } else if( (timeinfo.tm_mon + 1) == program.winter.beginMM  && timeinfo.tm_mday >= program.winter.beginDD ) {
        season_mode = program.winter;
        Mode = "&#10054;";
    } else if( (timeinfo.tm_mon + 1) == program.summer.beginMM  && timeinfo.tm_mday < program.summer.beginDD ) {
        season_mode = program.winter;
        Mode = "&#10054;";
    }
    else {
        season_mode = program.summer;
        Mode = "&#127796;";
    }     
    
    // Horraire JOUR
    if( season_mode.day.beginH <= timeinfo.tm_hour && timeinfo.tm_hour  < season_mode.night.beginH) {
        Mode += " &#9788;";
        // Controle Zone froide entre 24 et 28
        // Sécurité zone froide
        if(analog2Value >= season_mode.day.temp2.max) { 
            ChauffageState = OFF; // Chauffage OFF
            SpotState = OFF; // Spot OFF
            UVState = OFF; // UV OFF
            VentilationState = ON; // Ventilation ON
                        
            /*
            digitalWrite(pinRelay3, OFF); // Chauffage OFF
            digitalWrite(pinRelay2, OFF); // UV OFF
            digitalWrite(pinRelay1, OFF); // Spot OFF
            digitalWrite(pinRelay0, ON); // Ventilation ON
            */
        }
        else {
            
            // Si la zone chaude est trop froide, on chauffe. Sinon on éteint le chauffage.
            if(analog1Value <= season_mode.day.temp1.min ) { ChauffageState = ON; } // Chauffage ON
            if(analog1Value >= season_mode.day.temp1.max ) { ChauffageState = OFF; } // Chauffage OFF

            // Controle Zone tempérée ( Ambiante )
                if (analog3Value >= season_mode.day.temp3.max ) { UVState = OFF; } // UV OFF
                if (analog3Value <= season_mode.day.temp3.min ) { UVState = ON; } // UV ON
                // Ventilation ON si plus grand que temp max
                 digitalWrite(pinRelay0, (analog3Value >= season_mode.day.temp3.max ) ? ON : OFF); 
            
                // Controle des spots
                // Heures + Controle température zone tempérée
                if (10 >= timeinfo.tm_hour && timeinfo.tm_hour <= 16) {
                    if (analog3Value <= season_mode.day.temp3.min ) { SpotState = ON; } // Spot ON
                    if (analog3Value >= season_mode.day.temp3.max ) { SpotState = OFF; } // Spot OFF
                }
                else {
                    // Ne pas descendre en dessous de 28, température ambiante, en journée si le chauffage ne suffit pas
                    if (analog1Value <= season_mode.day.temp1.min ) { SpotState = ON; } // Spot ON
                    if (analog1Value >= season_mode.day.temp1.min ) { SpotState = OFF; } // Spot OFF
                }
        }

    }
    else { // Horraire NUIT ET SECURITER
        Mode += "&#127769;";
        SpotState = OFF; // Spot OFF
        UVState = OFF; // UV OFF    
        VentilationState = OFF; // Ventilation OFF
        
        /*
        digitalWrite(pinRelay1, OFF); // Spot OFF
        digitalWrite(pinRelay2, OFF); // UV OFF
        digitalWrite(pinRelay0, OFF); // Ventilation OFF
        */
        // Chauffage Nuit
        if (analog1Value <= season_mode.night.temp1.min ) { ChauffageState = ON; } // Chauffage ON
        if (analog1Value >= season_mode.night.temp1.max ) { ChauffageState = OFF; } // Chauffage OFF
    } 
    
    // On écrit les états aux relais
    digitalWrite(pinRelay0, VentilationState); // Ventilation
    digitalWrite(pinRelay1, SpotState);  // Spot 
    digitalWrite(pinRelay2, UVState);  // UV
    digitalWrite(pinRelay3, ChauffageState);  // Chauffage
    
    // Serial.printf("Hour : %d \n", timeinfo.tm_hour);

}

void programDefaultValues() {
    // Valeurs par défaut si pas de programme enregistré
    program.summer.beginDD = 01; // 1
    program.summer.beginMM = 04; // Avril
    program.summer.day.beginH = 8;
    program.summer.day.beginM = 0;
    program.summer.night.beginH= 20;
    program.summer.night.beginM = 0;
    
    // Zone chaude
    program.summer.day.temp1.min = 28;
    program.summer.day.temp1.max = 34;
    // Zone froide
    program.summer.day.temp2.min = 24;
    program.summer.day.temp2.max = 28;
    // Zone tempérée
    program.summer.day.temp3.min = 20;
    program.summer.day.temp3.max = 26;
    // Humidité
    program.summer.day.humidity1.min = 40;
    program.summer.day.humidity1.max = 60;
      
    program.summer.night.temp1.min = 26;
    program.summer.night.temp1.max = 32;
    program.summer.night.temp2.min = 18;
    program.summer.night.temp2.max = 22;
    program.summer.night.temp3.min = 22;
    program.summer.night.temp3.max = 26;
    program.summer.night.humidity1.min = 40;
    program.summer.night.humidity1.max = 60;

    // Winter values
    program.winter.beginDD = 21; // 1 Octobre
    program.winter.beginMM = 8;   // 28 Février
    program.winter.day.beginH = 8;
    program.winter.day.beginM = 0;  // 20h00
    program.winter.night.beginH = 20;
    program.winter.night.beginM = 0;
    
    
    program.winter.day.temp1.min = 24;
    program.winter.day.temp1.max = 30;
    program.winter.day.temp2.min = 20;
    program.winter.day.temp2.max = 24;
    program.winter.day.temp3.min = 18;
    program.winter.day.temp3.max = 22;
    program.winter.day.humidity1.min = 40;
    program.winter.day.humidity1.max = 60;
    

    program.winter.night.temp1.min = 22;
    program.winter.night.temp1.max = 28;
    program.winter.night.temp2.min = 16;
    program.winter.night.temp2.max = 20;
    program.winter.night.temp3.min = 20;
    program.winter.night.temp3.max = 24;
    program.winter.night.humidity1.min = 40;
    program.winter.night.humidity1.max = 60;
    
    
}