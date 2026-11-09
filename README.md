# SD2408 Devboard V1

When designing compact mobile robots, such as miniature rovers, self-balancing walkers, or desktop mecanum platforms—builders almost universally hit a frustrating physical bottleneck: the "breadboard jungle." Connecting an ESP32 microcontroller to external motor drivers, motion sensors, audio amplifiers, and servo breakout boards usually requires a rats' nest of jumper wires, perfboards, and loose cables. Every vibration from a motor risks shaking a loose DuPont connector loose, leading to intermittent power faults, debugging nightmares, and fragile hardware.

This project was built to solve that exact pain point from the ground up: an all-in-one, purpose-built development board that integrates every essential subsystem needed for intelligent, agile robotics onto a single, robust printed circuit board.

# How it Works

1. ESP32-S3-MINI-1: Processes information, reads data, and sends data to different parts of the board through firmware.
2. Motor Drivers: Control power and polarity of the brushed DC motors using either the USB-C power or external 5V input.
3. Four motor terminal connectors: Provide connection points for the DC motors for intended motor configuration.
4. Power Output Points: Designated 5V and GND power outputs for external components.
5. MPU6050: Measures tilt in radians (or if converted, degrees), and acceleration.
6. Audio output: Allows a compatible speaker to produce sound through the board's audio circuitry.

The components are connected through a custom-designed schematic and PCB layout. The schematic defines the electrical connections, while the PCB layout determines where components sit and how electrical signals travel through copper traces.

# Schematic

The schematic shows the electrical connection between all built-in components. Editable schematic available in the **hardware** folder.

<img width="654" height="433" alt="Screenshot 2026-10-11 180749" src="https://github.com/user-attachments/assets/3cf2e48a-f9ac-4b76-a35c-27f7b97a5e68" />

# PCB Layout

<img width="481" height="437" alt="layout" src="https://github.com/user-attachments/assets/74dac37f-c405-4f01-b9f5-4ef9e2311e8a" />

# 3D Model

The 3D Model shows the physical placement of components, copper traces, and connectors. Editable 3D Model available in the **hardware** folder.

<img width="522" height="450" alt="Screenshot 2026-10-11 181055" src="https://github.com/user-attachments/assets/0acd19b7-b62b-4fac-8f40-1f6f9f6364cc" />

# How to use

Connect the board to a computer through USB-C to program the ESP32-S3 using the Arduino IDE or ESP-IDF. Upload firmware onto the board provided in "firmware" folder for basic features. Firmware can then be used to control motors and servos, read motion data from the MPU6050, and play audio through the MAX98357A amplifier.

External components can be connected through the dedicated motor terminals, servo headers, power outputs, and GPIO, ADC, and I2C headers. Alternatively, a suitable external 5V supply can be connected through the power terminal block. Verify the board's power requirements before connecting motors or servos.


## Bill of Materials (BOM)

| Part | Purpose | Qty | Unit Cost | Total | Vendor |
|---|---|---:|---:|---:|---|
| Panasonic Push Button | User input, BOOT/RESET | 5 | $0.38 | $1.90 | LCSC |
| Ceramic 1µF Capacitor | Decoupling | 50 | $0.01 | $0.50 | LCSC |
| Ceramic 2.2µF Capacitor | Decoupling | 20 | $0.02 | $0.40 | LCSC |
| Ceramic 10µF Capacitor | Filtering | 20 | $0.03 | $0.60 | LCSC |
| Ceramic 100nF Capacitor | Decoupling | 50 | $0.01 | $0.50 | LCSC |
| Ceramic 10nF Capacitor | Filtering | 50 | $0.01 | $0.50 | LCSC |
| Ceramic 220nF Capacitor | Filtering | 2 | $0.33 | $0.66 | LCSC |
| USB-C Connector | Power and programming | 20 | $0.08 | $1.60 | LCSC |
| ESD Protection Diode | Surge protection | 20 | $0.03 | $0.60 | LCSC |
| Fuse | Overcurrent protection | 5 | $0.09 | $0.45 | LCSC |
| MAX98357A | Audio amplifier | 1 | $1.33 | $1.33 | LCSC |
| DRV8833PW | Motor driver | 2 | $1.65 | $3.30 | LCSC |
| LM1117 | 5V to 3.3V regulator | 5 | $0.18 | $0.90 | LCSC |
| USBLC6-2SC6 | USB ESD protection | 10 | $0.05 | $0.50 | LCSC |
| 10K Resistor | Passive component | 100 | $0.01 | $1.00 | LCSC |
| 2.2K Resistor | Passive component | 100 | $0.01 | $1.00 | LCSC |
| 5.1K Resistor | Passive component | 100 | $0.01 | $1.00 | LCSC |
| 1M Resistor | Passive component | 100 | $0.01 | $1.00 | LCSC |
| 1K Resistor | Passive component | 100 | $0.01 | $1.00 | LCSC |
| ESP32-S3-MINI-1 | Main MCU and Wi-Fi | 1 | $4.76 | $4.76 | LCSC |
| 1×2 Terminal Block | Power and motor input | 5 | $0.10 | $0.50 | LCSC |
| 1×3 Terminal Block | Power output | 5 | $0.35 | $1.75 | LCSC |
| LED | Power indicator | 100 | $0.01 | $1.00 | LCSC |
| Custom PCB | Component mounting | 5 | $2.60 | $13.00 | JLCPCB |

**Links available in BOM.md**

### Cost Summary

| Item | Cost |
|---|---:|
| Parts Subtotal | $39.75 |
| Tax & Shipping | $17.36 |
| **Grand Total** | **$57.11 USD** |

**Disclaimer** - Quantities are not exact as LCSC sells in bulk. 

