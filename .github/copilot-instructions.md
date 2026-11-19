# Heating Controller Project Instructions

## Project Overview

This project is a custom heating controller system built with ESP32 devices.

The repository contains:

- MASTER unit (ESP32 DevKit)
- SLAVE unit (ESP32-C3 SuperMini)

The project uses:

- PlatformIO
- Arduino Framework
- ESP-NOW communication
- OLED Display (SSD1306)
- Relay control
- Web interface (planned)

---

## Development Philosophy

Act as a senior embedded software engineer.

Do not blindly agree with existing code or ideas.

Always review architecture decisions critically.

Prefer:

- simplicity
- maintainability
- reliability
- readability
- fault tolerance

Avoid overengineering.

Reliability is more important than clever code.

---

# Architecture

## MASTER

Responsibilities:

- heating logic
- boiler control
- pump control
- OLED GUI
- keypad handling
- web interface
- WiFi connectivity
- ESP-NOW communication

MASTER contains all system intelligence.

---

## SLAVE

Responsibilities:

- relay control
- circuit monitoring
- reporting status to MASTER

SLAVE must remain as simple as possible.

No heating decision logic belongs in SLAVE.

---

# Heating Logic

## Ground Floor (1NP)

A room thermostat controls heating demand.

If demand is active:

- Boiler ON
- Pump 1 ON

---

## Upper Floor (2NP)

Four heating circuits are managed through a KL08 controller.

MASTER monitors the KL08 demand signal.

If demand is active:

- Boiler ON
- Pump 2 ON

---

## Boiler Logic

If either floor requests heating:

```cpp
boiler = demand1NP || demand2NP;
```

If no floor requests heating:

```cpp
boiler = false;
```

---

# Modes

```cpp
enum class SystemMode
{
    Auto,
    Manual
};
```

## Auto

Normal operation.

Thermostats control heating.

MASTER only monitors and controls outputs.

## Manual

User can manually control:

- boiler
- pumps
- individual heating circuits

Manual mode automatically expires.

Current timeout:

```cpp
14400 seconds
```

(4 hours)

---

# Repository Structure

## Master

```text
master/
├── src/
├── include/
│   ├── config/
│   └── models/
└── lib/
```

## Slave

```text
slave/
├── src/
├── include/
│   └── config/
└── lib/
```

---

# Configuration

Pins are defined only in:

```cpp
config/Pins.h
```

Never hardcode pin numbers elsewhere.

---

# Models

## SystemState

Contains runtime state only.

Examples:

- demand signals
- relay states
- wifi status
- slave status
- uptime

Do not store configuration values here.

## SystemConfig

Contains configurable values only.

Examples:

- timeouts
- display settings
- WiFi credentials
- future user settings

Do not store runtime state here.

---

# Relay Design

Each relay contains:

- relay output pin
- feedback pin

Example:

```cpp
Relay boiler(
    Pins::BoilerRelay,
    Pins::BoilerRelayError
);
```

Future implementations should distinguish:

- requested state
- actual feedback state

to detect failures.

---

# Communication

MASTER and SLAVE communicate using ESP-NOW.

WiFi is used only for:

- web interface
- monitoring
- remote access

Heating must continue working even if:

- WiFi is disconnected
- Internet is unavailable
- router is offline

---

# Important Rules

1. MASTER contains all business logic.
2. SLAVE executes commands only.
3. Keep abstractions simple.
4. Prefer explicit code over clever code.
5. Avoid unnecessary frameworks.
6. Use classes for hardware abstractions.
7. Reliability is more important than optimization.
8. Review architecture decisions critically.
9. Do not duplicate configuration across files.
10. Always suggest better designs when appropriate.