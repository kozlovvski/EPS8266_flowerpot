#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "../lib/EEPROMHandler/EEPROMHandler.h"
#include "../lib/WiFiHandler/WiFiHandler.h"
#include "../lib/WebHandler/WebHandler.h"

#ifndef STASSID
#define STASSID "FunBox2-21B8"
#define STAPSK "12345678"
#endif

EEPROMHandlerClass EEPROMHandler;
WiFiHandlerClass WiFiHandler;
WebHandlerClass WebHandler;

const int led = LED_BUILTIN;

const unsigned long MEASURE_INTERVAL = 1000;
unsigned long lastMeasureMillis;

void setup()
{
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);

  EEPROMHandler.init();
  WiFiHandler.init(EEPROMHandler.getSsid(), EEPROMHandler.getPassword());
  WebHandler.init(EEPROMHandler, WiFiHandler);
}

void loop()
{
  WebHandler.processRequest();

  if (millis() - lastMeasureMillis > MEASURE_INTERVAL)
  {
    if (digitalRead(0) == 0)
    {
      EEPROMHandler.resetEEPROM();
      ESP.restart();
    }
  }
}