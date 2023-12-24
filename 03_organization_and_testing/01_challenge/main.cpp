#include <iostream>
#include "temp_sensor.h"

int main() {
    Sensor::readTemperature();
    std::cout << "Temperature reading: " << Sensor::readTemperature() << std::endl;
    return 0;
}