#include "wifi_controller.h"

wifiController::wifiController(const char* ssid, const char* password, const String server): ssid{ssid}, password{password}, server{server} {
    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
}


int wifiController::tryGetNewData() {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED) {
        HTTPClient http;

        String getTextNumber = server + "/textCounter";
        String getText = server + "/text";

        int textNumber;

        http.begin(getTextNumber.c_str());

        int httpResponseCode = http.GET();

        if (httpResponseCode>0) {
            textNumber = static_cast<int>(http.getString());
        }
        
        http.end();

        if (textNumber == prevTextNumber) {
            return 0;
        }

        prevTextNumber = textNumber;
        http.begin(getText.c_str());

        int httpResponseCode = http.GET();

        if (httpResponseCode>0) {
            data << http.getString();
        }
        
        http.end();
        return 1;
    }
    else {
        Serial.println("WiFi Disconnected");
        return -1;
    }
  }
}
