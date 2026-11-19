# Hardware Documentation

---

# MASTER

## Controller

ESP32 DevKit

Responsibilities:

- Heating logic
- Boiler control
- Pump control
- User interface
- Communication

---

## Inputs

### Ground Floor Heating Demand

Signal Source:

Thermostat receiver

Function:

Indicates heating demand from 1NP.

---

### Upper Floor Heating Demand

Signal Source:

KL08 controller

Function:

Indicates heating demand from 2NP.

---

## Outputs

### Boiler Relay

Function:

Starts boiler operation.

---

### Pump 1 Relay

Function:

Controls ground floor circulation pump.

---

### Pump 2 Relay

Function:

Controls upper floor circulation pump.

---

## User Interface

### OLED Display

Display Type:

SSD1306

Connection:

I2C

Pins:

- SDA = GPIO25
- SCL = GPIO26

---

### Keypad

Buttons:

- UP
- DOWN
- OK
- BACK

Configuration:

2x2 matrix keypad

---

## Status LEDs

Current LEDs:

- Boiler ON
- Boiler OFF
- Error

Future:

- WiFi status
- Slave status

---

# SLAVE

## Controller

ESP32-C3 SuperMini

Responsibilities:

- Relay switching
- Feedback monitoring

---

## Relay Outputs

Relay 1

Circuit Control

---

Relay 2

Circuit Control

---

Relay 3

Circuit Control

---

Relay 4

Circuit Control

---

## Feedback Inputs

Feedback 1

Relay state verification

---

Feedback 2

Relay state verification

---

Feedback 3

Relay state verification

---

Feedback 4

Relay state verification

---

# Communication

Protocol:

ESP-NOW

Topology:

MASTER
↔
SLAVE

---

# Pin Definitions

Source of truth:

```cpp
Pins.h
```

This document does not duplicate pin assignments.

Pins must only be maintained in code.