#include "apis/LightData_API.h"


LightData_API::LightData_API(const int pin) :
    m_pin(pin)
{}


bool LightData_API::begin() {
    available = true; // unable to check if photo resistor is placed or not
    return true;
}


void LightData_API::get(Response* response) {

    if (!available) {
        response->text = "light data not available";
        return;
    }

    response->text = String(map(analogRead(m_pin), 0, 1023, 0, 100)) + "%"; // read photo-resistor and convert it into percent
}