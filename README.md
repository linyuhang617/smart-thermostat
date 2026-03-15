# Smart Thermostat

Sinopé-style embedded thermostat control system running on STM32.

## Features

- NTC temperature sensing (analog)
- PID control algorithm (Kp=2.0, Ki=0.5, Kd=0.1)
- Anti-windup integral clamp
- PWM heater output simulation
- UART serial monitoring

## Tech Stack

- STM32F103C8T6 (ARM Cortex-M3, Blue Pill)
- C / Arduino Framework
- Wokwi simulation

## Simulation

👉 [Wokwi Project](https://wokwi.com/projects/458590010014345217)

## Pin Assignment

| Pin | Function |
|-----|----------|
| A0  | NTC temperature sensor |
| A1  | PWM heater LED |
| A9  | UART TX (Serial Monitor) |
| A10 | UART RX (Serial Monitor) |

## Progress

| Slice | Name | Status |
|-------|------|--------|
| 1 | Heartbeat | ✅ Done |
| 2 | Temperature Sensing | ✅ Done |
| 3 | PID Control ⭐ | ✅ Done |
| 4 | CLI Interface | ⬜ Next |
| 5 | Scheduling | ⬜ |
| 6 | Zigbee Communication | ⬜ |

## Development Logs

- [Slice 1: Heartbeat](docs/slice-1-heartbeat.md)
- [Slice 2: Temperature Sensing](docs/slice-2-temperature.md)
- [Slice 3: PID Control](docs/slice-3-pid-control.md)
