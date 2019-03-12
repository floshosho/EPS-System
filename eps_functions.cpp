#include "./eps_functions.h"
#include <iostream>

/**
 * This constructor initializes a Component class instance
 * 
 * @param[name] String name of the component
 * @param[duty_cycle] The duty cycle of the component, between 0.0 - 1.0
 * @param[typical_power] The typical_power this specific component is using,
 * measured in watts
 * @return a Component instance
 */
Component::Component(std::string name, float duty_cycle, float typical_power)
    : name{name}, duty_cycle{duty_cycle}, typical_power{typical_power} {}

/**
 * The name of a Component instance
 * 
 * @param[void] no parameters
 * @return name of the Component as a string
 */
std::string Component::getName() {
    return name;
}

/**
 * The duty cycle of the Component instance
 * 
 * @param[void]
 * @return duty cycle of the Component as a float
 */
float Component::getDutyCycle() {
    return duty_cycle;
}

/**
 * The typical power of the Component instance
 * 
 * @param[void]
 * @return typical power of the Component as a float
 */
float Component::getTypicalPower() {
    return typical_power;
}

/**
 * The Component is either Enabled or Disabled
 * 
 * @param[void]
 * @return true if the Component is ON, or false if Component
 * is OFF
 */
bool Component::isEnabled() {
    return enabled;
}

/**
 * Set the Component on or off
 * 
 * @param[boolean] true to set Component as Enabled, else false to set
 * Component as disabled
 * @return void
 */
void Component::setEnabled(bool boolean) {
    enabled = boolean;
}

/**
 * The current power being used by all components in real-time
 * 
 * @param[void]
 * @return The current power usage of all components as a float, measured in watts
 */
float getCurrentPowerUsage() {
    return CurrentPowerUsage;
}

/**
 * The current power the batteries have left
 * 
 * @param[void]
 * @return The battery power as a float, measured in watts
 */
float getUpdatedBatteryEnergy() {
    std::cout << "This function gets the current battery energy\n";
    return 0;
}

/**
 * Whether or not there is power left to turn on a specific Component. This function
 * may not be done yet. If the battery energy is all we need to determine available
 * power, then it's done. Otherwise this function must be updated
 * 
 * @param[incoming_hardware_power] The power in watts that the Component will use up
 * @return True if there is power available, otherwise will return False
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

/**
 * Delete all Component references from the heap, we don't want any
 * memory leaks
 * 
 * @param[void]
 * @return void
 */
void PurgeComponents() {
    delete eps_overhead;
    delete battery_heaters;
    delete adrv_9361;
    delete fss;
    delete css;
    delete magnetometer;
    delete magnetorquer;
    delete uhf_rx;
    delete uhf_tx;
    delete xband_rx;
    delete xband_tx;
    delete camera;
}


/*
    **NOTE: All enable functions must check if there is enough power available first.
    Next, increment the CURRENT_POWER_USAGE tracker variable if the specific hardware
    was turn on correctly
*/

/**
 * Enable EPS Overhead. EPS Overhead is on the Always On Rail with a
 * duty cycle of 1.0
 * 
 * @param[void]
 * @return True if EPS Overhead enables, else False
 */
bool EnableESPOverheadRequest() {
    std::cout << "Turning on EPS Overhead\n";
    return true;
}

/**
 * Disable EPS Overhead.
 * 
 * @param[void]
 * @return True when EPS Overhead disables, else False
 */
bool DisableEPSOverheadRequest() {
    std::cout << "Turning off EPS Overhead\n";
    return true;
}

/**
 * Enable the Battery Heaters. The battery heaters are on the Always On Rail
 * with a duty cycle of 0.4
 * 
 * @param[void]
 * @return True if Battery Heaters enable, else False 
 */
bool EnableBatteryHeatersRequest() {
    std::cout << "Turning on Battery Heaters\n";
    return true;
}

/**
 * Disable the Battery Heaters. 
 * 
 * @param[void]
 * @return True if Battery Heaters disable, else False 
 */
bool DisableBatteryHeatersRequest() {
    std::cout << "Turning off Battery Heaters\n";
    return true;
}

/**
 * Enable the ADRV 9361. The ADRV 9361 is on the Always On Rail with
 * a duty cycle of 1.0
 * 
 * @param[void]
 * @return True if ADRV 9361 enables, else False 
 */
bool EnableADRV9361Request() {
    std::cout << "Turning on ADRV 9361\n";
    return true;
}

/**
 * Disable the ADRV 9361.
 * 
 * @param[void]
 * @return True if ADRV 9361 disables, else False 
 */
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

bool EnableCameraRequest() {
    std::cout << "Turning on Camera\n";
    return true;
}

bool DisableCameraRequest() {
    std::cout << "Turning off Camera\n";
    return true;
}

bool EnableXBandReceiveRequest() {
    std::cout << "Turning on X-Band Comms Receive\n";
    return true;
}

bool DisableXBandReceiveRequest() {
    std::cout << "Turning off X-Band Comms Receive\n";
    return true;
}

bool EnableXBandTransmitRequest() {
    std::cout << "Turning on X-Band Comms Transmit\n";
    return true;
}

bool DisableXBandTransmitRequest() {
    std::cout << "Turning off X-Band Comms Transmit\n";
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
