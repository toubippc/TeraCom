#include "html/tweak_html.h"

String tweak_html(void) {
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
    
    content += "</style>";
    
    content += "<script>";
    /*
    content += "function updateSliderPWM(element) {";
    content += "var sliderValue = document.getElementById('pwmSlider').value;";
    content += "document.getElementById('textSliderValue').innerHTML = sliderValue;";
    content += "console.log(sliderValue);";
    content += "var xhr = new XMLHttpRequest();";
    content += "xhr.open('GET', '/slider?value='+sliderValue, true);";
    content += "xhr.send();";
    content += "}";
    */
    content += "function saveTweak(element) {";
    content += "var timeMotor1 = document.getElementById('timeMotor1').value;";
    content += "var nameMotor1 = document.getElementById('nameMotor1').value;";
    content += "document.getElementById('timeMotor1').innerHTML = timeMotor1;";
    content += "console.log(timeMotor1);";
    content += "console.log(nameMotor1);";
    content += "var xhr = new XMLHttpRequest();";
    content += "xhr.open('GET', '/tweak?timeMotor1='+timeMotor1+'&nameMotor1='+nameMotor1, true);";
    content += "xhr.send();";
    content += "}";
    content += "</script>";
    content += "</head>";

    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/'\" value='&#8617;' />";
    content += "<h1> Tweak</h1>";
    content += "</div>";
    content += "<form method='get' action='tweak'>";
    content += "<p><label for='relay0'>Name : </label><input type='text' id='relay0' name='relay0' value='" +NameRelay0+ "' class='inputText'></p>";
    content += "<p><label for='relay1'>Name : </label><input type='text' id='relay1' name='relay1' value='" +NameRelay1+ "' class='inputText'></p>";
    content += "<p><label for='relay2'>Name : </label><input type='text' id='relay2' name='relay2' value='" +NameRelay2+ "' class='inputText'></p>";
    content += "<p><label for='relay3'>Name : </label><input type='text' id='relay3' name='relay3' value='" +NameRelay3+ "' class='inputText'></p>";

    content += "<fieldset><legend>Name sondes</legend>";
    content += "<p><label for='NameSensors1'>Name : </label><input type='text' id='NameSensors1' name='NameSensors1' value='" +NameSensors1+ "' class='inputText'></p>";
    content += "<p><label for='NameSensors2'>Name : </label><input type='text' id='NameSensors2' name='NameSensors2' value='" +NameSensors2+ "' class='inputText'></p>";
    content += "<p><label for='NameSensors3'>Name : </label><input type='text' id='NameSensors3' name='NameSensors3' value='" +NameSensors3+ "' class='inputText'></p>";
    content += "<p><label for='NameSensors4'>Name : </label><input type='text' id='NameSensors4' name='NameSensors4' value='" +NameSensors4+ "' class='inputText'></p>";
    content += "</fieldset>";
    content += "<input type='submit' onclick='saveTweak(this)' name='tweakSave' value='Save' />";
    content += "</form>";
    content += "</html>";

    return content;
}