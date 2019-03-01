#ifndef EPS_FUNCTIONS_H_
#define EPS_FUNCTIONS_H_

/*
NOTE: It would be convenient if the EPS can check how much power
each piece of hardware is currently using.

TASKS: 

- Make TURN_ON and TURN_OFF functions for all hardware that
correctly increments the CURRENT_POWER_USAGE and decrements it.

- Make an isPowerAvailable function to see if we can turn on a specific
hardware. Check the CURRENT_POWER_USAGE,the battery has enough power to 
support this new incoming hardware, return true, otherwise return false.

- Make an updateCurrentBatteryPower function
*/

extern float CurrentPowerUsage;
float getCurrentPowerUsage();
float getUpdatedBatteryEnergy();
bool isPowerAvailable(float incoming_hardware_power);
bool EnableESPOverheadRequest();
bool DisableEPSOverheadRequest();
bool EnableBatteryHeatersRequest();
bool DisableBatteryHeatersRequest();
bool EnableCameraRequest();
bool DisableCameraRequest();
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
bool EnableUHFRecieveRequest();
bool DisableUHFRecieveRequest();
bool EnableUHFTransmitRequest();
bool DisableUHFTransmitRequest();
bool EnableXBandReceiveRequest();
bool EnableXBandReceiveRequest();
#endif  // EPS_FUNCTIONS_H_
