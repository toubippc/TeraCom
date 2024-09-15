#include "wpse324.h"

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
void wpse324init(void) {
     sensors.begin();
}
void wpse324(void) {
     
    // call sensors.requestTemperatures() to issue a global temperature
    // request to all devices on the bus
    Serial.print(" Requesting temperatures...");
    sensors.requestTemperatures(); // Send the command to get temperatures
    Serial.println("DONE");
    Serial.print("Temperature is: ");
    Serial.print(sensors.getTempCByIndex(0)); // Why "byIndex"?
    analog1Value = sensors.getTempCByIndex(0);
    // You can have more than one IC on the same bus.
    // 0 refers to the first IC on the wire
}