#ifndef API_BLUEPRINT_H
#define API_BLUEPRINT_H



#include "webserver/types/Response.h"


class API_Blueprint {

public:

    virtual ~API_Blueprint() = default;

    virtual bool begin();
    virtual void get(Response* response);

protected:

    bool available = false;
};



#endif