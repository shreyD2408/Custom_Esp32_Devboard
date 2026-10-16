# SD2408 Devboard V1

This project is a custom ESP32-S3 development board designed for robotics and embedded systems. It integrates two DRV8833 motor drivers, an MPU6050 accelerometer and gyroscope, a MAX98357A audio amplifier, and connections for up to six servos. It also includes USB-C programming, power inputs, and accessible GPIO, ADC, and I2C pins for connecting external components.

The goal is to combine commonly used robotics components into one board, reducing external wiring and making prototyping easier. This project is part of Hack Club's Half Life program, where I am developing my PCB design and assembly skills using KiCad.
# Features

This custom board will feature an ESP32-S3-MINI-1 module as the microcontroller, 2 DRV8833 Motor Drivers, which allow a total of 4 motor inputs, a USB-C connector for programming and power input; alternatively, you can use the 5v terminal block for power input. This board also supports 3 5V and GND outputs for external components. I2C, ADC and GPIO pins are also available on the board via pin headers. ADC pins can be used as GPIO pins. The MPU6050 6-axis gyroscope and accelerometer, and the built-in MAX98357A audio amplifier may be programmed to be used. Separate servo connectors are also supported. It can have up to 6 servos connected at the same time (6 sets of 01x03 pin headers). 

I am designing and building this board as a part of the Hack Club Half Life program to develop my skills with circuit design and assembly using KiCad.

Purpose: To provide an all-in-one development board for robotics projects by integrating motor control, servo connections, motion sensing, audio output, and power distribution.
Why it exists: To reduce the need for separate modules and complicated wiring while gaining hands-on experience with PCB design, circuit development, and hardware assembly using KiCad.

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

