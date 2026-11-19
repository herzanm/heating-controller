# Heating Controller

Custom ESP32-based heating control system designed for floor heating installation management.

## Features

- Boiler control
- Heating pump control
- Multi-zone floor heating support
- OLED user interface
- Physical keypad navigation
- Manual and automatic operating modes
- ESP-NOW communication between controllers
- Relay feedback monitoring
- WiFi connectivity
- Future web and mobile interface

---

# Project Overview

The system consists of two independent controllers:

## MASTER

ESP32 DevKit

Responsibilities:

- heating logic
- boiler control
- pump control
- OLED display
- keypad navigation
- system monitoring
- WiFi connectivity
- ESP-NOW communication

The MASTER contains all decision-making logic.

---

## SLAVE

ESP32-C3 SuperMini

Responsibilities:

- remote relay control
- monitoring zone states
- reporting status back to MASTER

The SLAVE acts only as a remote I/O expansion module.

---

# Heating System

## Ground Floor (1NP)

Single thermostat controlled floor.

Heating request triggers:

- Boiler ON
- Pump 1 ON

---

## Upper Floor (2NP)

Four independent heating circuits controlled through a KL08 controller.

Heating request triggers:

- Boiler ON
- Pump 2 ON

---

# Communication

MASTER and SLAVE communicate using:

```text
ESP-NOW
```

Advantages:

- no router dependency
- low latency
- reliable local communication
- continues working without internet

---

# Operating Modes

## AUTO

Normal operating mode.

Heating is controlled by thermostats.

The controller only monitors and drives outputs.

---

## MANUAL

Service and diagnostic mode.

Allows manual control of:

- boiler
- pumps
- individual heating circuits

Manual mode automatically expires after a configurable timeout.

---

# Technologies

- ESP32
- ESP32-C3
- PlatformIO
- Arduino Framework
- ESP-NOW
- SSD1306 OLED
- GitHub
- GitHub Copilot

---

# Repository Structure

```text
heating-controller/
│
├── master/
│   ├── src/
│   ├── include/
│   └── lib/
│
├── slave/
│   ├── src/
│   ├── include/
│   └── lib/
│
├── docs/
│   └── architecture.md
│
└── .github/
    └── copilot-instructions.md
```

---

# Development Principles

1. Reliability over features
2. Simplicity over cleverness
3. MASTER contains all business logic
4. SLAVE executes commands only
5. No hardcoded pin numbers outside Pins.h
6. Configuration and runtime state must remain separated
7. System must continue operating without Internet access

---

# Current Status

🚧 Early development phase

Completed:

- Project architecture
- PlatformIO setup
- GitHub repository
- MASTER initialization
- SLAVE initialization
- Core models
- Relay abstraction design

Planned:

- HeatingController
- OLED GUI
- Menu navigation
- ESP-NOW protocol
- Manual control mode
- Relay diagnostic system
- Web interface
- Mobile access

---

# Documentation

Architecture documentation:

```text
docs/architecture.md
```

GitHub Copilot project instructions:

```text
.github/copilot-instructions.md
```

---

# License

Private project.

All rights reserved.