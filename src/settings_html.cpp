#include "html/settings_html.h"

String settings_html(void) {
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<>";
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

    content += "<h1> ESP Settings</h1>";
    content += "<form method='get' action='setsettings' style='width: 100%; padding:5px;'>";
    content += "<ul><label for='hostname'><h3>Hostname :</h3></label>";
    content += "<input type='text' id='hostname' name='hostname' value='" + hostname + "' class='inputText'></ul>";

    content += "<ul><label for='http_username'><h3>HTTP Username :</h3></label>";
    content += "<input type='text' id='http_username' name='http_username' value='" + String(http_username) + "' class='inputText'></ul>";

    content += "<ul><label for='http_password'><h3>HTTP Password :</h3></label>";
    content += "<input type='text' id='http_password' name='http_password' value='" + String(http_password) + "' class='inputText'></ul>";

    content += "<input type='submit' value='Save Settings'>";
    content += "</form>";

    content += "<form method='get' action='restartesp' style='width: 100%; padding:5px; margin-top:20px;'>";
    content += "<input type='submit' value='Restart ESP'>";
    content += "</form>";

    return content;
}