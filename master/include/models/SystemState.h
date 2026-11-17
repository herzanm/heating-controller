#pragma once

struct CircuitState
{
    bool requestedHeating = false;
    bool relayState = false;
};

struct SystemState
{
    // Inputs
    bool demand1NP = false;
    bool demand2NP = false;

    // Outputs
    bool boilerRelay = false;
    bool pump1Relay = false;
    bool pump2Relay = false;

    // Slave
    bool slaveConnected = false;

    CircuitState circuitBedroom;
    CircuitState circuitKidsroom;
    CircuitState circuitOffice;
    CircuitState circuitBathroom;

    // System
    bool wifiConnected = false;

    unsigned long uptimeSeconds = 0;
};