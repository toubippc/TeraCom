#include "html/settings_html.h"
#include "automation.h"

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
    
    content += "<script>";
    content += "</script>";
    content += "</head>";

    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/'\" value='&#8617;' />";
    content += "<h1> Settings</h1>";
    content += "</div>";

    content += "<h1> Seasons shedules ( summer/winter )</h1>";
    content += "<form method='get' action='setsheddule' style='width: 100%; padding:5px;'>";
    content += "<ul><label for='summerbegin'><h3>Summer begin (DDMM) :</h3></label>";
    content += "<input type='number' id='summerbeginDD' name='summerbeginDD' value='01' class='inputInt'>";
    content += " / <input type='number' id='summerbeginMM' name='summerbeginMM' value='03' class='inputInt'>";
    
    content += "<li><fieldset><legend>Day/Night Time</legend>";
    content += "<p><label for='daybegin'>Day Time (HH : MM) : </label><input type='number' id='daybeginH' name='daybeginH' value='08' class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value='00' class='inputInt'></p>";
    content += "<p><label for='nightbegin'>Night Time (HH : MM) : </label><input type='number' id='nightbeginH' name='nightbeginH' value='20' class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value='00' class='inputInt'></p>";
    content += "</fieldset></li>";
    
    content += "<li><fieldset><legend>Summer température : </legend>";
    
    content += "<p><label for='temp1min'>Température minimale "+ NameSensors1 +": </label><input type='number' id='temp1min' name='temp1min' value='" +String(temp1.min)+ "' class='inputText'></p>";
    content += "<p><label for='temp1max'>Température maximale "+ NameSensors1 +": </label><input type='number' id='temp1max' name='temp1max' value='" +String(temp1.max)+ "' class='inputText'></p>";

    content += "<p><label for='temp2min'>Température minimale "+ NameSensors2 +": </label><input type='number' id='temp2min' name='temp2min' value='" +String(temp2.min)+ "' class='inputText'></p>";
    content += "<p><label for='temp2max'>Température maximale "+ NameSensors2 +": </label><input type='number' id='temp2max' name='temp2max' value='" +String(temp2.max)+ "' class='inputText'></p>";

    content += "<p><label for='temp3min'>Température minimale "+ NameSensors3 +": </label><input type='number' id='temp3min' name='temp3min' value='" +String(temp3.min)+ "' class='inputText'></p>";
    content += "<p><label for='temp3max'>Température maximale "+ NameSensors3 +": </label><input type='number' id='temp3max' name='temp3max' value='" +String(temp3.max)+ "' class='inputText'></p>";

    content += "<p><label for='humidity1min'>Humidité minimale : </label><input type='number' id='humidity1min' name='humidity1min' value='" +String(humidity1min)+ "' class='inputText'></p>";
    content += "<p><label for='humidity1max'>Humidité maximale : </label><input type='number' id='humidity1max' name='humidity1max' value='" +String(humidity1max)+ "' class='inputText'></p>";
    content += "</fieldset></li>";
    
    content += "</ul>";


    content += "<ul><h3><label for='winterbegin'>Winter begin (DDMM) : </label></h3>";
    content += "<input type='number' id='winterbeginDD' name='winterbeginDD' value='01' class='inputInt'>";
    content += " / <input type='number' id='winterbeginMM' name='winterbeginMM' value='11' class='inputInt'>";
    
    content += "<li><fieldset><legend>Day/Night Time</legend>";
    content += "<p><label for='daybegin'>Day Time (HH : MM) : </label><input type='number' id='daybeginH' name='daybeginH' value='08' class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value='00' class='inputInt'></p>";
    content += "<p><label for='nightbegin'>Night Time (HH : MM) : </label><input type='number' id='nightbeginH' name='nightbeginH' value='20' class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value='00' class='inputInt'></p>";
    content += "</fieldset></li>";

    content += "<li><fieldset><legend>Winter température : </legend>";
    
    content += "<p><label for='temp1min'>Température minimale "+ NameSensors1 +": </label><input type='number' id='temp1min' name='temp1min' value='" +String(temp1.min)+ "' class='inputText'></p>";
    content += "<p><label for='temp1max'>Température maximale "+ NameSensors1 +": </label><input type='number' id='temp1max' name='temp1max' value='" +String(temp1.max)+ "' class='inputText'></p>";

    content += "<p><label for='temp2min'>Température minimale "+ NameSensors2 +": </label><input type='number' id='temp2min' name='temp2min' value='" +String(temp2.min)+ "' class='inputText'></p>";
    content += "<p><label for='temp2max'>Température maximale "+ NameSensors2 +": </label><input type='number' id='temp2max' name='temp2max' value='" +String(temp2.max)+ "' class='inputText'></p>";

    content += "<p><label for='temp3min'>Température minimale "+ NameSensors3 +": </label><input type='number' id='temp3min' name='temp3min' value='" +String(temp3.min)+ "' class='inputText'></p>";
    content += "<p><label for='temp3max'>Température maximale "+ NameSensors3 +": </label><input type='number' id='temp3max' name='temp3max' value='" +String(temp3.max)+ "' class='inputText'></p>";

    content += "<p><label for='humidity1min'>Humidité minimale : </label><input type='number' id='humidity1min' name='humidity1min' value='" +String(humidity1min)+ "' class='inputText'></p>";
    content += "<p><label for='humidity1max'>Humidité maximale : </label><input type='number' id='humidity1max' name='humidity1max' value='" +String(humidity1max)+ "' class='inputText'></p>";
    content += "</fieldset></li>";
    
    content += "</ul>";
        
        
    
    content += "<input type='submit' name='settempSave' value='Save' />";
    content += "</form>";
    content += "</html>";

    return content;
}