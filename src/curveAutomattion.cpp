//include
#include "curveAutomation.h"
using namespace curve;

// TODO: Revoir l'interface des courbes :
// - Mode normal : l'utilisateur choisit la température cible et la durée;
//   le coefficient est calculé automatiquement.
// - Mode avancé : si le coefficient est modifié, garder la cible fixe et
//   recalculer/afficher la durée nécessaire.
// La température cible reste prioritaire et ne change jamais silencieusement.

// Les parametres de base sont défini par : CurveProgram curveProgram

// Les préférences utilisateur sont enregistrés dans : EEPROM.get(264, curve);
// CurveProgram curve;
//EEPROM.get(264, curve);

// Les valeurs données par défaut, sont les valeurs maximum des parametre d'été
// Elles décroit de leurs coefficients au début de la fin d'été, début hiver ( Automne )

    void curvePeriod::seasonCurve(void) {
        if( (timeinfo.tm_mon + 1) > curveDate.summerEnd.endSummerMonth || (timeinfo.tm_mon + 1) < curveDate.summerBegin.beginSummerMonth ) {
                curvePeriod::season = 1;
                ModeIcon = "&#10054;";
            } else if( (timeinfo.tm_mon + 1) == curveDate.summerEnd.endSummerMonth  && timeinfo.tm_mday >= curveDate.summerEnd.endSummerDay ) {
                curvePeriod::season = season = 1;;
                ModeIcon = "&#10054;";
            } else if( (timeinfo.tm_mon + 1) == curveDate.summerBegin.beginSummerMonth  && timeinfo.tm_mday < curveDate.summerBegin.beginSummerDay ) {
                curvePeriod::season = 1;
                ModeIcon = "&#10054;";
            }
            else {
                curvePeriod::season = 0;
                ModeIcon = "&#127796;";
            }     
    }

    // Calcul du nombre de jour d'été
    int curvePeriod::summerDays(void) {
        
    }
    // Calcul du nombre de jour d'hiver
    int curvePeriod::winterDays(void) {
        
    }
    // Calcul des nouvelles valeurs selon le nombre de jours et le coefficient
    void curvePeriod::curveValues(void) {
        
    }
