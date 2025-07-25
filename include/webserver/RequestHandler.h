#ifndef RequestHandler_h
#define RequestHandler_h



#include "webserver/ResponseProvider.h"
#include "webserver/types/Request.h"

#include <Ethernet.h>


class RequestHandler {

public:

    bool begin();
    void handle(EthernetClient* client);

    static void analyze_request(const String& request_string, Request* request);

private:

    ResponseProvider response_provider;
};



#endif