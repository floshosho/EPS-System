#include "./eps_functions.h"
#include <iostream>

float getCurrentPowerUsage() {
    return CurrentPowerUsage;
}

float getUpdatedBatteryEnergy() {
    std::cout << "This function gets the current battery energy\n";
    return 50;
}

/* 
    This may not be done yet. If the battery energy is all we need to determine
    if we have available power, then it's done. Otherwise I may need to add upon
    this function.
*/ 
bool isPowerAvailable(float incoming_hardware_power) {
    float expected_power = CurrentPowerUsage + incoming_hardware_power;
    if (expected_power >= getUpdatedBatteryEnergy()) {
        std::cerr << "ERROR: Hardware will exceed the current amount of power "
            << "the battery has.\n";
        return false;
    }
    std::cout << "There is power available\n";
    return true;
}


/*
    **NOTE: All enable functions must check if there is enough power available first.
    Next, increment the CURRENT_POWER_USAGE tracker variable if the specific hardware
    was turn on correctly
*/

bool EnableESPOverheadRequest() {
    std::cout << "Turning on EPS Overhead\n";
    return true;
}

bool DisableEPSOverheadRequest() {
    std::cout << "Turning off EPS Overhead\n";
    return true;
}

bool EnableBatteryHeatersRequest() {
    std::cout << "Turning on Battery Heaters\n";
    return true;
}

bool DisableBatteryHeatersRequest() {
    std::cout << "Turning off Battery Heaters\n";
    return true;
}

bool EnableCameraRequest() {
    std::cout << "Turning on Camera\n";
    return true;
}

bool DisableCameraRequest() {
    std::cout << "Turning off Camera\n";
    return true;
}

bool EnableADRV9361Request() {
    std::cout << "Turning on ADRV 9361\n";
    return true;
}

bool DisableADRV9361Request() {
    std::cout << "Turning of ADRV 9361\n";
    return true;
}

bool EnableFineSunSensorRequest() {
    std::cout << "Turning on Fine Sun Sensor\n";
    return true;
}

bool DisableFineSunSensorRequest() {
    std::cout << "Turning off Fine Sun Sensor\n";
    return true;
}

bool EnableCoarseSunSensorRequest() {
    std::cout << "Turning on Coarse Sun Sensor\n";
    return true;
}

bool DisableCoardSunSensorRequest() {
    std::cout << "Turning off Coarse Sun Sensor\n";
    return true;
}

bool EnableMagnetometerRequest() {
    std::cout << "Turning on Magnetometer\n";
    return true;
}

bool DisableMagnetometerRequest() {
    std::cout << "Turning off Magnetometer\n";
    return true;
}

bool EnableMagnetorquersRequest() {
    std::cout << "Turning on Magnetorquers\n";
    return true;
}

bool DisableMagnetorquersRequest() {
    std::cout << "Turning off Magnetorquers\n";
    return true;
}

bool EnableUHFRecieveRequest() {
    std::cout << "Turning on UHF Recieve\n";
    return true;
}

bool DisableUHFRecieveRequest() {
    std::cout << "Turning off UHF Receive\n";
    return true;
}

bool EnableUHFTransmitRequest() {
    std::cout << "Turning on UHF Transmit\n";
    return true;
}

bool DisableUHFTransmitRequest() {
    std::cout << "Turning off UHF Transmit\n";
    return true;
}

bool EnableXBandReceiveRequest() {
    std::cout << "Turning on X-Band Comms\n";
    return true;
}

bool EnableXBandReceiveRequest() {
    std::cout << "Turning off X-Band Comms\n";
    return true;
}
