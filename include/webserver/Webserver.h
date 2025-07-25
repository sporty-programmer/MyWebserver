#ifndef Webserver_h
#define Webserver_h



#include "webserver/RequestHandler.h"

#include <Ethernet.h>


class Webserver {

public:

    explicit Webserver(int port);

    bool begin();
    void cycle();

private:

    EthernetServer server;
    RequestHandler request_handler;
    const int port;
};



#endif