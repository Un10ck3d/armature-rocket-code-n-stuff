#include "config.h"
#include "ota.h"
#include "socket.h"
#include "wifi.h"
#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

void setup() {
  Serial.begin(baud_rate);
  startWifi(ssid, password);
  startOTA(ota_port, ota_hostname, ota_password);
  // socket_connect(socket_port, socket_host);

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  ArduinoOTA.handle();
}
