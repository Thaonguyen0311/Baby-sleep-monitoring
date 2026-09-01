# Baby-sleep-monitoring

https://www.youtube.com/watch?v=7zeq_d3Gcyo

[![Watch the video](https://img.youtube.com/vi/7zeq_d3Gcyo/0.jpg)](https://www.youtube.com/watch?v=7zeq_d3Gcyo)

## Key Features
**Sleep movement monitoring**: Used the MPU6050 accelerometer and gyroscope to detect and analyze the baby’s movements during sleep.

**Automatic soothing**: Integrated a DFPlayer Mini and mini speaker to automatically play soothing audio when significant movement or restlessness was detected.

**Real-time parental alerts**: Connected the system to Telegram to send notifications to parents when predefined movement conditions were detected.

**Embedded control**: Developed the system logic in C++ on a ESP32, integrating sensor input, audio playback, and communication into a single monitoring workflow.

**Event-based monitoring**: Designed the system to continuously monitor sensor data and trigger appropriate actions based on detected movement patterns.
## System Workflow
MPU6050 → ESP32 → Movement Analysis →

↳ Normal sleep → Continue monitoring ↳ Detected movement → Play soothing audio ↳ Significant/abnormal movement → Send Telegram alert

## Technologies & Hardware
Programming: C++ Platform: ESP32 Sensor: MPU6050 (Accelerometer + Gyroscope) Audio: DFPlayer Mini + Mini Speaker Communication: Telegram Bot API Domain: Embedded Systems · IoT · Sensor Processing · Automation
