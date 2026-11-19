# Roadmap

This document contains the planned development roadmap for the Heating Controller project.

---

# Phase 1 - Foundation

Goal:

Create stable software architecture and hardware abstraction layers.

Status:

✅ In Progress

Tasks:

- [x] Create GitHub repository
- [x] Setup PlatformIO
- [x] Setup MASTER project
- [x] Setup SLAVE project
- [x] Create architecture documentation
- [x] Create SystemState model
- [x] Create SystemConfig model
- [x] Create SystemMode definitions
- [x] Create pin definitions
- [ ] Implement Relay class
- [ ] Implement relay feedback monitoring
- [ ] Create hardware tests

---

# Phase 2 - Heating Core

Goal:

Create a fully working heating controller without UI.

Tasks:

- [ ] HeatingController class
- [ ] Boiler control logic
- [ ] Pump control logic
- [ ] Demand signal monitoring
- [ ] Manual mode logic
- [ ] Manual mode timeout
- [ ] Fault detection
- [ ] Runtime diagnostics

Result:

System can fully operate heating hardware.

---

# Phase 3 - OLED User Interface

Goal:

Create local user interface.

Tasks:

- [ ] Display abstraction
- [ ] Screen manager
- [ ] Main screen
- [ ] Status screen
- [ ] Manual mode screen
- [ ] Settings screen
- [ ] Error screen
- [ ] Navigation framework
- [ ] Keypad driver

Result:

System is fully operable without PC.

---

# Phase 4 - Slave Communication

Goal:

Integrate remote relay controller.

Tasks:

- [ ] ESP-NOW driver
- [ ] Communication protocol
- [ ] Discovery mechanism
- [ ] Slave status monitoring
- [ ] Circuit control
- [ ] Circuit diagnostics
- [ ] Connection watchdog

Result:

MASTER can control all heating circuits.

---

# Phase 5 - Diagnostics

Goal:

Improve reliability.

Tasks:

- [ ] Relay diagnostics
- [ ] Pump diagnostics
- [ ] Communication diagnostics
- [ ] Event logging
- [ ] Fault history
- [ ] System health monitoring

Result:

Failures become visible and traceable.

---

# Phase 6 - Web Interface

Goal:

Provide remote monitoring.

Tasks:

- [ ] WiFi manager
- [ ] Embedded web server
- [ ] Authentication
- [ ] Dashboard
- [ ] Manual control page
- [ ] Settings page
- [ ] Status API

Result:

System can be monitored remotely.

---

# Phase 7 - Mobile Integration

Goal:

Support mobile control.

Candidates:

- Web App
- Home Assistant
- MQTT
- Dedicated App

Status:

Research required.

---

# Long-Term Ideas

Future possibilities:

- Heating schedule
- Outside temperature integration
- Energy consumption tracking
- Multiple slave units
- OTA updates
- MQTT support
- Home Assistant integration
- Push notifications
- Multi-user administration