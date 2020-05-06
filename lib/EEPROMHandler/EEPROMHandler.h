// EepromDataHandler.h

#ifndef _EEPROM_HANDLER
#define _EEPROM_HANDLER

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include <EEPROM.h>

class EEPROMHandlerClass
{
private:
  String _ssid;
  String _password;
  int _days;
  int _hours;
  int _time;
  int _min;
  int _max;

  void clearEEPROMBetween(int a, int b);
  void writeToEEPROM(String value, int start, int end);
  void readEEPROMToClass();

protected:
public:
  String getSsid();
  String getPassword();
  int getIntervalDays();
  int getIntervalHours();
  int getWateringTime();
  int getSensorMin();
  int getSensorMax();

  void resetEEPROM();
  void writeInputToEEPROM(String ssid, String password, String days, String minutes, String time, String min, String max);
  void init();
};

extern EEPROMHandlerClass EEPROMHandler;

#endif