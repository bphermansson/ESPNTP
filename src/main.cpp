#include <Arduino.h>
#include "connect.h"
#include "ntp.h"
#include "settings.h"

void setup() {
  Serial.begin(serialspeed);
  connectWifi();
  setup_NTP();
}

void loop() {
  time_t now;
  struct tm * timeinfo;
  time(&now);
  timeinfo = localtime(&now);

  char totTime[20];
  sprintf_P(totTime, (PGM_P)F("%02d:%02d:%02d"), timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
  Serial.println(totTime);
  delay(1000);

}
