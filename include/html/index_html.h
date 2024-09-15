#if defined(__arm__) && !defined(PROGMEM)
#define PROGMEM
#define PSTR(STR) STR
#endif


// INDEX PAGE
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>AXSiot Server</title>
  <style>
    body {background : rgb(250,250,255); max-width: 800px; margin: auto; padding-bottom: 25px;}
    input {font-size: 1.3rem; margin : 10px; padding: 10px;}
    input.buttonMenu {width : 75px; border : none; }
    div#bodyheader {
        display: grid;
        grid-template-columns: 4fr 1fr;
        background : lavender;
      }
    h2 {
        font-size: 2.3rem;
      }
    div#settingsMenu {
      text-align : right;
    }
    div#menuItems {
        display: none;
        position : relative;
        min-width : 75px;
        text-align : right;
        border : 1px solid gray;
        box-shadow: 0px 0px 1px 1px rgb(204, 203, 203);
      } 
      div#menuItems input {
        width : -moz-available;
      }   
    p {font-size: 1.3rem;}
    p {display : inline-flexbox;}
    p#sliderText {display : none;}
    p#slider {display : none;}
    .slider { -webkit-appearance: none; margin: 14px; width: 360px; height: 25px; background: #FFD65C;
      outline: none; -webkit-transition: .2s; transition: opacity .2s;}
    .slider::-webkit-slider-thumb {-webkit-appearance: none; appearance: none; width: 35px; height: 35px; background: #003249; cursor: pointer;}
    .slider::-moz-range-thumb { width: 35px; height: 35px; background: #003249; cursor: pointer; } 

    table#camControl button {
      margin : auto;
      padding : 3px;
      border : 1px solid black;
      width : 75px;
    }
  </style>
</head>

<body>
  <div id="bodyheader">
      <h2>AXSiot Server</h2>
      <div id="settingsMenu">
          <form action="menu" method="POST"><input class="buttonMenu" type="button" onclick="displayMenu()" value="&#9776;"></form>
          <div id="menuItems">
              <form action="network" method="POST"><input type="submit" value="&#8644; Network"></form>
              <form action="tweak" method="POST"><input type="submit" value="&#10049; Tweak"></form>
          </div>
      </div>
  </div>


<table id="camControl">
 <tr>
  <td>
  </td>
   
  <td>
   <input type="button" onclick="rotmove(this)" id="up" value="&uarr;">
  </td>
  <td>
  </td>
 </tr>

 <tr>
  <td>
   <input type="button" onclick="rotmove(this)" id="right" value="&cularr;">
  </td>
  <td>
  </td>
  <td>
   <input type="button" onclick="rotmove(this)" id="left" value="&curarr;">
  </td>
 </tr>

 <tr>
  <td>
  </td>
  <td>
   <input type="button" onclick="rotmove(this)" id="down" value="&darr;">
  </td>
  <td>
  </td>
 </tr>
</table>

  <p id="sliderText"><span id="textSliderValue">%SLIDERVALUE%</span></p>
  <p id="slider"><input type="range" onchange="updateSliderPWM(this)" id="pwmSlider" min="0" max="255" value="%SLIDERVALUE%" step="1" class="slider"></p>
  <p><span id="textPorteState">Status : %PORTESTATE%</span></p>
  <p><label for="Motor1">%NAMEMOTOR1% : </label><input type="button" onclick="updateMotor(this)" id="Motor" value="%PORTESTATE%"></p>
  <p><label for="out1">Relay 1 : </label><input type="button" onclick="relay(this)" id="out1" value="%STATEOUT1%"></p>
  <p><label for="out2">Relay 2 : </label><input type="button" onclick="relay(this)" id="out2" value="%STATEOUT2%"></p>
  <p><label for="out3">Relay 3 : </label><input type="button" onclick="relay(this)" id="out3" value="%STATEOUT3%"></p>
  <p>Input : </p>
  <p>Value 1 : %ANALOG3% </p>
  <p>Value 2 : %ANALOG4% </p>
  
<script>
    function displayMenu()
    {        
        document.getElementById("menuItems").style.display= document.getElementById("menuItems").style.display == "inline-grid" ? "" : "inline-grid";
    }
function updateSliderPWM(element) {
  var sliderValue = document.getElementById("pwmSlider").value;
  document.getElementById("textSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider?value="+sliderValue, true);
  xhr.send();
}

function updateMotor(element) {
  var porteState = document.getElementById("Motor").value;
  document.getElementById("textPorteState").innerHTML = porteState;
  if(porteState == "Fermer") {
    porteState = "Ouvert";
  }
  else {
    porteState = "Fermer";
  }
  console.log(porteState);
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (xhr.readyState == XMLHttpRequest.DONE) {
        // alert(xhr.responseText);
        document.getElementById("Motor").value = porteState;
    }
  }
  xhr.open("GET", "/slider?temp="+porteState, true);
  xhr.send();
}

function relay(element) {
  var id = element.id;
  var state = document.getElementById(id).value;
  if(state == "OFF") {
    state = "ON";
  }
  else {
    state = "OFF";
  }
  console.log(state);
  var xhr = new XMLHttpRequest();
  xhr.onreadystatechange = function() {
    if (xhr.readyState == XMLHttpRequest.DONE) {
        // alert(xhr.responseText);
        document.getElementById(id).value = state;
    }
  }
  xhr.open("GET", "/slider?"+id+"="+state, true);
  xhr.send();
}

function rotmove(element) {
  var id = element.id;
  var move = document.getElementById(id).value;
  console.log(id);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider?"+id, true);
  xhr.send();
}

</script>
</body>
</html>
)rawliteral";
