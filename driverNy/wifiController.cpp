#include "wifiController.h"


void initWiFi(const char* ssid, const char* password) {
    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
}

int getFrameIndex(String server) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
        // Init http connection
        HTTPClient http;
        http.begin(server.c_str());
        String payload = "";

        // Check response code
        int httpResponseCode = http.GET();

        // Get payload
        if (httpResponseCode > 0) {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            payload = http.getString();
            Serial.println(payload);
        }
        else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
            return httpResponseCode;
        }
        // Free resources
        http.end();
        return payload.toInt();
    }
    else {
        Serial.println("WiFi Disconnected");
        return -1;
    }
}

String getFrame(String server, int frameIndex) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
        // Init http connection
        HTTPClient http;
        http.begin((server + String(frameIndex)).c_str());
        String payload = "";

        // Check response code
        int httpResponseCode = http.GET();

        // Get payload
        if (httpResponseCode > 0) {
            Serial.print("HTTP Response code: ");
            Serial.println(httpResponseCode);
            payload = http.getString();
            Serial.println(payload);
        }
        else {
            Serial.print("Error code: ");
            Serial.println(httpResponseCode);
            return String(httpResponseCode);
        }
        // Free resources
        http.end();
        return payload;
    }
    else {
        Serial.println("WiFi Disconnected");
        return String(-1);
    }
}
