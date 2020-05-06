#include "WiFiHandler.h"

void WiFiHandlerClass::init(String ssid, String password)
{
  WiFi.disconnect();
  WiFi.softAPdisconnect();

  if (ssid.length() > 1)
  {
    WiFi.softAP(ssid.c_str(), password.c_str());
    Serial.println("Access point set up!");
  }
  else
  {
    WiFi.softAP("Kwiatek"); // set WiFi Access Point Name
    Serial.println("Initial access point set up!");
  }
}