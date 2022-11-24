#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include "ota.h"
#include "wifi.h"
#include "config.h"
#include "socket.h"

void core0loop( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(75);
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(75);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    client.write("IM STILL ALIVE!!");
  }
}

void core1loop( void * pvParameters ){
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for(;;){
    ArduinoOTA.handle();
    delay(250);
  }
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
    core0loop, /* Function to implement the task */
    "core0loop", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    2,  /* Priority of the task */
    &core0loophandle,  /* Task handle. */
    CoreZero); /* Core where the task should run */
  
  delay(250);

  xTaskCreatePinnedToCore(
    core1loop, /* Function to implement the task */
    "core0loop", /* Name of the task */
    10000,  /* Stack size in words */
    NULL,  /* Task input parameter */
    2,  /* Priority of the task */
    &core1loophandle,  /* Task handle. */
    CoreOne); /* Core where the task should run */
}


void loop() {
  
}
