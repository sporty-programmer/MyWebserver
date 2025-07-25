#ifndef Response_h
#define Response_h



#include <Arduino.h>


struct Response {

    String headers = "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain; charset=utf-8\r\n"
        "Connection: close\r\n\r\n";

    String text;
};



#endif