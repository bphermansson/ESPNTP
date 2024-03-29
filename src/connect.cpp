#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "settings.h"

const char ssid[] = MYSSID;
const char pass[] = PASSWORD;

void connectWifi() {
  Serial.begin(115200);
  Serial.println("Connect to Wifi...");
  WiFi.persistent(false);  // Do not write Wifi settings to flash
  WiFi.begin(ssid, pass);
}
