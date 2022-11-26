#include <ESP8266WiFi.h>

void socket_connect(const uint16_t port, const char *host) {
  while (!client.connect(host, port)) {
    Serial.println("Connection to host failed.. retrying");
    delay(1000);
  }
}