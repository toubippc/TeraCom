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
    
    content += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    content += "input.inputText { width : 150px; }";
    content += "input.inputInt { width : 75px; }";
    content += ".returnButton {";
    content += "background: var(--accent-orange) !important;";
    content += "color: var(--text) !important;";
    content += "border: none;";
    content += "padding: 10px 15px;";
    content += "font-size: 1.3rem;";
    content += "cursor: pointer;";
    content += "border-radius: 5px;";
    content += "}";



    // Inputs
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

    content += "</style>";


    content += "<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\" >";
    content += "<script>";
    content += "</script>";
    content += "</head>";

    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/'\" value='&#8617;' />";
    content += "<h1> Program</h1>";
    content += "</div>";
    content += "<form method='get' action='setprogram' style='width: 100%; padding:5px;'>";

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
                content += "<input type='number' id='summerdaybeginH' name='summer_day_beginH' value=" + String(program.summer.day.beginH) + " class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value=" + String(program.summer.day.beginM) + " class='inputInt'>  </p>";
            content += "</div>";
        content += "</div>";

        content += "<div class='input-group'>";
            content += "<p><label for='summernightbegin'><span class='icon'>&#127769;</span> Night Time <i class='small info'>(Light OFF)</i> : </label>";
            content += "<div class='inputs-row'>";
                content += "<input type='number' id='summernightbeginH' name='summer_night_beginH' value=" + String(program.summer.day.endH) + " class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value=" + String(program.summer.day.endM) + " class='inputInt'>  </p>";
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
                    content += "<input type='number' id='winterdaybeginH' name='winter_day_beginH' value='" +String(program.winter.day.beginH)+ "' class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value='" +String(program.winter.day.beginM)+ "' class='inputInt'></p>";
                content += "</div>";
            content += "</div>";
        

            content += "<div class='input-group'>";
                content += "<p><label for='winternightbegin'><span class='icon'>&#127769;</span> Night Time (HH : MM) : </label>";
                content += "<div class='inputs-row'>";
                    content += "<input type='number' id='winternightbeginH' name='winter_night_beginH' value='" +String(program.winter.night.beginH)+ "' class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value='" +String(program.winter.night.beginM)+ "' class='inputInt'></p>";
                content += "</div>";
            content += "</div>";

            content += "<p id='setWinterTemp' class='btn-secondary'><a href='/winter_scenario'>Set Winter température : </a></p>";

        content += "</div>";

    content += "</section>";

    content += "<input class='btn-primary' type='submit' name='save' value='Save' />";
    content += "</form>";
    content += "</html>";

    return content;
}