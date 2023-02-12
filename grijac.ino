#include "max6675.h"

int thermoDO = 4;
int thermoCS = 5;
int thermoCLK = 6;

const int RELAY_PIN = 3;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

const int TEMP_THRESHOLD_UPPER = 60; // upper threshold of temperature, change to your desire value
const int TEMP_THRESHOLD_LOWER = 55;

float temperature;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  Serial.println("MAX6675 test");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {

temperature = thermocouple.readCelsius();
Serial.println(thermocouple.readCelsius());

  if(temperature > TEMP_THRESHOLD_UPPER) {
    Serial.println("The heating element is turned off");
    digitalWrite(RELAY_PIN, LOW); // turn off
  } else if(temperature < TEMP_THRESHOLD_LOWER){
    Serial.println("The heating element is turned on");
    digitalWrite(RELAY_PIN, HIGH); // turn on
  }

  delay(500);



}
