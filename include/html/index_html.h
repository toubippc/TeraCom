#if defined(__arm__) && !defined(PROGMEM)
#define PROGMEM
#define PSTR(STR) STR
#endif


// INDEX PAGE
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>
  <meta http-equiv="content-type" content="text/html; charset=UTF-8" >
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>LeoMatic</title>
  <style>
    :root{--bg:#1a1a1e;--card:#242428;--text:#f5f5f5;--muted:#a0a0a8;--accent-orange:#ff8c00;--accent-yellow:#ffc107;--accent-red:#ff3333}
    body {background : var(--bg); max-width: 900px; margin: auto; padding-left: 5px; padding-bottom: 25px; color: var(--text);}
    input {font-size: 1.3rem; margin : 10px; padding: 10px; background:#242428; color:#f5f5f5; border:1px solid #ff8c00;}
    input.buttonMenu {width : 75px; border : none; background:#ff8c00; color:#1a1a1e; font-weight:600; cursor:pointer;}
    div#bodyheader {
        display: flex;
        align-items: center;
        justify-content: space-between;
        gap: 12px;
        border-bottom: 2px solid var(--accent-orange);
        padding: 12px 6px 14px 6px;
        margin-bottom: 18px;
      }
    h2, h1 {
        font-size: 1.6rem;
        color: var(--accent-orange);
        margin: 0;
      }
    .time {color: var(--muted); font-size: 0.95rem}
    div#settingsMenu {
      text-align : right;
    }
    div#menuItems {
        display: none;
        position : relative;
        min-width : 75px;
        text-align : right;
        border : 1px solid #ff8c00;
        box-shadow: 0px 0px 8px rgba(255,140,0,0.3);
        background: #242428;
        border-radius: 4px;
      } 
      div#menuItems input {
        width : -moz-available;
        background: #1a1a1e;
        color: #ff8c00;
        border: none;
      }   
    p {font-size: 1.3rem; color: #f5f5f5;}
    p {display : inline-flexbox;}
    p#sliderText {display : none;}
    p#slider {display : none;}
    .slider { -webkit-appearance: none; margin: 14px; width: 360px; height: 25px; background: #ffc107;
      outline: none; -webkit-transition: .2s; transition: opacity .2s; border-radius: 5px;}
    .slider::-webkit-slider-thumb {-webkit-appearance: none; appearance: none; width: 35px; height: 35px; background: #ff3333; cursor: pointer; border-radius: 50%;}
    .slider::-moz-range-thumb { width: 35px; height: 35px; background: #ff3333; cursor: pointer; border-radius: 50%;} 

    table#camControl button {
      margin : auto;
      padding : 3px;
      border : 2px solid #ff8c00;
      width : 75px;
      background: transparent;
      color: #f5f5f5;
      cursor: pointer;
      border-radius: 4px;
    }
      
    div#line1 {
      display: grid;
      grid-template-columns: 1fr;
      margin: 10px;
      width: 95%%;
    }
      
    
    .gauge-container {
      width: 300px;
      margin: 50px auto;
      position: relative;
    }
    
    .gauge {
      width: 100%%;
      height: 20px;
      background: #2a2a2e;
      border-radius: 10px;
      overflow: hidden;
      position: relative;
      border: 1px solid #ff8c00;
    }
    
    .gauge-fill {
      height: 100%%;
      width: 0%%;
      background: linear-gradient(to right, #ff8c00 0%%, #ffc107 50%%, #ff3333 100%%);
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
      background: rgba(255, 140, 0, 0.3);
      position: relative;
    }
    
    .gauge-mark.major {
      height: 15px;
      background: rgba(255, 140, 0, 0.6);
    }
    
    .gauge-labels {
      width: 100%%;
      display: flex;
      justify-content: space-between;
      margin-top: 5px;
      padding: 0 10px;
      box-sizing: border-box;
      color: #a0a0a8;
      font-family: Arial, sans-serif;
      font-size: 12px;
    }
    
    .current-value {
      position: absolute;
      top: -25px;
      transform: translateX(-50%%);
      background: #ff8c00;
      color: #1a1a1e;
      padding: 2px 8px;
      border-radius: 3px;
      font-family: Arial, sans-serif;
      font-size: 14px;
      font-weight: 600;
    }
    
    .current-value::after {
      content: '';
      position: absolute;
      bottom: -5px;
      left: 50%%;
      transform: translateX(-50%%);
      border-left: 5px solid transparent;
      border-right: 5px solid transparent;
      border-top: 5px solid #ff8c00;
    }
      
    .hidden {
      display: none;
      position: absolute;
    }

    /* Card layout (preview-like) */
    .wrap {max-width:900px;margin:0 auto;padding:12px}
    .cards {display:grid;grid-template-columns:repeat(auto-fit,minmax(310px,1fr));gap:15px;margin:5px 4px}
    .card {background:linear-gradient(180deg, rgba(255,255,255,0.02), rgba(255,255,255,0.01));border-radius:10px;padding:12px;box-shadow:0 8px 18px rgba(0,0,0,0.25);border:1px solid rgba(255,255,255,0.04); min-width: fit-content;}
    .card-title{font-weight:700;margin-bottom:8px;color:#ffc107}
    .value{font-size:1.3rem;font-weight:700;margin-bottom:8px;color:#f5f5f5}
    .small{font-size:0.9rem;color:#a0a0a8}
    .relay-btn{appearance:none;border:2px solid #ff8c00;background:transparent;color:#f5f5f5;padding:10px 12px;border-radius:8px;font-weight:700;cursor:pointer;transition:all 0.18s}
    .relay-btn:hover{background:#ff8c00;color:#1a1a1e}
    .relay-btn.on{background:#ff3333;border-color:#ff3333;color:#1a1a1e}
    @media (max-width:520px){.cards{grid-template-columns:1fr}}
    .relays{display:grid;grid-template-columns:repeat(auto-fit,minmax(180px,1fr));gap:12px;margin:12px 4px}
    .relay-card{background:transparent;border-radius:8px;padding:6px;display:flex;flex-direction:column;align-items:stretch;gap:6px}
    .relay-card .relay-btn{width:100%;text-align:center}
    
    label {
      color: #ffc107;
      font-weight: 600;
      display: block;
      margin-top: 15px;
      margin-bottom: 5px;
    }

    .ecu_content {
      display: flex;
      flex-direction: column;
      align-items: center;
      justify-content: center;
      margin-top: 20px;
      with: 100%;
    }
    .ecu_button {
      appearance: none;
      border: 2px solid #ff8c00;
      background: transparent;
      color: #f5f5f5;
      padding: 10px 20px;
      border-radius: 8px;
      font-weight: 700;
      cursor: pointer;
      transition: all 0.18s;
      font-size: 1.2rem;
      width: 95%;
    }
    .ecu_button:hover {
      background: #ff8c00;
      color: #1a1a1e;
    }
    
    .ecu_button.active {
      background: #ff3333;
      border-color: #ff3333;
      color: #d9d9d9;
    }


  </style>
</head>

<body>
    <div id="bodyheader">
      <h2>🦎 LéoMatic Module</h2>
      <div style="display:flex;align-items:center;gap:12px;">
      <div class="time" id="time">Time : <span id="timeValue">%TIME%</span></div>
      <div id="settingsMenu">
        <form action="menu" method="POST"><input class="buttonMenu" type="button" onclick="displayMenu()" value="&#9776;"></form>
        <div id="menuItems">
          <form action="network" method="POST"><input type="submit" value="&#8644; Network"></form>
          <form action="tweak" method="POST"><input type="submit" value="&#10049; Tweak"></form>
          <form action="program" method="POST"><input type="submit" value="&#10049; Program"></form>
          <form action="settings" method="POST"><input type="submit" value="&#9881; Settings"></form>
        </div>
      </div>
      </div>
    </div>

  <div id="line1">

    
    
  <div class="section-title">📊 Capteurs</div>

  <div class="hidden">
    <p>Input : </p>
    <p>Zone chaude : <span id="temp0"> %ANALOG1% </span>&degC</p>
    <p>Zone Froide : <span id="temp1"> %ANALOG2% </span>&degC</p>
    <p>Temperature : <span id="dht1"> %DHT1% </span>&degC</p>
    <p>Humidite : <span id="humidity1"> %HUMIDITY% </span>&percnt</p>
  </div>
  
  <div class="cards">
    <div class="card" id="card-1">
      <div class="card-title">Temperature %SONDE1%</div>
      <div class="value" id="v1"> %ANALOG1% &degC</div>
      <div id="gauge" class="gauge-container">
          <div class="current-value">0&degC</div>
          <div class="gauge">
            <div class="gauge-marks"></div>
            <div class="gauge-fill"></div>
          </div>
          <div class="gauge-labels">
            <span>0&deg;C</span>
            <span>20&deg;C</span>
            <span>40&deg;C</span>
            <span>60&deg;C</span>
            <span>80&deg;C</span>
            <span>100&deg;C</span>
          </div>
      </div>
      <div class="small">Sonde : %SONDE1%</div>
    </div>

    <div class="card" id="card-2">
      <div class="card-title">Temperature Zone %SONDE2%</div>
      <div class="value" id="v2"> %ANALOG2% &degC</div>
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
      <div class="small">Sonde : %SONDE2%</div>
    </div>

    <div class="card" id="card-3">
      <div class="card-title">Temperature %SONDE3%</div>
      <div class="value" id="v3"> %DHT1% &degC</div>
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
      <div class="small">Sonde : %SONDE3%</div>
    </div>

    <div class="card" id="card-4">
      <div class="card-title">%SONDE4%</div>
      <div class="value" id="v4"> %HUMIDITY% &percnt;</div>
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
      <div class="small">Sonde : %SONDE4%</div>
    </div>
  </div>
  
  <div class="section-title">⚡ Relais</div>
  <div class="relays">
    <div class="relay-card"><div class="small">%RELAY0%</div><input class="relay-btn" type="button" id="out0" onclick="relay(this)" value="%STATEOUT0%"></div>
    <div class="relay-card"><div class="small">%RELAY1%</div><input class="relay-btn" type="button" id="out1" onclick="relay(this)" value="%STATEOUT1%"></div>
    <div class="relay-card"><div class="small">%RELAY2%</div><input class="relay-btn" type="button" id="out2" onclick="relay(this)" value="%STATEOUT2%"></div>
    <div class="relay-card"><div class="small">%RELAY3%</div><input class="relay-btn" type="button" id="out3" onclick="relay(this)" value="%STATEOUT3%"></div>
  </div>

  <div id="ecu_content">
    <!-- Bouton arret urgence -->
    <p>ECU : <input type="button" onclick="ecu(this)" id="ecu_button" value=" %ECU% "></p>
  </div>
  
  </div>
  
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
            if(document.getElementById('v1')) document.getElementById('v1').textContent = parseFloat(data.temperature_0).toFixed(1) + '\u00B0C';
            document.getElementById("temp1").innerHTML = data.temperature_1;
            gauge1.setValue(data.temperature_1); // Définir une valeur pour la gauge1
            if(document.getElementById('v2')) document.getElementById('v2').textContent = parseFloat(data.temperature_1).toFixed(1) + '\u00B0C';
            document.getElementById("dht1").innerHTML = data.dht_1;
            gauge2.setValue(data.dht_1); // Définir une valeur pour la gauge2
            if(document.getElementById('v3')) document.getElementById('v3').textContent = parseFloat(data.dht_1).toFixed(1) + '\u00B0C';
            document.getElementById("humidity1").innerText = data.humidity_1;
            gauge3.setValue(data.humidity_1); // Définir une valeur pour la gauge3
            if(document.getElementById('v4')) document.getElementById('v4').textContent = parseFloat(data.humidity_1).toFixed(1) + '%';

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
