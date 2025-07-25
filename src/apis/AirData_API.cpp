#include "apis/AirData_API.h"



bool AirData_API::begin() {

    if (!bme680.begin()) return false;

    // prepare bme sensor
    bme680.setTemperatureOversampling(BME680_OS_8X);
    bme680.setHumidityOversampling(BME680_OS_2X);
    bme680.setPressureOversampling(BME680_OS_4X);
    bme680.setGasHeater(0, 0);

    available = true; // sensor initialization successful
    return true;
}


void AirData_API::get(Response* response) {

    if (!available) {
        response->text = "air data not available";
        return;
    }

    bme680.performReading();

    const float temperature = bme680.temperature;
    const float humidity = bme680.humidity;
    const unsigned long pressure = bme680.pressure / 100;

    const String result =
        "t=" + String(temperature) + "°C;"
        "h=" + String(humidity) + "%;"
        "p=" + String(pressure) + "hPa";

    response->text = result;
}