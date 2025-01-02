#include "html/style.h"

String style_css (void) {
    String style = "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
    style += "<style>";
    style += "body {background : rgb(250,250,255); max-width: 800px; margin:0px auto; padding-bottom: 25px;}";
    style += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    style += "input.returnButton { background-color :  white; border : 1px solid  #d0d3d4; }";
    style += "input.returnButton:hover { background-color :  #5499c7; }";
    style += "</style>";
    return style;
}