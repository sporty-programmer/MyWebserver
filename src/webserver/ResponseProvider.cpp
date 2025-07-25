#include "webserver/ResponseProvider.h"


bool ResponseProvider::begin() {
    airData_API.begin();
    lightData_API.begin();
    return true; // ignore if some api modules are unavailable
}


void ResponseProvider::get(const Request* request, Response* response) {
    if (request->path == "/AIRDATA") airData_API.get(response);
    else if (request->path == "/LIGHTDATA") lightData_API.get(response);
    else response->text = "request received, uri invalid";
}