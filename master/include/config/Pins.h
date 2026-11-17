#pragma once
#include <cstdint>

namespace Pins
{
    // Relays
    constexpr uint8_t BoilerRelay = 16;
    constexpr uint8_t Pump1Relay = 14;
    constexpr uint8_t Pump2Relay = 27;

    // Relay Error detection
    constexpr uint8_t BoilerRelayError = 34;
    constexpr uint8_t Pump1RelayError = 36;
    constexpr uint8_t Pump2RelayError = 39;

    // Inputs
    constexpr uint8_t Demand1NP = 4;
    constexpr uint8_t Demand2NP = 35;

    // Status LED
    constexpr uint8_t BoilerRunningLED = 18;
    constexpr uint8_t BoilerIdleLED = 19;
    constexpr uint8_t ErrorLED = 2;

    //Buttons
    constexpr uint8_t ButtonL1 = 23;
    constexpr uint8_t ButtonL2 = 5;
    constexpr uint8_t ButtonR1 = 13;
    constexpr uint8_t ButtonR2 = 12;

    // OLED Display
    constexpr uint8_t DisplaySDA = 25;
    constexpr uint8_t DisplaySCL = 26;
}