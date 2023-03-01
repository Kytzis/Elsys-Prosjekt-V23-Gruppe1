#pragma once

#include <HTTPClient.h>
#include <sstream>
#include <WiFi.h>

class wifiController {
    const char* ssid;
    const char* password;   
    const char* server;

public:
    std::stringstream data;
    wifiController(const char* ssid, const char* password, const char* server);
    int tryGetMoreData();
};
