#include "webserver/Webserver.h"


Webserver::Webserver(int port) :
    server(port),
    port(port)
{}


bool Webserver::begin() {
    return request_handler.begin();
}


void Webserver::cycle() {

    EthernetClient client = server.available(); // potential client

    if (!client) return; // there is no client

    while (client.connected()) { // while the client is connected
        if (client.available()) { // if the client is ready
            request_handler.handle(&client); // handle request
            break; // end loop after handling
        }
    }

    delay(1); // safety delay before closing connection to client

    client.stop(); // close connection to client
}