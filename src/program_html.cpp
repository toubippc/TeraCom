#include "html/program_html.h"

String program_html(void) {
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<html>";
    content += "<head>";
    content += "<style>";
    content += ":root{--bg:#1a1a1e;--card:#242428;--text:#f5f5f5;--muted:#a0a0a8;--accent-orange:#ff8c00;--accent-yellow:#ffc107;--accent-red:#ff3333; --border-radius:8px;}";
    content += "body {background : var(--bg); max-width: 900px; margin: auto; padding-left: 5px; padding-right: 5px; padding-bottom: 25px; color: var(--text);}";
    content += "input {font-size: 1.3rem; margin : 10px; padding: 10px; background:#242428; color:#f5f5f5; border:1px solid #ff8c00;}";
    
    content += "div#bodyheader {";
    content += "display: flex;";
    content += "align-items: center;";
    content += "justify-content: space-between;";
    content += "gap: 12px;";
    content += "border-bottom: 2px solid var(--accent-orange);";
    content += "padding: 12px 6px 14px 6px;";
    content += "margin-bottom: 18px;";
    content += "}";
    
    content += "h2, h1 {";
    content += "font-size: 1.6rem;";
    content += "color: var(--accent-orange);";
    content += "margin: 0;";
    content += "}";

    content += "li {list-style-type: none; margin-bottom: 5px;}";
    
 
    content += ".returnButton {";
    content += "background: var(--accent-orange) !important;";
    content += "color: var(--text) !important;";
    content += "border: none;";
    content += "padding: 10px 15px;";
    content += "font-size: 1.3rem;";
    content += "cursor: pointer;";
    content += "border-radius: 5px;";
    content += "min-width: 100px;";
    content += "text-align: center;";
    content += "width: 50%%;";
    content += "}";


    // Inputs
    content += "input.inputText { width : 150px; }";
    content += "input.inputInt { width : 75px; }";

    content += ".input-group {";
    content += "margin-bottom: 20px;";
    content += "display: flex;";
    content += "justify-content: space-between;";
    content += "align-items: center;";
    content += "}";

    content += ".input-group label {";
    content += "font-size: 0.95rem;";
    content += "color: var(--text);";
    content += "}";

    content += ".inputs-row {";
    content += "display: flex;";
    content += "align-items: center;";
    content += "gap: 8px;";
    content += "}";

    content += "input[type=\"number\"], inputInt {";
    content += "background: transparent;";
    content += "border-style: unset;";
    content += "border-bottom: 1px solid var(--accent-orange);";
    //content += "border-radius: var(--border-radius);";
    content += "color: var(--accent-orange);";
    content += "background: var(--card);";
    content += "width: 75px;";
    content += "padding: 8px;";
    content += "text-align: center;";
    content += "font-size: 1rem;";
    content += "outline: none;";
    content += "}";

    // Buttons

    content += ".btn-primary {";
    content += "width: 90%;";
    content += "background: var(--accent-orange);";
    content += "border: none;";
    content += "padding: 15px;";
    content += "border-radius: var(--border-radius);";
    content += "color: black;";
    content += "font-weight: bold;";
    content += "font-size: 1rem;";
    content += "cursor: pointer;";
    content += "}";

    content += ".btn-secondary {";
    content += "width: 90%;";
    content += "background: transparent;";
    content += "border: 1px solid var(--accent-orange);";
    content += "color: var(--accent-orange);";
    content += "padding: 12px;";
    content += "border-radius: var(--border-radius);";
    content += "margin-top: 10px;";
    content += "cursor: pointer;";
    content += "transition: 0.2s;";
    content += "text-align: center;";
    content += "}";

    content += ".btn-secondary a {";
    content += "text-decoration: none;";
    content += "color: var(--accent-orange);";
    content += "font-size: 1.1rem;";
    content += "display: block;";
    content += "}";

    content += ".btn-secondary a:active::parent {";
    content += "background: var(--accent-orange);";
    content += "color: var(--text);";
    content += "}";

    content += ".icon {";
    content += "margin-right: 8px;";
    content += "color: var(--accent-orange);";
    content += "}";

    content += ".program-mode-toggle {";
    content += "display: flex;";
    content += "align-items: center;";
    content += "justify-content: center;";
    content += "gap: 10px;";
    content += "margin: 18px 0;";
    content += "color: var(--muted);";
    content += "}";

    content += ".program-mode-switch {";
    content += "position: relative;";
    content += "display: inline-block;";
    content += "flex-shrink: 0;";
    content += "width: 52px;";
    content += "height: 28px;";
    content += "}";

    content += ".program-mode-switch input {";
    content += "position: absolute;";
    content += "width: 0;";
    content += "height: 0;";
    content += "margin: 0;";
    content += "opacity: 0;";
    content += "}";

    content += ".program-mode-slider {";
    content += "position: absolute;";
    content += "inset: 0;";
    content += "cursor: pointer;";
    content += "background-color: #666;";
    content += "border-radius: 28px;";
    content += "transition: background-color 0.25s;";
    content += "}";

    content += ".program-mode-slider::before {";
    content += "position: absolute;";
    content += "content: \"\";";
    content += "width: 20px;";
    content += "height: 20px;";
    content += "left: 4px;";
    content += "bottom: 4px;";
    content += "background-color: #fff;";
    content += "border-radius: 50%;";
    content += "transition: transform 0.25s;";
    content += "}";

    content += ".program-mode-switch input:checked + .program-mode-slider {";
    content += "background-color: var(--accent-orange);";
    content += "}";

    content += ".program-mode-switch input:focus-visible + .program-mode-slider {";
    content += "outline: 2px solid var(--accent-yellow);";
    content += "outline-offset: 2px;";
    content += "}";

    content += ".program-mode-switch input:checked + .program-mode-slider::before {";
    content += "transform: translateX(24px);";
    content += "}";

    content += ".curve-section-title {";
    content += "margin-top: 28px;";
    content += "}";

    content += "</style>";


    content += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" >";
    content += "</head>";

    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/'\" value='&#8617;' />";
    content += "<h1> Program</h1>";

    content += "</div>";

    content += "<div class='program-mode-toggle'>";
    content += "<span>Saisonnier</span>";
    content += "<label class='program-mode-switch' aria-label='Programme saisonnier ou courbe'>";
    content += "<input id='programMode' type='checkbox' ";
    content += curveMode ? "checked " : "";
    content += "onchange=\"location.href='/program?curveMode='+(this.checked?1:0)\">";
    content += "<span class='program-mode-slider'></span>";
    content += "</label>";
    content += "<span>Courbe</span>";
    content += "</div>";
    
    content += curveMode ? curveProgramHtml() : seasonProgramHtml();
    content += "</html>";

    return content;
}

static void appendCurveField(String& content, const char* name, const char* label, float value, unsigned int decimals, const char* step) {
    content += "<div class='input-group'>";
    content += "<label for='";
    content += name;
    content += "'>";
    content += label;
    content += "</label><div class='inputs-row'>";
    content += "<input type='number' id='";
    content += name;
    content += "' name='";
    content += name;
    content += "' value='";
    content += String(value, decimals);
    content += "' step='";
    content += step;
    content += "' class='inputInt'>";
    content += "</div></div>";
}

String curveProgramHtml()
{
    String content = "<form style='width: 100%; padding:5px;'>";
    
    content += "<h2>Saison été</h2>";
    content += "<fieldset>";
    content += "Les valeurs sont incrémentées de leurs coefficient après la date/heure et décrementé a la date de fin. <br />";
    content += "Les heures de début de journée sont définies au départ et seront calculées, chaque jour, par la suite <br />";
    content += "Aidez vous du fichier excel pour calculer les coefficients et périodes afin d'obtenir les températures cible <br />";
    content += "</fieldset>";
    
    // Heure jour
    content += "Heure / Minute <input class='inputInt' name='curveStartHour' type='int' min='0' max='23' step='1' >/";
    content += "<input class='inputInt' name='curveStartMinute' type='int' min='0' max='59' step='1' ><br />";
    // Date
    content += "Eté Jour / Mois <input class='inputInt' name='curveStartDay' type='int' min='1' max='31' step='1' >/";
    content += "<input class='inputInt' name='curveStartMonth' type='int' min='1' max='12' step='1' ><br />";
    content += "Hiver Jour / Mois <input class='inputInt' name='curveEndDay' type='int' min='1' max='31' step='1' >/";
    content += "<input class='inputInt' name='curveEndMonth' type='int' min='1' max='12' step='1' ><br />";
    
    content += "<h2>Paramètres de la courbe</h2>";
    content += "<h3 class='season-label curve-section-title'>COEFFICIENTS</h3>";

    appendCurveField(content, "coefficientHotPointDay", "Température point chaud sol (jour)", curveProgram.coefficients.hotPointDay, 2, "0.01");
    appendCurveField(content, "coefficientHotPointNight", "Température point chaud sol (nuit)", curveProgram.coefficients.hotPointNight, 2, "0.01");
    appendCurveField(content, "coefficientColdPointDay", "Température point froid sol (jour)", curveProgram.coefficients.coldPointDay, 2, "0.01");
    appendCurveField(content, "coefficientColdPointNight", "Température point froid sol (nuit)", curveProgram.coefficients.coldPointNight, 2, "0.01");
    appendCurveField(content, "coefficientAmbientAirDay", "Température air ambiant (jour)", curveProgram.coefficients.ambientAirDay, 2, "0.01");
    appendCurveField(content, "coefficientAmbientAirNight", "Température air ambiant (nuit)", curveProgram.coefficients.ambientAirNight, 2, "0.01");
    appendCurveField(content, "secondsPerDay", "Pas de calcul (secondes par jour)", curveProgram.coefficients.secondsPerDay, 0, "1");

    content += "<h3 class='season-label curve-section-title'>VALEURS DE DÉPART</h3>";
    appendCurveField(content, "startDay", "Jour de départ", curveProgram.start.day, 0, "1");
    appendCurveField(content, "startHotPointDay", "Température point chaud sol (jour, &deg;C)", curveProgram.start.hotPointDay, 1, "0.1");
    appendCurveField(content, "startHotPointNight", "Température point chaud sol (nuit, &deg;C)", curveProgram.start.hotPointNight, 1, "0.1");
    appendCurveField(content, "startColdPointDay", "Température point froid sol (jour, &deg;C)", curveProgram.start.coldPointDay, 1, "0.1");
    appendCurveField(content, "startColdPointNight", "Température point froid sol (nuit, &deg;C)", curveProgram.start.coldPointNight, 1, "0.1");
    appendCurveField(content, "startAmbientAirDay", "Température air ambiant (jour, &deg;C)", curveProgram.start.ambientAirDay, 1, "0.1");
    appendCurveField(content, "startAmbientAirNight", "Température air ambiant (nuit, &deg;C)", curveProgram.start.ambientAirNight, 1, "0.1");
    appendCurveField(content, "startPhotoperiodHours", "Photopériode (heures)", curveProgram.start.photoperiodHours, 1, "0.1");

    content += "</>";
    return content;
}


String seasonProgramHtml()
{
    String content = "<form method='get' action='setprogram' style='width: 100%; padding:5px;'>";

    content += "<h2> Seasons shedules ( summer/winter )</h2>";
    content += "<section class='season-section'>";

        content += "<h3 class='season-label'>SUMMER</h3>";

        content += "<div class='input-group'>";
            content += "<label for='summerbegin'>Summer begin (DDMM) :</label>";
            content += "<div class='inputs-row'>";
                content += "<input type='number' id='summerbeginDD' name='summerbeginDD' value=" + String(program.summer.beginDD) + " class='inputInt'>";
                content += " / <input type='number' id='summerbeginMM' name='summerbeginMM' value=" + String(program.summer.beginMM) + " class='inputInt'>";
            content += "</div>";
        content += "</div>";

        content += "<div class='input-group'>";
            content += "<p><label for='summerdaybegin'><span class='icon'>&#9728;</span> Day Time <i class='small info'>(Light ON)</i> : </label>";
            content += "<div class='inputs-row'>";
                content += "<input type='number' id='summerdaybeginH' name='summer_day_beginH' value=" + String(program.summer.day.beginH) + " class='inputInt'> : <input type='number' id='daybeginM' name='summer_day_beginM' value=" + String(program.summer.day.beginM) + " class='inputInt'>  </p>";
            content += "</div>";
        content += "</div>";

        content += "<div class='input-group'>";
            content += "<p><label for='summernightbegin'><span class='icon'>&#127769;</span> Night Time <i class='small info'>(Light OFF)</i> : </label>";
            content += "<div class='inputs-row'>";
                content += "<input type='number' id='summernightbeginH' name='summer_night_beginH' value=" + String(program.summer.night.beginH) + " class='inputInt'> : <input type='number' id='nightbeginM' name='summer_night_beginM' value=" + String(program.summer.night.beginM) + " class='inputInt'>  </p>";
            content += "</div>";
        content += "</div>";

        content += "<p  id='setSummerTemp' class='btn-secondary'><a href='/summer_scenario'>Set Summer température</a></p>";
    content += "</section>";


    content += "<section class='season-section'>";

        content += "<h3 class='season-label'>WINTER</h3>";

            content += "<div class='input-group'>";
                content += "<label for='winterbegin'>Winter begin (DDMM) :</label>";
                content += "<div class='inputs-row'>";
                    content += "<input type='number' id='winterbeginDD' name='winterbeginDD' value='" +String(program.winter.beginDD)+ "' class='inputInt'>";
                    content += " / <input type='number' id='winterbeginMM' name='winterbeginMM' value='" +String(program.winter.beginMM)+ "' class='inputInt'>";
                content += "</div>";
            content += "</div>";

            content += "<div class='input-group'>";
                content += "<p><label for='winterdaybegin'><span class='icon'>&#9728;</span> Day Time (HH : MM) : </label>";
                content += "<div class='inputs-row'>";
                    content += "<input type='number' id='winterdaybeginH' name='winter_day_beginH' value='" +String(program.winter.day.beginH)+ "' class='inputInt'> : <input type='number' id='winterdaybeginM' name='winter_day_beginM' value='" +String(program.winter.day.beginM)+ "' class='inputInt'></p>";
                content += "</div>";
            content += "</div>";
        

            content += "<div class='input-group'>";
                content += "<p><label for='winternightbegin'><span class='icon'>&#127769;</span> Night Time (HH : MM) : </label>";
                content += "<div class='inputs-row'>";
                    content += "<input type='number' id='winternightbeginH' name='winter_night_beginH' value='" +String(program.winter.night.beginH)+ "' class='inputInt'> : <input type='number' id='winternightbeginM' name='winter_night_beginM' value='" +String(program.winter.night.beginM)+ "' class='inputInt'></p>";
                content += "</div>";
            content += "</div>";

            content += "<p id='setWinterTemp' class='btn-secondary'><a href='/winter_scenario'>Set Winter température : </a></p>";

        content += "</div>";

    content += "</section>";

    content += "<input class='btn-primary' type='submit' name='save' value='Save' />";
    content += "</form>";
    
    return content;
}