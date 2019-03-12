## EPS-System

This code defines a handy API used for the EPS-System in the CubeSat. The Component class
is meant to be a class that helps the user keep track of each component in the 
satelite. There are subroutines to Enable and Disable each piece of hardware and functions that check for power availability, battery power, etc.

Currently, this API is in it's early alpha, meaning that most of the crucial
functions are stub functions. These will be updated respectively once we get a working
EPS. (See "Running the Tests" to get a brief description on envoking this API)

# Prerequisites

To run the eps_skeleton.cpp, you must have:

- GNU Make 4.1 Built for x86_64-pc-linux-gnu
- g++ (Ubuntu 7.3.0-27ubuntu1~18.04) 7.3.0

# How to Run the Stub Functions

You can run the program by simply calling these commands while in the EPS-System
directory:

```
florens@computer:~/Desktop/EPS-System$ make
g++ -c eps_skeleton.cpp
g++ -c eps_functions.cpp
g++ eps_skeleton.o  eps_functions.o -o eps_skeleton

florens@computer:~/Desktop/EPS-System$ ./eps_skeleton 
```
Sample output:

```
The EPS sudocode says Hello! Starting function diagnostics...

Current Power Usage: 0
This function gets the current battery energy
ERROR: Hardware will exceed the current amount of power the battery has.
Current Power Usage: 10
This function gets the current battery energy
ERROR: Hardware will exceed the current amount of power the battery has.
This function gets the current battery energy
Turning on EPS Overhead
Turning off EPS Overhead
Turning on Battery Heaters
Turning off Battery Heaters
Turning on ADRV 9361
Turning of ADRV 9361
Turning on Fine Sun Sensor
Turning off Fine Sun Sensor
Turning on Coarse Sun Sensor
Turning off Coarse Sun Sensor
Turning on Magnetometer
Turning off Magnetometer
Turning on Magnetorquers
Turning off Magnetorquers
Turning on UHF Recieve
Turning off UHF Receive
Turning on Camera
Turning off Camera
Turning on X-Band Comms Receive
Turning off X-Band Comms Receive
Turning on X-Band Comms Transmit
Turning off X-Band Comms Transmit
Turning on UHF Transmit
Turning off UHF Transmit


...Finished function diagnostics.
```
# Additional Notes

The specifics of how each function works is documented in the eps_functions.cpp
file itself.