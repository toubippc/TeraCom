#include "html/settings_html.h"

String settings_html(void) {
    String style = "\
    <style>\
        :root{--bg:#1a1a1e;--card:#242428;--text:#f5f5f5;--muted:#a0a0a8;--accent-orange:#ff8c00;--accent-yellow:#ffc107;--accent-red:#ff3333}\
        body {background : var(--bg); max-width: 900px; margin: auto; padding-left: 5px; padding-bottom: 25px; color: var(--text);}\
        input {font-size: 1.3rem; margin : 10px; padding: 10px; background:#242428; color:#f5f5f5; border:1px solid #ff8c00;}\
        input.buttonMenu {width : 75px; border : none; background:#ff8c00; color:#1a1a1e; font-weight:600; cursor:pointer;}\
        div#bodyheader {\
            display: flex;\
            align-items: center;\
            justify-content: space-between;\
            gap: 12px;\
            border-bottom: 2px solid var(--accent-orange);\
            padding: 12px 6px 14px 6px;\
            margin-bottom: 18px;\
        }\
        h2, h1 {\
            font-size: 1.6rem;\
            color: var(--accent-orange);\
            margin: 0;\
        }\
        label {\
            color: #ffc107;\
            font-weight: 600;\
            display: block;\
            margin-top: 15px;\
            margin-bottom: 5px;\
        }\
    </style>\
    ";
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<body>";
    content += "<head>";
    content += "<title>ESP Settings</title>";
    content += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    content += "<meta charset=\"UTF-8\">";
    content += "<style>";
    content += "div#bodyheader { display: grid; grid-template-columns: 1fr 4fr; }";
    content += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    content += "input.inputText { width : 150px; }";
    content += "input.inputInt { width : 75px; }";
    content += "p.sendsettings { display: flex; justify-content: center; }";
    content += "</style>";
    content += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" >";
    content += style;
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

    content += "<p class='sendsettings'>";
    content += "<input type='submit' value='Save Settings'>";
    content += "</form>";

    content += "<form method='get' action='restartesp' style='width: 100%; padding:5px; margin-top:20px;'>";
    content += "<input type='submit' value='Restart ESP'>";
    content += "</form>";
    content += "</p>";

    return content;
}