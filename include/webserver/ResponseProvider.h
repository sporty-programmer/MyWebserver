#ifndef ResponseProvider_h
#define ResponseProvider_h



#include "webserver/types/Request.h"
#include "webserver/types/Response.h"

#include "apis/AirData_API.h"
#include "apis/LightData_API.h"


class ResponseProvider {

public:

    bool begin();
    void get(const Request* request, Response* response);

private:

    AirData_API airData_API = AirData_API();
    LightData_API lightData_API = LightData_API(PIN_A15);
};



#endif