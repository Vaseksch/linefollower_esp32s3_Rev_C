
```
linefollower_esp32s3_V2.0
├─ docs
│  ├─ project_structure.md
│  └─ README.md
├─ include
│  ├─ config
│  │  ├─ board_config.h
│  │  └─ constants.h
│  ├─ modules
│  │  ├─ controller
│  │  │  ├─ pid.h
│  │  │  └─ special_cases.h
│  │  ├─ display
│  │  │  └─ display.h
│  │  ├─ imu
│  │  │  └─ imu.h
│  │  ├─ motors
│  │  │  └─ motor.h
│  │  ├─ sensors
│  │  │  └─ sensor.h
│  │  └─ status_led
│  │     └─ status_led.h
│  └─ utils
│     └─ logger
│        └─ logger.h
├─ platformio.ini
└─ src
   ├─ config
   │  └─ board_config.cpp
   ├─ core
   │  └─ main.cpp
   ├─ modules
   │  ├─ controller
   │  │  ├─ pid.cpp
   │  │  └─ special_cases.cpp
   │  ├─ display
   │  │  └─ display.cpp
   │  ├─ imu
   │  │  └─ imu.cpp
   │  ├─ motors
   │  │  └─ motors.cpp
   │  ├─ sensor
   │  │  └─ sensor.cpp
   │  └─ status_led
   │     └─ status_led.cpp
   └─ utils
      └─ logger.cpp

```