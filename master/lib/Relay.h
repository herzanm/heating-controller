#pragma once
#include <cstdint>

// Relay class controls a relay device using a specified pin and monitors its error state via an error pin.
// Usage: Instantiate with the relay control pin and error pin, then use TurnOn/TurnOff to control the relay.
class Relay
{
    private:
        uint8_t relayPin;
        uint8_t errorPin;
    public:
        Relay(uint8_t relayPin, uint8_t errorPin);
        void TurnOn();
        void TurnOff();
        bool GetRequiredState();
        bool GetErrorPinState();

        bool HasError();
}