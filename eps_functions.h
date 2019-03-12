#ifndef EPS_FUNCTIONS_H_
#define EPS_FUNCTIONS_H_

#include <string>

/**
 * @file eps_functions.h
 * This header file includes all routines for enabling and disabling all Components
 * in the CubeSAT. Additionally, the class Component is designed to help the user grab
 * information of the hardware, including it's name, duty cycle, typical power (watts), 
 * and whether it is enabled or not. Finally, you are also able to get the current power
 * all of the hardware is using as well as getting the energy the batteries have left
 * 
 * @author floshosho
 * /

/*
NOTE: It would be convenient if the EPS can check how much power
each piece of hardware is currently using.

TASKS: 

- Make an isPowerAvailable function to see if we can turn on a specific
hardware. Check the CURRENT_POWER_USAGE,the battery has enough power to 
support this new incoming hardware, return true, otherwise return false.

- When XBand Comms transmit is on, EPS Overhead, Battery Heaters, ADRV, Magnetometer,
 UHF Receive, must all be on

 - When XBand Comms receive is on, EPS Overhead, Battery Heaters, ADRV, UHF Receive
*/

class Component {
 private:
    std::string name;
    float typical_power;
    float duty_cycle;
    bool enabled = false;
 public:
    Component(std::string name, float duty_cycle, float typical_power);
    ~Component() {}
    std::string getName();
    float getTypicalPower();
    float getDutyCycle();
    bool isEnabled();
    void setEnabled(bool boolean);
};

extern Component *eps_overhead;
extern Component *battery_heaters;
extern Component *adrv_9361;
extern Component *fss;
extern Component *css;
extern Component *magnetometer;
extern Component *magnetorquer;
extern Component *uhf_rx;
extern Component *uhf_tx;
extern Component *xband_rx;
extern Component *xband_tx;
extern Component *camera;
extern float CurrentPowerUsage;


float getCurrentPowerUsage();
float getUpdatedBatteryEnergy();
bool isPowerAvailable(float incoming_hardware_power);
void PurgeComponents();
bool EnableESPOverheadRequest();
bool DisableEPSOverheadRequest();
bool EnableBatteryHeatersRequest();
bool DisableBatteryHeatersRequest();
bool EnableADRV9361Request();
bool DisableADRV9361Request();
bool EnableFineSunSensorRequest();
bool DisableFineSunSensorRequest();
bool EnableCoarseSunSensorRequest();
bool DisableCoardSunSensorRequest();
bool EnableMagnetometerRequest();
bool DisableMagnetometerRequest();
bool EnableMagnetorquersRequest();
bool DisableMagnetorquersRequest();
bool EnableCameraRequest();
bool DisableCameraRequest();
bool EnableUHFRecieveRequest();
bool DisableUHFRecieveRequest();
bool EnableUHFTransmitRequest();
bool DisableUHFTransmitRequest();
bool EnableXBandReceiveRequest();
bool DisableXBandReceiveRequest();
bool EnableXBandTransmitRequest();
bool DisableXBandTransmitRequest();
#endif  // EPS_FUNCTIONS_H_
