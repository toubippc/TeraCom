 String winter_scenario_html(void);

 String winter_scenario_html(void) {


    String content = "<!DOCTYPE HTML>\r\n";
    content += "<head>";
    content += "<style>";
    content += ":root{--bg:#1a1a1e;--card:#242428;--text:#f5f5f5;--muted:#a0a0a8;--accent-orange:#ff8c00;--accent-yellow:#ffc107;--accent-red:#ff3333}";
    content += "body {background : var(--bg); max-width: 900px; margin: auto; padding-left: 5px; padding-bottom: 25px; color: var(--text);}";
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
    content += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    content += "input.inputText { width : 150px; }";
    content += "input.inputInt { width : 75px; }";
    content += "</style>";
    content += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" >";
    content += "<script>";
    content += "</script>";
    content += "</head>";

    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/program'\" value='&#8617;' />";
    content += "<h1> Winter Scenario</h1>";
    content += "</div>";
    content += "<li><fieldset><legend>Winter day température :</legend>";
    
    content += "<p><label for='winter_day_temp1min'>Température minimale "+ NameSensors1 +": </label><input type='number' id='winter_day_temp1min' name='winter_day_temp1min' value='" +String(program.winter.day.temp1.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_day_temp1max'>Température maximale "+ NameSensors1 +": </label><input type='number' id='winter_day_temp1max' name='winter_day_temp1max' value='" +String(program.winter.day.temp1.max)+ "' class='inputText'></p>";

    content += "<p><label for='winter_day_temp2min'>Température minimale "+ NameSensors2 +": </label><input type='number' id='winter_day_temp2min' name='winter_day_temp2min' value='" +String(program.winter.day.temp2.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_day_temp2max'>Température maximale "+ NameSensors2 +": </label><input type='number' id='winter_day_temp2max' name='winter_day_temp2max' value='" +String(program.winter.day.temp2.max)+ "' class='inputText'></p>";
    content += "<p><label for='winter_day_temp3min'>Température minimale "+ NameSensors3 +": </label><input type='number' id='winter_day_temp3min' name='winter_day_temp3min' value='" +String(program.winter.day.temp3.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_day_temp3max'>Température maximale "+ NameSensors3 +": </label><input type='number' id='winter_day_temp3max' name='winter_day_temp3max' value='" +String(program.winter.day.temp3.max)+ "' class='inputText'></p>";

    content += "<p><label for='winter_day_humidity1min'>Humidité minimale : </label><input type='number' id='winter_day_humidity1min' name='winter_day_humidity1min' value='" +String(program.winter.day.humidity1.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_day_humidity1max'>Humidité maximale : </label><input type='number' id='winter_day_humidity1max' name='winter_day_humidity1max' value='" +String(program.winter.day.humidity1.max)+ "' class='inputText'></p>";
    
    content += "</fieldset></li>";
    
    content += "<li><fieldset><legend>Winter night température : </legend>";

    content += "<p><label for='winter_night_temp1min'>Température minimale "+ NameSensors1 +": </label><input type='number' id='winter_night_temp1min' name='winter_night_temp1min' value='" +String(program.winter.night.temp1.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_night_temp1max'>Température maximale "+ NameSensors1 +": </label><input type='number' id='winter_night_temp1max' name='winter_night_temp1max' value='" +String(program.winter.night.temp1.max)+ "' class='inputText'></p>";

    content += "<p><label for='winter_night_temp2min'>Température minimale "+ NameSensors2 +": </label><input type='number' id='winter_night_temp2min' name='winter_night_temp2min' value='" +String(program.winter.night.temp2.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_night_temp2max'>Température maximale "+ NameSensors2 +": </label><input type='number' id='winter_night_temp2max' name='winter_night_temp2max' value='" +String(program.winter.night.temp2.max)+ "' class='inputText'></p>";
    content += "<p><label for='winter_night_temp3min'>Température minimale "+ NameSensors3 +": </label><input type='number' id='winter_night_temp3min' name='winter_night_temp3min' value='" +String(program.winter.night.temp3.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_night_temp3max'>Température maximale "+ NameSensors3 +": </label><input type='number' id='winter_night_temp3max' name='winter_night_temp3max' value='" +String(program.winter.night.temp3.max)+ "' class='inputText'></p>";

    content += "<p><label for='winter_night_humidity1min'>Humidité minimale : </label><input type='number' id='winter_night_humidity1min' name='winter_night_humidity1min' value='" +String(program.winter.night.humidity1.min)+ "' class='inputText'></p>";
    content += "<p><label for='winter_night_humidity1max'>Humidité maximale : </label><input type='number' id='winter_night_humidity1max' name='winter_night_humidity1max' value='" +String(program.winter.night.humidity1.max)+ "' class='inputText'></p>";
    content += "</fieldset></li>";
    content += "</body></html>";

    return content;

 }