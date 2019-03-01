#include <iostream>
#include "./eps_functions.h"

using std::cin;
using std::cout;
using std::endl;

const float kMaxTotalPower = 26.0000;
const float kBatteryEnergyCapactiy = 38.5;

// This global variable keeps track of the current power being used in real-time
float CurrentPowerUsage = 0;

// NOTE: One satelite cycle is appromixately 92 min/5520 sec

void TestAllStubFunctions();

int main() {
    cout << "The EPS sudocode says Hello! Starting function diagnostics...\n\n";
    TestAllStubFunctions();
    cout << "\n\n...Finished function diagnostics.\n";
    return 1;
}

void TestAllStubFunctions() {
    cout << "Current Power Usage: " << getCurrentPowerUsage() << endl;
    CurrentPowerUsage += 10;
    isPowerAvailable(20);
    cout << "Current Power Usage: " << getCurrentPowerUsage() << endl;
    CurrentPowerUsage += 25;
    isPowerAvailable(15);
    getUpdatedBatteryEnergy();
    EnableESPOverheadRequest();
    DisableEPSOverheadRequest();
    EnableBatteryHeatersRequest();
    DisableBatteryHeatersRequest();
    EnableCameraRequest();
    DisableCameraRequest();
    EnableADRV9361Request();
    DisableADRV9361Request();
    EnableFineSunSensorRequest();
    DisableFineSunSensorRequest();
    EnableCoarseSunSensorRequest();
    DisableCoardSunSensorRequest();
    EnableMagnetometerRequest();
    DisableMagnetometerRequest();
    EnableMagnetorquersRequest();
    DisableMagnetorquersRequest();
    EnableUHFRecieveRequest();
    DisableUHFRecieveRequest();
    EnableUHFTransmitRequest();
    DisableUHFTransmitRequest();
    EnableXBandReceiveRequest();
    EnableXBandReceiveRequest();
}
