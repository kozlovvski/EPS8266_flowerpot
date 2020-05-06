#include "EEPROMHandler.h"

const int EEPROMsize = 512;

/* EEPROM map:

0 - 63: reserved
64 - 127: ssid
128 - 191: password
192 - 195: days
196 - 199: hours
200 - 203: time
204 - 207: min
208 - 211: max

*/

// private

void EEPROMHandlerClass::clearEEPROMBetween(int a, int b)
{
  for (int i = a; i < b; ++i)
  {
    EEPROM.write(i, 255);
  }
}

void EEPROMHandlerClass::writeToEEPROM(String input, int start, int end)
{
  for (int i = 0; i < end; ++i)
  {
    if (i < input.length())
    {
      EEPROM.write(start + i, input[i]);
    }
    else
    {
      EEPROM.write(start + i, 255);
    }
  }
}

void EEPROMHandlerClass::readEEPROMToClass()
{
  EEPROM.begin(EEPROMsize);
  Serial.println("Starting EEPROM read");

  String ssid;
  for (int i = 64; i < 128; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      ssid += char(readValue);
    }
  }
  if (ssid.length() > 0)
  {
    _ssid = ssid;
  }
  Serial.println(ssid);

  String password;
  for (int i = 128; i < 192; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      password += char(readValue);
    }
  }
  if (password.length() > 0)
  {
    _password = password;
  }

  String days;
  for (int i = 192; i < 196; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      days += char(readValue);
    }
  }
  if (days.length() > 0)
  {
    _days = days.toInt();
  }

  String hours;
  for (int i = 196; i < 200; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      hours += char(readValue);
    }
  }
  if (hours.length() > 0)
  {
    _hours = hours.toInt();
  }

  String time;
  for (int i = 200; i < 204; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      time += char(readValue);
    }
  }
  if (time.length() > 0)
  {
    _time = time.toInt();
  }

  String min;
  for (int i = 204; i < 208; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      min += char(readValue);
    }
  }
  if (min.length() > 0)
  {
    _min = min.toInt();
  }

  String max;
  for (int i = 208; i < 212; ++i)
  {
    const uint8_t readValue = EEPROM.read(i);
    if (readValue == 255)
    {
      break;
    }
    else
    {
      max += char(readValue);
    }
  }

  if (max.length() > 0)
  {
    _max = max.toInt();
  }

  EEPROM.end();
  Serial.println("Read from EEPROM");
}

// public

String EEPROMHandlerClass::getSsid()
{
  return _ssid;
}

String EEPROMHandlerClass::getPassword()
{
  return _password;
}

int EEPROMHandlerClass::getIntervalDays()
{
  return _days;
}

int EEPROMHandlerClass::getIntervalHours()
{
  return _hours;
}

int EEPROMHandlerClass::getWateringTime()
{
  return _time;
}

int EEPROMHandlerClass::getSensorMin()
{
  return _min;
}

int EEPROMHandlerClass::getSensorMax()
{
  return _max;
}

void EEPROMHandlerClass::resetEEPROM()
{
  EEPROM.begin(EEPROMsize);

  for (int i = 0; i < EEPROMsize; ++i)
  {
    EEPROM.write(i, 255);
  }

  EEPROM.end();
  Serial.println("EEPROM clean");
}

void EEPROMHandlerClass::writeInputToEEPROM(String ssid, String password, String days, String hours, String time, String min, String max)
{
  EEPROM.begin(EEPROMsize);
  Serial.println("Starting EEPROM write");

  writeToEEPROM(ssid, 64, 128);
  writeToEEPROM(password, 128, 192);
  writeToEEPROM(days, 192, 196);
  writeToEEPROM(hours, 196, 200);
  writeToEEPROM(time, 200, 204);
  writeToEEPROM(min, 204, 208);
  writeToEEPROM(max, 208, 212);

  EEPROM.end();
  Serial.println("Saved to EEPROM");
}

void EEPROMHandlerClass::init()
{
  _ssid = "";
  _password = "";
  _days = 0;
  _hours = 0;
  _time = 0;
  _min = 0;
  _max = 1023;

  readEEPROMToClass();
}
