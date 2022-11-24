#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "ota.h"
#include "wifi.h"
#include "config.h"
#include "socket.h"

void core1loop( void * pvParameters ){
  handleOTA();
  digitalWrite(LED_BUILTIN, HIGH);
  delay(75);
  digitalWrite(LED_BUILTIN, LOW);
  delay(50);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(75);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  //client.write("IM STILL ALIVE!!");
}

void core2loop( void * pvParameters ){

}

void setup() {
  Serial.begin(baud_rate);
  startWifi(ssid, password);
  startOTA(ota_port, ota_hostname, ota_password);
  //socket_connect(socket_port, socket_host);

  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(LED_BUILTIN, OUTPUT);

  xTaskCreatePinnedToCore(
    core1loop, /* Function to implement the task */
    "core1loop", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    0,  /* Priority of the task */
    &core1loophandle,  /* Task handle. */
    0); /* Core where the task should run */
    
  xTaskCreatePinnedToCore(
    core2loop, /* Function to implement the task */
    "core2loop", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    0,  /* Priority of the task */
    &core2loophandle,  /* Task handle. */
    0); /* Core where the task should run */
}


void loop() {
  
}
