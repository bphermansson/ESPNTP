#include <Arduino.h>
#include "connect.h"
#include "ntp.h"
#include "settings.h"

char realTime[20], realDate[20];
int realyear, realmon;

void setup() {
  Serial.begin(serialspeed);
  connectWifi();
  setup_NTP();
}

void loop() {
  time_t now;                 // Create a variable for time
  struct tm * timeinfo;       // A struct with time fields
  time(&now);                 // get current time; same as: now = time(NULL)
  timeinfo = localtime(&now); // struct tm * localtime (const time_t * timer);
                              // Convert time_t to tm as local time

  sprintf_P(realTime, (PGM_P)F("%02d:%02d:%02d"), timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
  realyear = timeinfo->tm_year + 1900;
  realmon = timeinfo->tm_mon + 1;
  sprintf_P(realDate, (PGM_P)F("%04d-%02d-%02d"), realyear, realmon, timeinfo->tm_mday);

  Serial.println(realTime);
  Serial.println(realDate);

  delay(1000);

}
