#include "webserver/Webserver.h"

#include <Arduino.h>
#include <Wire.h>
#include <Ethernet.h>


bool setup_ok = false;

int port = 80; // standard http port
byte mac[6] = {0xA8, 0x61, 0x0A, 0xAE, 0x00, 0x92}; // TODO: CHANGE TO OWN MAC
Webserver server(port);


static bool start (const bool status, const String& topic) {
    // handles info output to reduce multiple similar code snippets
    if (status) Serial.println(topic + "-Start successful.");
    else Serial.println(topic + "-Start failed.");
    return status;
}


void setup() {

    Serial.begin(9600);
    Wire.begin();

    if (!start(EthernetClass::begin(mac), "Ethernet")) return; // start ethernet
    if (!start(server.begin(), "Server")) return; // start server

    // setup successful
    setup_ok = true;
    Serial.println("Setup successful.");
}


void loop() {

    // prevent program from executing relevant code if setup failed
    if (!setup_ok) {
        Serial.println("Setup failed. Server not running.");
        delay(3000);
        return;
    }

    // actual part of mainloop
    server.cycle();
}