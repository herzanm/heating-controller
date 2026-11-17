#pragma once
#include <cstdint>

namespace Pins
{
    // Relays
    constexpr uint8_t CircuitBedroom = 1;
    constexpr uint8_t CircuitKidsRoom = 2;
    constexpr uint8_t CircuitOffice = 3;
    constexpr uint8_t CircuitBathroom = 4;

    // Relay Error detection
    constexpr uint8_t CircuitBedroomError = 5;
    constexpr uint8_t CircuitKidsRoomError = 6;
    constexpr uint8_t CircuitOfficeError = 7;
    constexpr uint8_t CircuitBathroomError = 8;
}