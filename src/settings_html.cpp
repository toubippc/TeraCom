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
        p.input-row {\
            display: flex;\
            justify-content: space-between;\
            align-items: center;\
            gap: 12px;\
        }\
        p.sendsettings {\
            display: flex;\
            justify-content: center;\
        }\
        p.sendsettings input[type=\"submit\"] {\
            width: 30%;\
            background: var(--accent-orange);\
            border: none;\
            padding: 15px;\
            border-radius: var(--border-radius);\
            color: black;\
            font-weight: bold;\
            font-size: 1rem;\
            cursor: pointer;\
        }\
        .ecu_content {\
        display: flex;\
        flex-direction: column;\
        align-items: center;\
        justify-content: center;\
        margin-top: 20px;\
        width: 100%%;\
        } \
        .ecu_content p {\
        width: 100%%;\
        text-align: center;\
        }\
        .ecu_button {\
        appearance: none;\
        border: 2px solid #ff0000;\
        background: var(--accent-red);\
        color: var(--text);\
        padding: 10px 20px;\
        border-radius: 8px;\
        font-weight: 700;\
        cursor: pointer;\
        transition: all 0.18s;\
        font-size: 1.2rem;\
        width: 95%%;\
        }\
        .ecu_button:hover {\
        background: var(--accent-red) !important;\
        color: var(--text) !important;\
        }\
        .ecu_button.active {\
        background: #ff3333;\
        border-color: #ff3333;\
        color: #d9d9d9;\
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
    content += "<p class='input-row'><label for='hostname'>Hostname :</label>";
    content += "<input type='text' id='hostname' name='hostname' value='" + hostname + "' class='inputText'></p>";

    content += "<p class='input-row'><label for='http_username'>HTTP Username :</label>";
    content += "<input type='text' id='http_username' name='http_username' value='" + String(http_username) + "' class='inputText'></p>";
    content += "<p class='input-row'><label for='http_password'>HTTP Password :</label>";
    content += "<input type='text' id='http_password' name='http_password' value='" + String(http_password) + "' class='inputText'></p>";

    content += "<p class='sendsettings'>";
    content += "<input type='submit' value='Save Settings'>";
    content += "</form>";

    content += "<form method='get' action='restartesp' style='width: 100%; padding:5px; margin-top:20px;'>";
    content += "<input type='submit' value='Restart ESP'>";
    content += "</form>";
    content += "</p>";

    content += "<div id=\"ecu_content\" class=\"ecu_content\">";
    content += "<!-- Bouton arret urgence -->";
    content += "<p>ECU : <input type=\"button\" onclick=\"ecu(this)\" id=\"ecu_button\" class=\"ecu_button\" value='" + String(ECU_STATE) + "'></p>";
    content += "</div>";

    content += "<script type=\"text/javascript\">";
    content += "function ecu(button) {";
    content += "  var xhr = new XMLHttpRequest();";
    content += "  var ecuState = document.getElementById(\"ecu_button\").value;";
    content += "  if(ecuState == \"ON\") {";
    content += "    ecuState = \"OFF\";";
    content += "  }";
    content += "  else {";
    content += "    ecuState = \"ON\";";
    content += "  }";
    content += "  xhr.open('GET', '/ecu?ecu=ecuState', true);";
    content += "  xhr.onreadystatechange = function() {";
    content += "    if (xhr.readyState == 4 && xhr.status == 200) {";
    content += "      var newState = xhr.responseText;";
    content += "      button.value = !ecuState;";
    content += "      if (newState == \"ON\") {";
    content += "        button.classList.add('active');";
    content += "      } else {";
    content += "        button.classList.remove('active');";
    content += "      }";
    content += "    }";
    content += "  };";
    content += "  xhr.send();";
    content += "}";
    /*
    function ecu(element) {
  var ecuState = document.getElementById("ecu").value;
  if(ecuState == "ON") {
    ecuState = "OFF";
  }
  else {
    ecuState = "ON";
  }
  console.log(ecuState);
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (xhr.readyState == XMLHttpRequest.DONE) {
        // alert(xhr.responseText);
        document.getElementById("ecu").value = ecuState;
    }
  }
  xhr.open("GET", "/ecu?ecu="+ecuState, true);
  xhr.send();
}
    */

    content += "</script>";
    
    content += "</body></html>";
    return content;
}