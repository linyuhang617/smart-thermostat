# smart-thermostat

STM32 smart thermostat with PID control and Zigbee - Sinopé style

## Live Simulation
👉 https://wokwi.com/projects/458439316370906113

## Progress
- [x] Slice 1: Heartbeat (LED blink + System OK)
- [ ] Slice 2: Temperature sensing
- [ ] Slice 3: PID control ⭐
- [ ] Slice 4: User interface (CLI)
- [ ] Slice 5: Scheduling (RTC)
- [ ] Slice 6: Zigbee communication

## Tech Stack
- STM32 L031K6 (ARM Cortex-M0+)
- C language + HAL Library
- Wokwi simulator for validation

## Development Approach
Agile Vertical Slicing — each slice is independently testable and deployable

## Target
Inspired by Sinopé Technologies smart thermostat product line
