// Copyright @SpaceHauc
#include <iostream>
#include "./eps_functions.h"

using std::cin;
using std::cout;
using std::endl;

const float kMaxTotalPower = 26.0000;
const float kBatteryEnergyCapactiy = 38.5;

Component *eps_overhead = new Component("EPS Overhead", 1.0, 0.26);
Component *battery_heaters = new Component("Battery Heaters", 0.4, 7.0);
Component *adrv_9361 = new Component("ADRV 9361", 1.0, 5.0);
Component *fss = new Component("Fine Sun Sensor", 0.3, 0.0066);
Component *css = new Component("Coarse Sun Sensor", 0.7, 0.01485);
Component *magnetometer = new Component("Magnetometer", 0.6, 0.099);
Component *magnetorquer = new Component("Magnetorquer", 0.6, 0.6);
Component *uhf_rx = new Component("UHF Receive", 1.0, 0.8);
Component *uhf_tx = new Component("UHF Transmit", 0.2, 8.0);
Component *xband_rx = new Component("XBands Receive", 0.5, 8.9447);
Component *xband_tx = new Component("XBands Transmit", 0.5, 8.8026);
// TODO(floshosho): duty cycle and typical power of camera is unclear
Component *camera = new Component("Camera", 0.0, 0.0);

// This global variable keeps track of the current power being used in real-time
float CurrentPowerUsage = 0;

void TestAllStubFunctions();

int main() {
    cout << "The EPS sudocode says Hello! Starting function diagnostics...\n\n";
    TestAllStubFunctions();
    cout << "\n\n...Finished function diagnostics.\n";
    PurgeComponents();
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
    EnableADRV9361Request();
    DisableADRV9361Request();
    EnableFineSunSensorRequest();
    DisableFineSunSensorRequest();
    EnableCoarseSunSensorRequest();
    DisableCoarseSunSensorRequest();
    EnableMagnetometerRequest();
    DisableMagnetometerRequest();
    EnableMagnetorquersRequest();
    DisableMagnetorquersRequest();
    EnableUHFRecieveRequest();
    DisableUHFRecieveRequest();
    EnableCameraRequest();
    DisableCameraRequest();
    EnableXBandReceiveRequest();
    DisableXBandReceiveRequest();
    EnableXBandTransmitRequest();
    DisableXBandTransmitRequest();
    EnableUHFTransmitRequest();
    DisableUHFTransmitRequest();
}