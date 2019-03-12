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
 * Set the Component Enabled status On or Off
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
 * Enable EPS Overhead. EPS Overhead should always stay enabled after
 * this call
 * 
 * @param[void]
 * @return True if EPS Overhead enables, else False
 */
bool EnableESPOverheadRequest() {
    std::cout << "Turning on EPS Overhead\n";
    return true;
}

/**
 * Disable EPS Overhead. This most likely would not be called, except for
 * testing purposes
 * 
 * @param[void]
 * @return True when EPS Overhead disables, else False
 */
bool DisableEPSOverheadRequest() {
    std::cout << "Turning off EPS Overhead\n";
    return true;
}

/**
 * Enable the Battery Heaters.
 * 
 * @param[void]
 * @return True if Battery Heaters enable, else False 
 */
bool EnableBatteryHeatersRequest() {
    std::cout << "Turning on Battery Heaters\n";
    return true;
}

/**
 * Disable the Battery Heaters. This most likely would not be called, except for
 * testing purposes
 * 
 * @param[void]
 * @return True if Battery Heaters disable, else False 
 */
bool DisableBatteryHeatersRequest() {
    std::cout << "Turning off Battery Heaters\n";
    return true;
}

/**
 * Enable the ADRV 9361. The ADRV 9361 should always stay
 * enabled after this call
 * 
 * 
 * @param[void]
 * @return True if ADRV 9361 enables, else False 
 */
bool EnableADRV9361Request() {
    std::cout << "Turning on ADRV 9361\n";
    return true;
}

/**
 * Disable the ADRV 9361. This most likely would not be called, except for
 * testing purposes
 * 
 * @param[void]
 * @return True if ADRV 9361 disables, else False 
 */
bool DisableADRV9361Request() {
    std::cout << "Turning of ADRV 9361\n";
    return true;
}

/**
 * Enable the Fine Sun Senor. Before enabling the Fine Sun Sensor, the EPS Overhead,
 * Battery Heaters, and ADRV 9361 must all be enabled. Additionally, this is called
 * once the Coarse Sun Sensor finishes it's job
 * 
 * @param[void]
 * @return True if Coarse Sun Sensor enables, else False 
 */
bool EnableFineSunSensorRequest() {
    std::cout << "Turning on Fine Sun Sensor\n";
    return true;
}

/**
 * Disable the Fine Sun Sensor. 
 * 
 * @param[void]
 * @return True if Fine Sun Sensor disables, else False 
 */
bool DisableFineSunSensorRequest() {
    std::cout << "Turning off Fine Sun Sensor\n";
    return true;
}

/**
 * Enable the Coarse Sun Senor. Before enabling the Coarse Sun Sensor, the EPS Overhead,
 * Battery Heaters, and ADRV 9361 must all be enabled.
 * 
 * @param[void]
 * @return True if Coarse Sun Sensor enables, else False 
 */
bool EnableCoarseSunSensorRequest() {
    std::cout << "Turning on Coarse Sun Sensor\n";
    return true;
}

/**
 * Disable the Coarse Sun Sensor. 
 * 
 * @param[void]
 * @return True if Coarse Sun Sensor disables, else False 
 */
bool DisableCoarseSunSensorRequest() {
    std::cout << "Turning off Coarse Sun Sensor\n";
    return true;
}

/**
 * Enable the Magnetometer. Before enabling the Magnetometer, EPS Overhead,
 * Battery Heaters, and ADRV9361 must all be enabled
 * 
 * @param[void]
 * @return True if Magnetometer enables, else False 
 */
bool EnableMagnetometerRequest() {
    std::cout << "Turning on Magnetometer\n";
    return true;
}

/**
 * Disable the Magnetometer.
 * 
 * @param[void]
 * @return True if Magnetometer disables, else False 
 */
bool DisableMagnetometerRequest() {
    std::cout << "Turning off Magnetometer\n";
    return true;
}

/**
 * Enable the Magnetorquers. Before enabling the Magnetorquers, EPS Overhead,
 * Battery Heaters, and ADRV9361 must all be enabled
 * 
 * @param[void]
 * @return True if Magnetorquers enable, else False 
 */
bool EnableMagnetorquersRequest() {
    std::cout << "Turning on Magnetorquers\n";
    return true;
}

/**
 * Disable the Magnetorquers.
 * 
 * @param[void]
 * @return True if Magnetorquers disable, else False 
 */
bool DisableMagnetorquersRequest() {
    std::cout << "Turning off Magnetorquers\n";
    return true;
}

/**
 * Enable the UHF Recieve. Before enabling the UHF Recieve, EPS Overhead,
 * Battery Heaters, and ADRV9361 must all be enabled
 * 
 * @param[void]
 * @return True if UHF Recieve enables, else False 
 */
bool EnableUHFRecieveRequest() {
    std::cout << "Turning on UHF Recieve\n";
    return true;
}

/**
 * Disable the UHF Receive.
 * 
 * @param[void]
 * @return True if UHF Recieve disables, else False 
 */
bool DisableUHFRecieveRequest() {
    std::cout << "Turning off UHF Receive\n";
    return true;
}

/**
 * Enable the Camera. Before enabling the camera, the Magnetorquers and Magnetometers
 * have to run before the camera in order to align the CubeSat with the sun. 
 * Additionally, this needs to be enabled before XBand Transmit
 * is enabled
 * 
 * @param[void]
 * @return True if Camera enables, else False 
 */
bool EnableCameraRequest() {
    std::cout << "Turning on Camera\n";
    return true;
}

/**
 * Disable the Camera. Most likely will be called shortly after the Camera
 * takes a picture and saves it.
 * 
 * @param[void]
 * @return True if Camera disables, else False 
 */
bool DisableCameraRequest() {
    std::cout << "Turning off Camera\n";
    return true;
}

/**
 * Enable the XBand Recieve. Before enabling the XBand Comms Recieve, EPS Overhead,
 * Battery Heaters, ADRV9361, must all be enabled. Additionally, the satelite must
 * be aligned before we set out to receive an XBand Recieve signal
 * 
 * @param[void]
 * @return True if XBand Recieve enables, else False 
 */
bool EnableXBandReceiveRequest() {
    std::cout << "Turning on X-Band Comms Receive\n";
    return true;
}

/**
 * Disable the XBand Recieve.
 * 
 * @param[void]
 * @return True if XBand Recieve disables, else False 
 */
bool DisableXBandReceiveRequest() {
    std::cout << "Turning off X-Band Comms Receive\n";
    return true;
}

/**
 * Enable the XBand Transmit. Before enabling the XBand Comms Transmit, EPS Overhead,
 * Battery Heaters, ADRV9361, Magnetometer, UHF Receive, and Camera must all be enabled
 * 
 * @param[void]
 * @return True if XBand Transmit enables, else False 
 */
bool EnableXBandTransmitRequest() {
    std::cout << "Turning on X-Band Comms Transmit\n";
    return true;
}

/**
 * Disable the XBand Transmit.
 * 
 * @param[void]
 * @return True if XBand Transmit disables, else False 
 */
bool DisableXBandTransmitRequest() {
    std::cout << "Turning off X-Band Comms Transmit\n";
    return true;
}

/**
 * Enable the UHF Transmit. Before enabling the UHF Transmit, EPS Overhead,
 * Battery Heaters, and ADRV9361 must all be enabled
 * 
 * @param[void]
 * @return True if UHF Transmit enables, else False 
 */
bool EnableUHFTransmitRequest() {
    std::cout << "Turning on UHF Transmit\n";
    return true;
}

/**
 * Disable the UHF Transmit.
 * 
 * @param[void]
 * @return True if UHF Transmit disables, else False 
 */
bool DisableUHFTransmitRequest() {
    std::cout << "Turning off UHF Transmit\n";
    return true;
}
