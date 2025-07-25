#ifndef LightData_API_h
#define LightData_API_h



#include "apis/API_Blueprint.h"


class LightData_API final : API_Blueprint {

public:

    explicit LightData_API(int pin);

    bool begin() override;
    void get(Response* response) override;

private:

    const int m_pin;
};



#endif