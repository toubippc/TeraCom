#include "html/tweak_html.h"

String tweak_html(void) {
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<html>";
    content += "<head>";
    content += "<style>";
    content += "p#sliderInput {display:none;}";
    content += "div#bodyheader { display: grid; grid-template-columns: 1fr 4fr; background : lavender; }";
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
    content += "<p><label for='nameMotor1'>Name : </label><input type='text' id='nameMotor1' name='nameMotor1' value='" +NameMotor1+ "' class='inputText'></p>";
    content += "<p id=\"sliderInput\"><label for='pwmSlider'>Power Motor 1 : </label><input type='range' onchange='updateSliderPWM(this)' id='pwmSlider' min='0' max='255' name='sliderMotor1' value='%SLIDERVALUE%' step='1' class='slider'><span id='textSliderValue'>%SLIDERVALUE%</span></p>";
    content += "<p><label for='timeMotor1'>Time Motor 1 : </label><input type='number' id='timeMotor1' min='0' max='60000' name='timeMotor1' value='";
    content += timeMotor1;
    content += "' step='1' class='inputNumber'></p>";
    content += "<p><label for='relay1'>Name : </label><input type='text' id='relay1' name='relay1' value='" +NameRelay1+ "' class='inputText'></p>";
    content += "<p><label for='relay2'>Name : </label><input type='text' id='relay2' name='relay2' value='" +NameRelay2+ "' class='inputText'></p>";
    content += "<p><label for='relay3'>Name : </label><input type='text' id='relay3' name='relay3' value='" +NameRelay3+ "' class='inputText'></p>";

    content += "<input type='submit' onclick='saveTweak(this)' name='tweakSave' value='Save' />";
    content += "</form>";
    content += "</html>";

    return content;
}