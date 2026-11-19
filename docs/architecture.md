# Heating Controller Architecture

## Purpose

Heating Controller is a custom ESP32-based heating control system.

The goal is to create a reliable, maintainable and fault-tolerant heating control unit that can:

- control boiler operation
- control heating circulation pumps
- monitor heating demands
- support manual override mode
- provide local OLED UI
- provide future web/mobile interface
- support distributed I/O using ESP-NOW

The system must continue operating even if WiFi or Internet become unavailable.

---

# Hardware Overview

## MASTER Unit

Hardware:

- ESP32 DevKit
- SSD1306 OLED display
- 2x2 keypad
- Boiler relay
- Pump 1 relay
- Pump 2 relay
- Status LEDs
- WiFi connection
- ESP-NOW communication

Responsibilities:

- decide when heating should run
- control boiler
- control pumps
- monitor demand inputs
- communicate with slave units
- provide local GUI
- provide future remote access

MASTER contains all business logic.

---

## SLAVE Unit

Hardware:

- ESP32-C3 SuperMini
- 4-channel relay board
- 4 feedback inputs

Responsibilities:

- relay switching
- relay status reporting
- receive commands from MASTER

SLAVE contains no heating logic.

SLAVE acts as a remote I/O module only.

---

# Heating System

## Ground Floor (1NP)

One thermostat controls the entire floor.

Signal flow:

Thermostat
→ Receiver
→ MASTER demand input

Logic:

Demand active:

- Boiler ON
- Pump 1 ON

Demand inactive:

- Boiler OFF (if no other demand exists)
- Pump 1 OFF

---

## Upper Floor (2NP)

Four independent heating circuits.

Each room thermostat controls its own circuit through KL08.

MASTER receives overall heating demand from KL08.

Logic:

Demand active:

- Boiler ON
- Pump 2 ON

Demand inactive:

- Boiler OFF (if no other demand exists)
- Pump 2 OFF

---

# Boiler Logic

Current logic:

```cpp
boiler = demand1NP || demand2NP;
```

Meaning:

If any floor requests heating:

```cpp
boiler = true;
```

Otherwise:

```cpp
boiler = false;
```

---

# System Modes

## AUTO

Default operating mode.

Heating is controlled exclusively by actual thermostats.

MASTER:

- monitors inputs
- controls outputs

MASTER does not override thermostat decisions.

---

## MANUAL

Manual service mode.

User may control:

- boiler
- pump 1
- pump 2
- individual 2NP circuits

Purpose:

- testing
- maintenance
- diagnostics

---

# Manual Mode Timeout

Manual mode automatically expires.

Current timeout:

```cpp
14400 seconds
```

(4 hours)

Reason:

Prevent accidental long-term manual heating.

---

# Fault Detection

Relays have feedback inputs.

Every relay contains:

- control output
- feedback input

Future fault detection should compare:

```cpp
requested state
```

versus

```cpp
actual relay state
```

Example:

Requested = ON

Actual = OFF

→ relay fault

---

# Communication Architecture

MASTER ↔ SLAVE

Protocol:

```text
ESP-NOW
```

Reason:

- independent of WiFi infrastructure
- low latency
- high reliability
- no router dependency

---

# WiFi Usage

WiFi is used only for:

- web interface
- monitoring
- remote control

Heating operation must not depend on WiFi.

System must continue operating when:

- WiFi is disconnected
- Internet is unavailable
- router is offline

---

# Software Architecture

## MASTER

```text
master/
│
├── src/
│
├── include/
│   ├── config/
│   └── models/
│
└── lib/
```

---

## SLAVE

```text
slave/
│
├── src/
│
├── include/
│   └── config/
│
└── lib/
```

---

# Configuration

Hardware definitions belong only in:

```cpp
Pins.h
```

Pin numbers must never be hardcoded elsewhere.

---

# Current Models

## CircuitState

```cpp
struct CircuitState
{
    bool requestedHeating = false;
    bool relayState = false;
};
```

requestedHeating

Represents heating request.

relayState

Represents actual measured output state.

---

## SystemState

Contains runtime information only.

Examples:

- demand states
- relay states
- connection status
- uptime

SystemState must never contain configuration.

---

## SystemConfig

Contains configurable values only.

Examples:

- timeout values
- display settings
- WiFi credentials
- future user settings

SystemConfig must never contain runtime state.

---

# OLED GUI

## Home Screen

```text
11:25

AUTO
WiFi     OK
SLAVE    OK

KOTEL    ON
1NP      ON
2NP      OFF
```

---

## Main Menu

```text
> STATUS
  MANUAL
  SETTINGS
```

---

## Manual Menu

```text
Boiler
Pump 1
Pump 2

Circuit 1
Circuit 2
Circuit 3
Circuit 4
```

---

# Design Principles

1. MASTER contains all system intelligence.
2. SLAVE acts only as remote I/O.
3. Reliability is more important than optimization.
4. Prefer clarity over abstraction.
5. Avoid premature optimization.
6. Avoid unnecessary frameworks.
7. Use classes for hardware abstractions.
8. Keep configuration separate from runtime state.
9. Hardware must continue operating without Internet.
10. Every architectural decision should favor maintainability and serviceability.