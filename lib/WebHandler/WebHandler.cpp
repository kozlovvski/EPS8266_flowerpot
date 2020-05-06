#include "WebHandler.h"

ESP8266WebServer server(80);
String htmlStart = "<!DOCTYPE html>\n<html lang=\"en\">\n <head>\n <meta charset=\"UTF-8\" />\n <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n <link\n rel=\"shortcut icon\"\n href=\"data:image/png;base64,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\"\n type=\"image/x-icon\"\n />\n <title>Sterowanie kwiatkiem</title>\n <style>\n * {\n font-family: sans-serif;\n box-sizing: border-box;\n }\n\n body,\n html {\n min-width: 100vw;\n min-height: 100vh;\n margin: 0;\n }\n\n html {\n background-color: #2e691c;\n }\n\n body {\n display: flex;\n justify-content: center;\n align-items: center;\n\n width: 100%;\n height: 100%;\n padding: 20px;\n }\n\n .main {\n display: flex;\n flex-direction: column;\n width: 100%;\n max-width: 600px;\n padding: 20px;\n border-radius: 5px;\n\n background-color: #fff;\n }\n\n h1 {\n margin: 0;\n\n font-size: 32px;\n letter-spacing: 0.05em;\n\n color: #33831b;\n }\n\n h2 {\n display: flex;\n align-items: center;\n margin-top: 20px;\n\n font-size: 10px;\n font-weight: 300;\n text-transform: uppercase;\n letter-spacing: 0.2em;\n white-space: nowrap;\n\n color: #0004;\n }\n\n h2::after {\n content: \"\";\n display: inline-block;\n width: 100%;\n height: 1px;\n margin-left: 10px;\n background-color: #0003;\n }\n\n .labelwrap {\n display: flex;\n flex-wrap: wrap;\n\n margin: 0 -10px;\n }\n\n .labelwrap > * {\n width: 50%;\n padding: 0 10px;\n }\n\n @media screen and (max-width: 500px) {\n .labelwrap > * {\n width: 100%;\n }\n }\n\n label,\n span {\n color: #000a;\n }\n\n label {\n display: block;\n }\n\n input {\n display: block;\n width: 100%;\n margin: 10px 0;\n padding: 10px 12px;\n border-radius: 5px;\n\n appearance: none;\n -webkit-appearance: none;\n -moz-appearance: none;\n border: 1px solid #6eb658;\n }\n\n input[type=\"submit\"] {\n margin-top: 20px;\n padding: 10px;\n border-radius: 5px;\n\n font-size: 16px;\n\n color: #fff;\n background-color: #6eb658;\n }\n\n .flex-input {\n display: flex;\n align-items: center;\n }\n\n .flex-input span {\n margin-left: 10px;\n }\n </style>\n </head>\n <body>\n";
String htmlEnd = "\n </body>\n</html>\n";

void WebHandlerClass::init(EEPROMHandlerClass EEPROMHandler, WiFiHandlerClass WiFiHandler)
{
  _EEPROMHandler = EEPROMHandler;
  _WiFiHandler = WiFiHandler;

  server.on("/", std::bind(&WebHandlerClass::handleRoot, this));
  server.on("/submit", HTTP_POST, std::bind(&WebHandlerClass::handleSubmit, this));

  server.begin();
}

void WebHandlerClass::processRequest()
{
  server.handleClient();
}

void WebHandlerClass::handleRoot()
{
  String res = htmlStart;
  res += "<form\n method=\"post\"\n enctype=\"application/x-www-form-urlencoded\"\n action=\"/submit\"\n class=\"main\"\n >\n <h1>Sterowanie kwiatkiem 🌱</h1>\n <h2>Sieć</h2>\n <div class=\"labelwrap\">\n <div>\n <label>\n nazwa sieci:\n </label>\n <input\n type=\"text\"\n name=\"ssid\"\n value=\"";
  res += EEPROMHandler.getSsid();
  res += "\"\n placeholder=\"Psst... możesz dać emotki\"\n />\n </div>\n <div>\n <label>hasło do sieci:</label>\n <input\n type=\"text\"\n name=\"password\"\n value=\"";
  res += EEPROMHandler.getPassword();
  res += "\"\n placeholder=\"Hasło do sieci kwiatka\"\n />\n </div>\n </div>\n <h2>Podlewanie</h2>\n <label>\n podlewaj co:\n </label>\n <div class=\"labelwrap\">\n <div class=\"flex-input\">\n <input\n type=\"number\"\n name=\"days\"\n value=\"";
  res += EEPROMHandler.getIntervalDays();
  res += "\"\n min=\"0\"\n placeholder=\"co ile dni podlewać?\"\n />\n <span>dni</span>\n </div>\n <div class=\"flex-input\">\n <input\n type=\"number\"\n name=\"hours\"\n max=\"23\"\n min=\"0\"\n value=\"";
  res += EEPROMHandler.getIntervalHours();
  res += "\"\n placeholder=\"co ile godzin podlewać?\"\n />\n <span>godzin</span>\n </div>\n </div>\n <label>\n czas podlewania:\n </label>\n <div class=\"labelwrap\">\n <div class=\"flex-input\">\n <input\n type=\"number\"\n name=\"time\"\n value=\"";
  res += EEPROMHandler.getWateringTime();
  res += "\"\n min=\"0\"\n placeholder=\"jak długo podlewać?\"\n />\n <span>sekund</span>\n </div>\n </div>\n <h2>Kalibracja czujnika</h2>\n <div class=\"labelwrap\">\n <div>\n <label>\n minimum:\n </label>\n <input\n type=\"number\"\n name=\"min\"\n min=\"0\"\n max=\"1023\"\n value=\"";
  res += EEPROMHandler.getSensorMin();
  res += "\"\n placeholder=\"minimalny odczyt\"\n />\n </div>\n <div>\n <label>maximum:</label>\n <input\n type=\"number\"\n min=\"0\"\n max=\"1023\"\n name=\"max\"\n value=\"";
  res += EEPROMHandler.getSensorMax();
  res += "\"\n placeholder=\"maksymalny odczyt\"\n />\n </div>\n </div>\n <input type=\"submit\" value=\"Zapisz\" />\n </form>";
  res += htmlEnd;
  server.send(200, "text/html", res);
}

void WebHandlerClass::handleSubmit()
{
  String ssid = server.arg("ssid");
  String password = server.arg("password");
  String days = server.arg("days");
  String hours = server.arg("hours");
  String time = server.arg("time");
  String min = server.arg("min");
  String max = server.arg("max");

  EEPROMHandler.writeInputToEEPROM(ssid, password, days, hours, time, min, max);

  String res = htmlStart;
  res += "    <div class=\"main\">\n      <h1>I gotowe!</h1>\n      <p\n        >Możesz zamknąć tą kartę. Kwiatek się z Tobą rozłączył, ale tylko na\n        chwilę!<br />\n        Od teraz będzie dostępny cały czas w tym WiFi:</p\n      >\n      <p\n        >Nazwa: <b>";
  res += ssid;
  res += "</b><br />\n        Hasło: <b>";
  res += password;
  res += "</b>\n      </p>\n      <p\n        >Jeżeli będziesz chciała coś zmienić, to możesz się z nim połączyć i\n        zmienić ustawienia.</p\n      >\n    </div>";

  server.send(200, "text/html", res);
  ESP.restart();
}