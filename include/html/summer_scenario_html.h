String summer_scenario_html(void);

String summer_scenario_html(void) {
    
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<html>";
    content += "<head>";
    content += "<style>";
    content += "div#bodyheader { display: grid; grid-template-columns: 1fr 4fr; background : lavender; }";
    content += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    content += "input.inputText { width : 150px; }";
    content += "input.inputInt { width : 75px; }";
    content += "</style>";
    content += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" >";
    content += "<script>";
    content += "</script>";
    content += "</head>";

    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/'\" value='&#8617;' />";
    content += "<h1> Settings</h1>";
    content += "</div>";

    content += "<li><fieldset><legend><a href='#?summer_scenario'>Summer day température : </a></legend>";

    content += "<p><label for='summer_day_temp1min'>Température minimale "+ NameSensors1 +": </label><input type='number' id='summer_day_temp1min' name='summer_day_temp1min' value='" +String(program.summer.day.temp1.min)+ "' class='inputText'> <i class='small info'>(Heater ON) </i> </p>";
    content += "<p><label for='summer_day_temp1max'>Température maximale "+ NameSensors1 +": </label><input type='number' id='summer_day_temp1max' name='summer_day_temp1max' value='" +String(program.summer.day.temp1.max)+ "' class='inputText'> <i class='small info'>(Heater OFF) </i> </p>";

    content += "<p><label for='summer_day_temp2min'>Température minimale "+ NameSensors2 +": </label><input type='number' id='summer_day_temp2min' name='summer_day_temp2min' value='" +String(program.summer.day.temp2.min)+ "' class='inputText'> <i class='small info'>(Heater ON) </i> </p>";
    content += "<p><label for='summer_day_temp2max'>Température maximale "+ NameSensors2 +": </label><input type='number' id='summer_day_temp2max' name='summer_day_temp2max' value='" +String(program.summer.day.temp2.max)+ "' class='inputText'><i class='small info'>(All's OFF ) </i> </p>";
    content += "<p><label for='summer_day_temp3min'>Température minimale "+ NameSensors3 +": </label><input type='number' id='summer_day_temp3min' name='summer_day_temp3min' value='" +String(program.summer.day.temp3.min)+ "' class='inputText'><i class='small info'>(Heater ON if no max ) </i></p>";
    content += "<p><label for='summer_day_temp3max'>Température maximale "+ NameSensors3 +": </label><input type='number' id='summer_day_temp3max' name='summer_day_temp3max' value='" +String(program.summer.day.temp3.max)+ "' class='inputText'><i class='small info'> (FAN ON ) </i></p>";

    content += "<p><label for='summer_day_humidity1min'>Humidité minimale : </label><input type='number' id='summer_day_humidity1min' name='summer_day_humidity1min' value='" +String(program.summer.day.humidity1.min)+ "' class='inputText'><i class='small info'>(FAN OFF) </i></p>";
    content += "<p><label for='summer_day_humidity1max'>Humidité maximale : </label><input type='number' id='summer_day_humidity1max' name='summer_day_humidity1max' value='" +String(program.summer.day.humidity1.max)+ "' class='inputText'><i class='small info'>(FAN ON ) </i></p>";
    content += "</fieldset></li>";
    
    content += "<li><fieldset><legend>Summer night température : </legend>";
    
    content += "<p><label for='summer_night_temp1min'>Température minimale "+ NameSensors1 +": </label><input type='number' id='summer_night_temp1min' name='summer_night_temp1min' value='" +String(program.summer.night.temp1.min)+ "' class='inputText'> <i class='small info'>(Heater ON) </i> </p>";
    content += "<p><label for='summer_night_temp1max'>Température maximale "+ NameSensors1 +": </label><input type='number' id='summer_night_temp1max' name='summer_night_temp1max' value='" +String(program.summer.night.temp1.max)+ "' class='inputText'> <i class='small info'>(Heater OFF) </i> </p>";

    content += "<p><label for='summer_night_temp2min'>Température minimale "+ NameSensors2 +": </label><input type='number' id='summer_night_temp2min' name='summer_night_temp2min' value='" +String(program.summer.night.temp2.min)+ "' class='inputText'> <i class='small info'>(Heater ON) </i> </p>";
    content += "<p><label for='summer_night_temp2max'>Température maximale "+ NameSensors2 +": </label><input type='number' id='summer_night_temp2max' name='summer_night_temp2max' value='" +String(program.summer.night.temp2.max)+ "' class='inputText'><i class='small info'>(All's OFF ) </i> </p>";
    content += "<p><label for='summer_night_temp3min'>Température minimale "+ NameSensors3 +": </label><input type='number' id='summer_night_temp3min' name='summer_night_temp3min' value='" +String(program.summer.night.temp3.min)+ "' class='inputText'><i class='small info'>(Heater ON if no max ) </i></p>";
    content += "<p><label for='summer_night_temp3max'>Température maximale "+ NameSensors3 +": </label><input type='number' id='summer_night_temp3max' name='summer_night_temp3max' value='" +String(program.summer.night.temp3.max)+ "' class='inputText'><i class='small info'> (FAN ON ) </i></p>";

    content += "<p><label for='summer_night_humidity1min'>Humidité minimale : </label><input type='number' id='summer_night_humidity1min' name='summer_night_humidity1min' value='" +String(program.summer.night.humidity1.min)+ "' class='inputText'><i class='small info'>(FAN OFF) </i></p>";
    content += "<p><label for='summer_night_humidity1max'>Humidité maximale : </label><input type='number' id='summer_night_humidity1max' name='summer_night_humidity1max' value='" +String(program.summer.night.humidity1.max)+ "' class='inputText'><i class='small info'>(FAN ON ) </i></p>";
    content += "</fieldset></li>";  

    return content;
}