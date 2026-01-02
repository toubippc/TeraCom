#include "html/settings_html.h"

String settings_html(void) {
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

    content += "<h1> Seasons shedules ( summer/winter )</h1>";
    content += "<form method='get' action='setprogram' style='width: 100%; padding:5px;'>";
    content += "<ul><label for='summerbegin'><h3>Summer begin (DDMM) :</h3></label>";
    content += "<input type='number' id='summerbeginDD' name='summerbeginDD' value=" + String(program.summer.beginDD) + " class='inputInt'>";
    content += " / <input type='number' id='summerbeginMM' name='summerbeginMM' value=" + String(program.summer.beginMM) + " class='inputInt'>";
    
    content += "<li><fieldset><legend>Day/Night Time</legend>";
    content += "<p><label for='summerdaybegin'>Day Time (HH : MM) : </label><input type='number' id='summerdaybeginH' name='summer_day_beginH' value=" + String(program.summer.day.beginH) + " class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value=" + String(program.summer.day.beginM) + " class='inputInt'> <i class='small info'>(Light ON)</i> </p>";
    content += "<p><label for='summernightbegin'>Night Time (HH : MM) : </label><input type='number' id='summernightbeginH' name='summer_night_beginH' value=" + String(program.summer.day.endH) + " class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value=" + String(program.summer.day.endM) + " class='inputInt'> <i class='small info'>(Light OFF)</i> </p>";
    content += "</fieldset></li>";
    
    content += "<li><fieldset><legend>Summer day température : </legend>";

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

    content += "</ul>";


    content += "<ul><h3><label for='winterbegin'>Winter begin (DDMM) : </label></h3>";
    content += "<input type='number' id='winterbeginDD' name='winterbeginDD' value='" +String(program.winter.beginDD)+ "' class='inputInt'>";
    content += " / <input type='number' id='winterbeginMM' name='winterbeginMM' value='" +String(program.winter.beginMM)+ "' class='inputInt'>";
    
    content += "<li><fieldset><legend>Day/Night Time</legend>";
    content += "<p><label for='winterdaybegin'>Day Time (HH : MM) : </label><input type='number' id='winterdaybeginH' name='winter_day_beginH' value='" +String(program.winter.day.beginH)+ "' class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value='" +String(program.winter.day.beginM)+ "' class='inputInt'></p>";
    content += "<p><label for='winternightbegin'>Night Time (HH : MM) : </label><input type='number' id='winternightbeginH' name='winter_night_beginH' value='" +String(program.winter.night.beginH)+ "' class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value='" +String(program.winter.night.beginM)+ "' class='inputInt'></p>";
    content += "</fieldset></li>";

    content += "<li><fieldset><legend>Winter day température : </legend>";
    
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

    content += "</ul>";
        
        
    
    content += "<input type='submit' name='save' value='Save' />";
    content += "</form>";
    content += "</html>";

    return content;
}