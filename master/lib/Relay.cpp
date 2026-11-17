#include "Relay.h"

Relay::Relay(uint8_t relayPin, uint8_t errorPin)
    : relayPin(relayPin), errorPin(errorPin)
{
    pinMode(relayPin, OUTPUT);
    pinMode(errorPin, INPUT);
}

void Relay::TurnOn()
{
    digitalWrite(relayPin, HIGH);
}

void Relay::TurnOff()
{
    digitalWrite(relayPin, LOW);
}

bool Relay::GetRequiredState()
{
    return digitalRead(relayPin) == HIGH;
}

bool Relay::GetErrorPinState()
{
    return digitalRead(errorPin) == HIGH;
}

bool Relay::HasError()
{
    return GetRequiredState() && GetErrorPinState();
}
