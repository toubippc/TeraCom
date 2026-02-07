#include "html/network_html.h"

String network_html(void) {
    IPAddress ip = WiFi.softAPIP();
    IPAddress iplocal = WiFi.localIP();
    String ipStr = String(ip[0]) + '.' + String(ip[1]) + '.' + String(ip[2]) + '.' + String(ip[3]);
    String iplocalStr = String(iplocal[0]) + '.' + String(iplocal[1]) + '.' + String(iplocal[2]) + '.' + String(iplocal[3]);
    uint8_t macAddr[6];
    WiFi.softAPmacAddress(macAddr);
    Serial.printf("MAC address = %02x:%02x:%02x:%02x:%02x:%02x \n", macAddr[0], macAddr[1], macAddr[2], macAddr[3], macAddr[4], macAddr[5]);    

    String StringMacAddr = "MAC address : " + String(macAddr[0]) + ":" + String(macAddr[1]) + ":" + String(macAddr[2]) + ":" + String(macAddr[3]) + ":" + String(macAddr[4]) + ":" + String(macAddr[5]);
    String content = "<!DOCTYPE HTML>\r\n";
    content += "<style>";
    content += "body {text-align : center;}";
    content += "div#bodyheader { display: grid; grid-template-columns: 1fr 4fr; background : lavender; }";
    content +="ol {text-align: left;}";
    content += "input {font-size: 1.3rem; margin : 10px; padding: 10px;}";
    content += "</style>";
    content += "<html>";
    content += "<div id=\"bodyheader\">";
    content += "<input class=\"returnButton\" type='button' onclick=\"location.href='/'\" value='&#8617;' />";
    content += "<h1>AXSiot Wifi settings</h1>";
    content += "</div>";
    content += "<form action=\"/scan\" method=\"POST\"><input type=\"submit\" value=\"Rescan\"></form>";
    content += "<p>Network statut :</p>";
    content += "<li>ESSID : "+String(ssid)+"</li>";
    content += "<li>Local IP : "+iplocalStr+"</li>"; 
    content += "<li>Access Point IP : "+ ipStr+"</li>";
    content += "<li>MAC addresse : "+ StringMacAddr +"</li>";
    content += "<p>";
    content += st;
    content += "</p><form method='get' action='setting'>";
    content += "<label>SSID : </label><input name='ssid' length=32><br />";
    content += "<label>Password : </label><input name='pass' length=64><br />";
    content += "<input type='submit' name='Enregistrer'>";
    content += "</form>";
    content += "</html>";
    return content;
}