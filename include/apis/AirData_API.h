#ifndef AirData_API_h
#define AirData_API_h



#include "apis/API_Blueprint.h"

#include <Adafruit_BME680.h>


class AirData_API final : API_Blueprint {

public:

    bool begin() override;
    void get(Response* response) override;

private:

    Adafruit_BME680 bme680;
};



#endif