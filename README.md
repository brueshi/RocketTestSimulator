# Rocket Test Data Simulator
A C++ console application simulating rocket test stand data. Generates random sensor readings (temperature, pressure, thrust), monitors safety with configurable thresholds, logs to a CSV file, and calculates averages. Stops on unsafe conditions. Built to explore test software concepts relevant to SpaceX.

## Features
- Real-time simulation with 1-second delays
- Configurable safety checks with specific alerts (overheating, overpressure, thrust range)
- CSV file logging (`rocket_data.txt`)
- User prompt to start
- Error-handled average calculation

## How to Run
1. Compile with a C++ compiler (e.g., Visual Studio, g++).
2. Press Enter to start.
3. View output in console and `rocket_data.txt`.

## Sample Output

Press Enter to start rocket test simulation...

Reading 1: Temp: 87 degC, Pressure: 4.4 bar, Thrust: 1637 N

Reading 2: Temp: 97 degC, Pressure: 4.8 bar, Thrust: 2333 N - ALERT: Overheating! Reduce fuel flow. Stopping simulation.

Average Temperature: 92 degC

Data saved to rocket_data.txt
