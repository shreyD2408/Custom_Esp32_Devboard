# SD2408 Devboard V1

I am designing a custom ESP32 development board featuring the ESP32-S3-MINI module for maximized GPIO pins. My goal is to combine electrical components such as power distribution, audio output, motor and servo control, and additional sensors into one board, minimizing the need to have external components.

# Features

This custom board will feature an ESP32-S3-MINI-1 module as the microcontroller, 2 DRV8833 Motor Drivers, which allow a total of 4 motor inputs, a USB-C connector for programming and power input; alternatively, you can use the 5v terminal block for power input. This board also supports 3 5V and GND outputs for external components. I2C, ADC and GPIO pins are also available on the board via pin headers. ADC pins can be used as GPIO pins. The MPU6050 6-axis gyroscope and accelerometer, and the built-in MAX98357A audio amplifier may be programmed to be used. Separate servo connectors are also supported. It can have up to 6 servos connected at the same time (6 sets of 01x03 pin headers). 

I am designing and building this board as a part of the Hack Club Half Life program to develop my skills with circuit design and assembly using KiCad.

# How it Works
