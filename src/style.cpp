#include "html/style.h"

String style_css (void) {
    String style = "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    style += "<style>";
    style += ":root{--bg:#1a1a1e;--card:#242428;--text:#f5f5f5;--muted:#a0a0a8;--accent-orange:#ff8c00;--accent-yellow:#ffc107;--accent-red:#ff3333}";
    style += "body {background : var(--bg); max-width: 900px; margin: auto; padding-left: 5px; padding-bottom: 25px; color: var(--text);}";
    style += "input {font-size: 1.3rem; margin : 10px; padding: 10px; background:#242428; color:#f5f5f5; border:1px solid #ff8c00;}";
    
    style += "div#bodyheader {";
    style += "display: flex;";
    style += "align-items: center;";
    style += "justify-content: space-between;";
    style += "gap: 12px;";
    style += "border-bottom: 2px solid var(--accent-orange);";
    style += "padding: 12px 6px 14px 6px;";
    style += "margin-bottom: 18px;";
    style += "}";
    
    style += "h2, h1 {";
    style += "font-size: 1.6rem;";
    style += "color: var(--accent-orange);";
    style += "margin: 0;";
    style += "}";

    style += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    style += "input.inputText { width : 150px; }";
    style += "input.inputInt { width : 75px; }";
    style += ".returnButton {";
    style += "background: var(--accent-orange) !important;";
    style += "color: var(--text) !important;";
    style += "border: none;";
    style += "padding: 10px 15px;";
    style += "font-size: 1.3rem;";
    style += "cursor: pointer;";
    style += "border-radius: 5px;";
    style += "}";
    style += "</style>";
    return style;
}