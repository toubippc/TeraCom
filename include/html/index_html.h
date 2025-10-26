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
      
    div#line1 {
      display: grid;
      grid-template-columns: 1fr 1fr;
      margin: 10px;
      width: 100%%;
    }
      
    
    .gauge-container {
      width: 300px;
      margin: 50px auto;
      position: relative;
    }
    
    .gauge {
      width: 100%%;
      height: 20px;
      background: #f0f0f0;
      border-radius: 10px;
      overflow: hidden;
      position: relative;
    }
    
    .gauge-fill {
      height: 100%%;
      width: 0%%;
      background: linear-gradient(to right, #fff 0%%, #2600ff 40%%, #f44336 100%%);
      transition: width 0.3s ease;
      border-radius: 10px;
    }
    
    .gauge-marks {
      position: absolute;
      width: 100%%;
      height: 100%%;
      display: flex;
      justify-content: space-between;
      padding: 0 10px;
      box-sizing: border-box;
    }
    
    .gauge-mark {
      width: 1px;
      height: 10px;
      background: rgba(0, 0, 0, 0.2);
      position: relative;
    }
    
    .gauge-mark.major {
      height: 15px;
    }
    
    .gauge-labels {
      width: 100%%;
      display: flex;
      justify-content: space-between;
      margin-top: 5px;
      padding: 0 10px;
      box-sizing: border-box;
      color: #666;
      font-family: Arial, sans-serif;
      font-size: 12px;
    }
    
    .current-value {
      position: absolute;
      top: -25px;
      transform: translateX(-50%%);
      background: #333;
      color: white;
      padding: 2px 8px;
      border-radius: 3px;
      font-family: Arial, sans-serif;
      font-size: 14px;
    }
    
    .current-value::after {
      content: '';
      position: absolute;
      bottom: -5px;
      left: 50%%;
      transform: translateX(-50%%);
      border-left: 5px solid transparent;
      border-right: 5px solid transparent;
      border-top: 5px solid #333;
    }
      
    .hidden {
      display: none;
      position: absolute;
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

  <div id="line1">
    <div id="ecu_content">
      <!-- Bouton arret urgence -->
      <p>ECU : <input type="button" onclick="ecu(this)" id="ecu" value=" %ECU% "></p>
    </div>
    <div id="time_content">
      <!-- Affichage de l'heure -->
      <p id="time">Time : <span id="timeValue">%TIME%</span></p>
    </div>
    
    
  <div class="hidden">
    <p>Input : </p>
    <p>Zone chaude : <span id="temp0"> %ANALOG1% </span>&degC</p>
    <p>Zone Froide : <span id="temp1"> %ANALOG2% </span>&degC</p>
    <p>Temperature : <span id="dht1"> %DHT1% </span>&degC</p>
    <p>Humidite : <span id="humidity1"> %HUMIDITY% </span>&percnt</p>
  </div>
  
  <label for="gauge">Temperature Zone Chaude</label>
  <div id="gauge" class="gauge-container">
      <div class="current-value">0&degC</div>
      <div class="gauge">
        <div class="gauge-marks"></div>
        <div class="gauge-fill"></div>
      </div>
      <div class="gauge-labels">
        <span>0&deg</span>
        <span>20&degC</span>
        <span>40&degC</span>
        <span>60&degC</span>
        <span>80&degC</span>
        <span>100&degC</span>
      </div>
  </div>
  <label for="gauge1">Temperature Zone Froide</label>
  <div id="gauge1" class="gauge-container">
      <div class="current-value">0&degC</div>
      <div class="gauge">
        <div class="gauge-marks"></div>
        <div class="gauge-fill"></div>
      </div>
      <div class="gauge-labels">
        <span>0&deg</span>
        <span>20&degC</span>
        <span>40&degC</span>
        <span>60&degC</span>
        <span>80&degC</span>
        <span>100&degC</span>
      </div>
  </div>
  <label for="gauge2">Temperature Ambiante</label>
  <div id="gauge2" class="gauge-container">
      <div class="current-value">0&degC</div>
      <div class="gauge">
        <div class="gauge-marks"></div>
        <div class="gauge-fill"></div>
      </div>
      <div class="gauge-labels">
        <span>0&degC</span>
        <span>20&degC</span>
        <span>40&degC</span>
        <span>60&degC</span>
        <span>80&degC</span>
        <span>100&degC</span>
      </div>
  </div>
  <label for="gauge3">Humidite</label>
  <div id="gauge3" class="gauge-container">
      <div class="current-value">?<span>&percnt;</span></div>
      <div class="gauge">
        <div class="gauge-marks"></div>
        <div class="gauge-fill"></div>
      </div>
      <div class="gauge-labels">
        <span>0&percnt;</span>
        <span>20&percnt;</span>
        <span>40&percnt;</span>
        <span>60&percnt;</span>
        <span>80&percnt;</span>
        <span>100&percnt;</span>
      </div>
  </div>
  
  <p><label for="out0">%RELAY0% : </label><input type="button" onclick="relay(this)" id="out1" value="%STATEOUT0%"></p>
  <p><label for="out1">%RELAY1% : </label><input type="button" onclick="relay(this)" id="out1" value="%STATEOUT1%"></p>
  <p><label for="out2">%RELAY2% : </label><input type="button" onclick="relay(this)" id="out2" value="%STATEOUT2%"></p>
  <p><label for="out3">%RELAY3% : </label><input type="button" onclick="relay(this)" id="out3" value="%STATEOUT3%"></p>

<script>

 // request data updates every 5000 milliseconds
    setInterval(updateSensor, 5000);
    setInterval(updateTime, 10000);
    
    function displayMenu()
    {        
        document.getElementById("menuItems").style.display= document.getElementById("menuItems").style.display == "inline-grid" ? "" : "inline-grid";
    }
        
// Gauge setup

class LinearGauge {
        
  constructor(idhtml) {
    this.root = document.getElementById(idhtml);
    this.gaugeFill = this.root.querySelector('.gauge-fill');
    this.currentValue = this.root.querySelector('.current-value');
    this.value = 0;
    this.maxValue = 100;
    
    this.createMarks();
    //this.animateValue(); // Pour la démonstration
  }

  createMarks() {
    const marksContainer = this.root.querySelector('.gauge-marks');
    for(let i = 0; i <= 50; i++) {
      const mark = document.createElement('div');
      mark.className = (Math.floor(i / 5) * 5 === i) ? 'gauge-mark major' : 'gauge-mark';
      marksContainer.appendChild(mark);
    }
  }

  setValue(value) {
    this.value = Math.max(0, Math.min(value, this.maxValue));
    const percentage = (this.value / this.maxValue) * 100;
    
    this.gaugeFill.style.width = `${percentage}%%`;
    this.currentValue.textContent = `${this.value}`;
    this.currentValue.style.left = `${percentage}%%`;
  }

  // Animation de démonstration
  animateValue() {
    let value = 0;
    let direction = 1;
    
    setInterval(() => {
      value += direction * 0.5;
      
      if(value >= 100) direction = -1;
      if(value <= 0) direction = 1;
      
      this.setValue(value);
    }, 50);
  }
}

const gauge = new LinearGauge("gauge"); // Zone chaude
const gauge1 = new LinearGauge("gauge1"); // Zone froide
const gauge2 = new LinearGauge("gauge2"); // Température ambiante
const gauge3 = new LinearGauge("gauge3"); // Humidité  
    
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
    
function updateSliderPWM(element) {
  var sliderValue = document.getElementById("pwmSlider").value;
  document.getElementById("textSliderValue").innerHTML = sliderValue;
  console.log(sliderValue);
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/slider?value="+sliderValue, true);
  xhr.send();
}
  
function updateTime() {
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/gettime", true);
  xhr.onload = function() {
    if (xhr.status === 200) {
      if (xhr.responseText) { // if the returned data is not null, update the values
        let data = JSON.parse(xhr.responseText);
        document.getElementById("timeValue").innerHTML = data.time;
      } else { // a problem occurred
        document.getElementById("timeValue").innerHTML = "?";
      }
    } else {
      console.log('Request failed.  Returned status of ' + xhr.status);
      document.getElementById("timeValue").innerHTML = "?";
    }
  };
  xhr.send();
}

function updateSensor() {
   var xhr = new XMLHttpRequest();
  xhr.open("GET", "/getdht11", true);
  xhr.onload = function() {
        if (xhr.status === 200) {

          if (xhr.responseText) { // if the returned data is not null, update the values

            var data = JSON.parse(xhr.responseText);
            document.getElementById("temp0").innerHTML = data.temperature_0;
            gauge.setValue(data.temperature_0); // Définir une valeur pour la gauge
            document.getElementById("temp1").innerHTML = data.temperature_1;
            gauge1.setValue(data.temperature_1); // Définir une valeur pour la gauge1
            document.getElementById("dht1").innerHTML = data.dht_1;
            gauge2.setValue(data.dht_1); // Définir une valeur pour la gauge2
            document.getElementById("humidity1").innerText = data.humidity_1;
            gauge3.setValue(data.humidity_1); // Définir une valeur pour la gauge3

          } else { // a problem occurred

            document.getElementById("temp1").innerText = "?";
            document.getElementById("humidity1").innerText = "?";
          }
        } else {
          console.log('Request failed.  Returned status of ' + xhr.status);

          document.getElementById("temp1").innerText = "?";
          document.getElementById("humidity1").innerText = "?";
          
        }
      };
      
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
