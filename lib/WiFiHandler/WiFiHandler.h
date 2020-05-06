#ifndef _WIFIHANDLER_h
#define _WIFIHANDLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <ESP8266WiFi.h>

class WiFiHandlerClass
{
private:
protected:
public:
  void init(String ssid, String password);
};

extern WiFiHandlerClass WiFiHandler;

#endif