# EV Battery Optimizer

An ESP32-based IoT system for monitoring and optimizing EV charging bays using real-time telemetry, load management, edge intelligence, and cloud connectivity.

## Overview

The **EV Battery Optimizer** is designed to monitor multiple EV charging bays and make charging decisions based on real-time electrical and environmental parameters.

The system uses ESP32 devices deployed across individual charging bays. Each bay collects sensor data such as voltage, current, and temperature and communicates the data to **ThingsBoard using MQTT**.

The project currently contains three charging-bay implementations:

* BAY1
* BAY2
* BAY3

Each bay follows a similar modular architecture while maintaining its own configuration.

## Key Features

* Real-time voltage and current monitoring
* Temperature monitoring using DHT22
* EV charging bay status detection
* Relay-based charging control
* Overload detection
* Charging load management
* Telemetry transmission using MQTT
* ThingsBoard cloud integration
* Remote procedure call (RPC) support
* Edge-AI based processing
* Charging optimization logic
* Wokwi simulation support
* Modular ESP32 firmware architecture

## System Architecture

```text
             ┌─────────────────────┐
             │    EV Charging Bay  │
             └──────────┬──────────┘
                        │
          ┌─────────────┼─────────────┐
          │             │             │
       Voltage        Current      Temperature
       Sensor         Sensor          DHT22
          │             │             │
          └─────────────┼─────────────┘
                        │
                   ┌────▼────┐
                   │  ESP32  │
                   └────┬────┘
                        │
             ┌──────────┴──────────┐
             │                     │
       Optimization             Edge AI
          Logic                  Logic
             │                     │
             └──────────┬──────────┘
                        │
                     MQTT
                        │
                ┌───────▼────────┐
                │   ThingsBoard   │
                │    Dashboard    │
                └─────────────────┘
```

## Hardware

The project is developed for an ESP32 development board.

### Main Components

* ESP32 DOIT DEVKIT V1
* Voltage sensing input
* Current sensing input
* DHT22 temperature sensor
* Relay module
* Push buttons for plug-in / plug-out events
* Status LEDs
* Optional OLED display

## Software Stack

| Component            | Technology  |
| -------------------- | ----------- |
| Microcontroller      | ESP32       |
| Firmware Framework   | Arduino     |
| Build System         | PlatformIO  |
| IoT Protocol         | MQTT        |
| Cloud Platform       | ThingsBoard |
| Simulation           | Wokwi       |
| Programming Language | C/C++       |
| Sensor               | DHT22       |
| Communication        | Wi-Fi       |

## Project Structure

```text
projectiot/
│
├── BAY1 (1)/
│   └── esp32_blink/
│       ├── include/
│       ├── lib/
│       ├── src/
│       ├── test/
│       └── platformio.ini
│
├── BAY2/
│   └── esp32_blink/
│       ├── include/
│       ├── lib/
│       ├── src/
│       ├── test/
│       └── platformio.ini
│
├── BAY3/
│   └── esp32_blink/
│       ├── include/
│       ├── lib/
│       ├── src/
│       ├── diagram.json
│       ├── platformio.ini
│       └── wokwi.toml
│
├── .gitignore
└── README.md
```

## Firmware Modules

The firmware is divided into separate modules to keep the system maintainable.

* `Network.cpp` — Wi-Fi and MQTT communication
* `Peripherals.cpp` — sensor and hardware interaction
* `State.cpp` — charging-bay state management
* `Telemetry.cpp` — telemetry preparation and transmission
* `optimization.cpp` — charging/load optimization logic
* `edge_ai.cpp` — edge intelligence functionality
* `rpc.cpp` — ThingsBoard RPC handling
* `config.cpp` — project configuration
* `main.cpp` — main firmware execution flow

## ThingsBoard Integration

The ESP32 communicates with ThingsBoard through MQTT.

The system can transmit telemetry related to:

* Voltage
* Current
* Temperature
* Bay status
* Charging/load state
* Overload status
* Optimization decisions
* Other system parameters

ThingsBoard RPC functionality can also be used for remote control operations such as relay or charging-state control.

> **Security:** Device access tokens and other credentials should never be committed to the repository. Configure them locally before running the firmware.

## Running the Project

### 1. Clone the Repository

```bash
git clone https://github.com/ananya819/EVbattery_Optimizer.git
```

### 2. Open a Bay Project

Open one of the PlatformIO projects, for example:

```text
BAY3/esp32_blink/
```

### 3. Configure Credentials

Before running the firmware, configure your local ThingsBoard device credentials in the appropriate configuration file.

Do not commit real access tokens or passwords to GitHub.

### 4. Build

Using PlatformIO:

```bash
pio run
```

### 5. Upload to ESP32

Connect the ESP32 and run:

```bash
pio run --target upload
```

### 6. Monitor Serial Output

```bash
pio device monitor
```

## Wokwi Simulation

The project contains Wokwi configuration files for simulation and testing.

Depending on the bay implementation, simulation files include:

```text
diagram.json
wokwi.toml
```

These can be used to test the ESP32 firmware without physical hardware.

## Future Improvements

Possible future extensions include:

* Centralized multi-bay load optimization
* Database integration
* Advanced charging-demand prediction
* Improved edge-AI models
* Dynamic tariff-aware charging
* PostgreSQL/MySQL/MongoDB integration
* Advanced ThingsBoard dashboards
* Automated anomaly detection
* Improved fault monitoring

## Author

**Ananya Singh**

B.Tech — Computer Science and Engineering

GitHub: [ananya819](https://github.com/ananya819)

## License

This project is intended for educational, research, and development purposes.
