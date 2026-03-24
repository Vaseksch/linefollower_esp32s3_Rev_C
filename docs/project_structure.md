
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
│  │  ├─ board
│  │  │  ├─ buttons.h
│  │  │  └─ status_led.h
│  │  ├─ controller
│  │  │  ├─ pid.h
│  │  │  └─ special_cases.h
│  │  ├─ display
│  │  │  └─ display.h
│  │  ├─ imu
│  │  │  └─ imu.h
│  │  ├─ motors
│  │  │  └─ motor.h
│  │  └─ sensors
│  │     └─ sensor.h
│  └─ utils
│     ├─ i2c_manager
│     │  └─ i2c_manager.h
│     └─ logger
│        └─ logger.h
├─ platformio.ini
└─ src
   ├─ config
   │  └─ board_config.cpp
   ├─ core
   │  └─ main.cpp
   ├─ modules
   │  ├─ board
   │  │  ├─ buttons.cpp
   │  │  └─ status_led.cpp
   │  ├─ controller
   │  │  ├─ pid.cpp
   │  │  └─ special_cases.cpp
   │  ├─ display
   │  │  └─ display.cpp
   │  ├─ imu
   │  │  └─ imu.cpp
   │  ├─ motors
   │  │  └─ motors.cpp
   │  └─ sensor
   │     └─ sensor.cpp
   └─ utils
      ├─ i2c_manager
      │  └─ i2c_manager.cpp
      └─ logger
         └─ logger.cpp

```