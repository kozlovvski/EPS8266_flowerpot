#ifndef __WEB_HANDLER
#define __WEB_HANDLER

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#include "../EEPROMHandler/EEPROMHandler.h"
#include "../WiFiHandler/WiFiHandler.h"

class WebHandlerClass
{
private:
  EEPROMHandlerClass _EEPROMHandler;
  WiFiHandlerClass _WiFiHandler;

  void handleRoot();
  void handleSubmit();

protected:
public:
  void init(EEPROMHandlerClass EEPROMHandler, WiFiHandlerClass WiFiHandler);
  void processRequest();
};

extern WebHandlerClass WebHandler;

#endif