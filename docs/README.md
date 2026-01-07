# Line Follower Robot

This repository contains the hardware and software for a line-following robot based on the ESP32 platform.
The project was developed iteratively, starting from very simple motor-control boards and gradually evolving into a complete robot designed for further experimentation and improvement.

---

## Project Overview

- **Microcontroller:** ESP32-S3-WROOM-1
- **Motors:** DC motors (up to 12 V)
- **Motor Driver:** TB6612FNG
- **Sensors:** QRD1114 reflective IR sensors

The main goal of the project is to build a reliable and understandable line-following robot while keeping the hardware and software modular and easy to modify.

---

## How It Started

The project began with simple **ESP-based prototype boards** whose only purpose was to verify basic motor control.

The earliest versions were essentially just **ESP32 boards capable of driving DC motors**, without sensors or any control algorithm.
These prototypes used the **L9110 motor driver** and served mainly for learning how the ESP32 behaves in real hardware conditions.

Later, the project moved to a more complete design using the **L293D motor driver**, which made it possible to build the first fully functional robot.

These early boards established the foundation for all later hardware and software revisions.

---

## Hardware Revisions

The project went through several hardware versions.
Only Revision C is actively used today; earlier versions mainly served as learning steps.

Across all hardware versions, the project consistently uses **QRD1114 reflective IR sensors**.
Keeping the same sensor type made it easier to compare different revisions and focus on layout and software improvements instead of changing components.

---

### V0.1 – V0.3 (Base Board Prototypes)

Early prototype boards focused purely on motor control.

Purpose:
- Verify ESP32 motor control
- Test basic power distribution and I/O

Specifications:
- **MCU:** ESP32-S3-WROOM-1
- **Motor driver:** L9110
- **Motors:** Random DC motors (3–6 V)
- **Sensors:** Not implemented

Additional features:
- Status LED
- Programmable buttons

These versions were not complete robots, but they were crucial for early testing and experimentation.

---

### V1.0 (First Functional Robot)

V1.0 was the **first fully functional line-following robot**.
All later revisions are conceptually based on this version.

Specifications:
- **MCU:** ESP32-S3-WROOM-1
- **Motor driver:** L293D
- **Motors:** N20, 1000 RPM, 6 V
- **Sensors:** QRD1114 (9×)

Additional features:
- Status LED
- Programmable buttons
- MPU-6050 socket (functional)
- Downforce fan (later abandoned after real-world testing)

This version validated the overall robot architecture and control concept.

---

### Revision B (Design Only)

Revision B was a design-only iteration that was never manufactured.

Planned specifications:
- **MCU:** ESP32-S3-WROOM-1
- **Motor driver:** L293D
- **Motors:** N20, 2000 RPM, 6 V
- **Sensors:** QRD1114 (9×)

Planned additional features:
- Status LED
- Programmable buttons
- MPU-6050 socket
- I2C OLED display socket
- Connector for an external master power switch  
  (currently shorted when not used)

This revision was scrapped because it did not provide enough benefit compared to its complexity.

---

### Revision C (Latest)

Revision C is the current and actively used hardware version.

Specifications:
- **MCU:** ESP32-S3-WROOM-1
- **Motor driver:** TB6612FNG
- **Motors:** N20, 3000 RPM, 6–12 V
- **Sensors:** QRD1114 (11×)

Additional features:
- Status LED
- Programmable buttons
- MPU-6050 socket
- I2C OLED display socket
- Connector for an external master power switch  
  (currently shorted, prepared for competition rules)

Revision C is considered stable and serves as the final PCB platform.

---

## Software

- Written in Arduino-style C++ for ESP32
- Uses a **PD control algorithm** for line following
- Clear separation between sensor reading, control logic, and motor output

The software is structured to allow easy tuning and future feature expansion.

---

## Current Goal

- **Tune the PD control algorithm as much as possible**
  - Improve stability in turns
  - Reduce oscillations
  - Achieve consistent behavior on different surfaces

---

## Long-Term Goals

- **Wireless communication using ESP-NOW**
- **Implementation of the MPU-6050**
  - Orientation and motion data
  - Possible use for improved control or diagnostics

