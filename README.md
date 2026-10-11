# SD2408 Devboard V1

I am designing a custom ESP32 development board featuring the ESP32-S3-MINI module for maximized GPIO pins. My goal is to combine electrical components such as power distribution, audio output, motor and servo control, and additional sensors into one board, minimizing the need to have external components.

# Features

This custom board will feature an ESP32-S3-MINI-1 module as the microcontroller, 2 DRV8833 Motor Drivers, which allow a total of 4 motor inputs, a USB-C connector for programming and power input; alternatively, you can use the 5v terminal block for power input. This board also supports 3 5V and GND outputs for external components. I2C, ADC and GPIO pins are also available on the board via pin headers. ADC pins can be used as GPIO pins. The MPU6050 6-axis gyroscope and accelerometer, and the built-in MAX98357A audio amplifier may be programmed to be used. Separate servo connectors are also supported. It can have up to 6 servos connected at the same time (6 sets of 01x03 pin headers). 

I am designing and building this board as a part of the Hack Club Half Life program to develop my skills with circuit design and assembly using KiCad.

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

"Reference","Qty","Value","DNP","Exclude from BOM","Exclude from Board","Exclude from Simulation","Exclude from Position Files","Footprint","Datasheet"
"SW3","1","USER_SW1","","","","","${EXCLUDE_FROM_POS_FILES}","Button_Switch_SMD:SW_SPST_EVQP2_ShortPushTravel_H2.1mm",""
"SW4","1","USER_SW2","","","","","${EXCLUDE_FROM_POS_FILES}","Button_Switch_SMD:SW_SPST_EVQP2_ShortPushTravel_H2.1mm",""
"C1,C19,C20","3","1u","","","","","${EXCLUDE_FROM_POS_FILES}","Capacitor_SMD:C_0201_0603Metric_Pad0.64x0.40mm_HandSolder",""
"C4,C11,C12","3","2.2u","","","","","${EXCLUDE_FROM_POS_FILES}","Capacitor_SMD:C_0201_0603Metric_Pad0.64x0.40mm_HandSolder",""
"C2,C13,C14","3","10u","","","","","${EXCLUDE_FROM_POS_FILES}","Capacitor_SMD:C_0402_1005Metric_Pad0.74x0.62mm_HandSolder",""
"C3,C5,C6,C7,C8,C17,C18","7","0.1u","","","","","${EXCLUDE_FROM_POS_FILES}","Capacitor_SMD:C_0402_1005Metric_Pad0.74x0.62mm_HandSolder",""
"C15,C16","2","0.01u","","","","","${EXCLUDE_FROM_POS_FILES}","Capacitor_SMD:C_1206_3216Metric_Pad1.33x1.80mm_HandSolder",""
"C9,C10","2","22u","","","","","${EXCLUDE_FROM_POS_FILES}","Capacitor_SMD:C_1825_4564Metric_Pad1.57x6.80mm_HandSolder",""
"J1","1","USB_C_Receptacle_USB2.0_16P","","","","","${EXCLUDE_FROM_POS_FILES}","Connector_USB:USB_C_Receptacle_HCTL_HC-TYPE-C-16P-01A","https://www.usb.org/sites/default/files/documents/usb_type-c.zip"
"D1,D2,D5,D6","4","ESD3.3","","","","","${EXCLUDE_FROM_POS_FILES}","Diode_SMD:D_SOD-923","https://www.onsemi.com/pub/Collateral/ESD9B-D.PDF"
"F1","1","Polyfuse 1A","","","","","${EXCLUDE_FROM_POS_FILES}","Fuse:Fuse_1206_3216Metric",""
"FB1","1","BLM21PG220","","","","","${EXCLUDE_FROM_POS_FILES}","Inductor_SMD:L_0805_2012Metric_Pad1.05x1.20mm_HandSolder",""
"D4","1","GREEN","","","","","${EXCLUDE_FROM_POS_FILES}","LED_SMD:LED_0402_1005Metric_Pad0.77x0.64mm_HandSolder",""
"U3","1","MAX98357A","","","","","${EXCLUDE_FROM_POS_FILES}","Package_DFN_QFN:TQFN-16-1EP_3x3mm_P0.5mm_EP1.23x1.23mm","https://www.analog.com/media/en/technical-documentation/data-sheets/MAX98357A-MAX98357B.pdf"
"SW1","1","BOOT","","","","","${EXCLUDE_FROM_POS_FILES}","Package_DIP:DIP-24_W7.62mm",""
"SW2","1","RESET","","","","","${EXCLUDE_FROM_POS_FILES}","Package_DIP:DIP-24_W7.62mm",""
"U6,U7","2","DRV8833PW","","","","","${EXCLUDE_FROM_POS_FILES}","Package_SO:TSSOP-16_4.4x5mm_P0.65mm","http://www.ti.com/lit/ds/symlink/drv8833.pdf"
"U4","1","LM1117-3.3","","","","","${EXCLUDE_FROM_POS_FILES}","Package_TO_SOT_SMD:SOT-223-3_TabPin2","http://www.ti.com/lit/ds/symlink/lm1117.pdf"
"U5","1","USBLC6-2SC6","","","","","${EXCLUDE_FROM_POS_FILES}","Package_TO_SOT_SMD:SOT-23-6","https://www.st.com/resource/en/datasheet/usblc6-2.pdf"
"R1,R2,R9,R10","4","10K","","","","","${EXCLUDE_FROM_POS_FILES}","Resistor_SMD:R_0402_1005Metric_Pad0.72x0.64mm_HandSolder",""
"R3,R4","2","2K2","","","","","${EXCLUDE_FROM_POS_FILES}","Resistor_SMD:R_0402_1005Metric_Pad0.72x0.64mm_HandSolder",""
"R5,R6","2","5.1K","","","","","${EXCLUDE_FROM_POS_FILES}","Resistor_SMD:R_0402_1005Metric_Pad0.72x0.64mm_HandSolder",""
"R7","1","1M","","","","","${EXCLUDE_FROM_POS_FILES}","Resistor_SMD:R_0402_1005Metric_Pad0.72x0.64mm_HandSolder",""
"R8","1","1K","","","","","${EXCLUDE_FROM_POS_FILES}","Resistor_SMD:R_0402_1005Metric_Pad0.72x0.64mm_HandSolder",""
"U2","1","ESP32-S3-MINI-1","","","","","${EXCLUDE_FROM_POS_FILES}","RF_Module:ESP32-S2-MINI-1","https://www.espressif.com/sites/default/files/documentation/esp32-s3-mini-1_mini-1u_datasheet_en.pdf"
"J15","1","5V_OUT","","","","","${EXCLUDE_FROM_POS_FILES}","TerminalBlock:TerminalBlock_Xinya_XY308-2.54-3P_1x03_P2.54mm_Horizontal",""
"J16","1","GND_OUT","","","","","${EXCLUDE_FROM_POS_FILES}","TerminalBlock:TerminalBlock_Xinya_XY308-2.54-3P_1x03_P2.54mm_Horizontal",""
"J13","1","5v_IN","","","","","${EXCLUDE_FROM_POS_FILES}","TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Horizontal",""
"J21,J22","2","Motor1","","","","","${EXCLUDE_FROM_POS_FILES}","TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Horizontal",""
"J23,J24","2","Motor2","","","","","${EXCLUDE_FROM_POS_FILES}","TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Horizontal",""

