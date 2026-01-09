#include "html/program_html.h"

String program_html(void) {
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<html>";
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
    content += ".returnButton {";
    content += "background: var(--accent-orange) !important;";
    content += "color: var(--text) !important;";
    content += "border: none;";
    content += "padding: 10px 15px;";
    content += "font-size: 1.3rem;";
    content += "cursor: pointer;";
    content += "border-radius: 5px;";
    content += "}";

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
    
    content += "<li><fieldset><legend><a href='/summer_scenario'>Summer day température : </a></legend>";
    content += "</fieldset></li>";  
    content += "</ul>";


    content += "<ul><h3><label for='winterbegin'>Winter begin (DDMM) : </label></h3>";
    content += "<input type='number' id='winterbeginDD' name='winterbeginDD' value='" +String(program.winter.beginDD)+ "' class='inputInt'>";
    content += " / <input type='number' id='winterbeginMM' name='winterbeginMM' value='" +String(program.winter.beginMM)+ "' class='inputInt'>";
    
    content += "<li><fieldset><legend>Day/Night Time</legend>";
    content += "<p><label for='winterdaybegin'>Day Time (HH : MM) : </label><input type='number' id='winterdaybeginH' name='winter_day_beginH' value='" +String(program.winter.day.beginH)+ "' class='inputInt'> : <input type='number' id='daybeginM' name='daybeginM' value='" +String(program.winter.day.beginM)+ "' class='inputInt'></p>";
    content += "<p><label for='winternightbegin'>Night Time (HH : MM) : </label><input type='number' id='winternightbeginH' name='winter_night_beginH' value='" +String(program.winter.night.beginH)+ "' class='inputInt'> : <input type='number' id='nightbeginM' name='nightbeginM' value='" +String(program.winter.night.beginM)+ "' class='inputInt'></p>";
    content += "</fieldset></li>";

    content += "<li><fieldset><legend><a href='/winter_scenario'>Set Winter température : </a></legend>";
    
    content += "</fieldset></li>";

    content += "</ul>";
        
    content += "<input type='submit' name='save' value='Save' />";
    content += "</form>";
    content += "</html>";

    return content;
}