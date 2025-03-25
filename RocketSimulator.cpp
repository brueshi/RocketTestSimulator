#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>

// Safety threshold constants
const double MAX_TEMP = 90.0;        // Max safe temperature (degC)
const double MAX_PRESSURE = 5.0;     // Max safe pressure (bar)
const double MIN_THRUST = 1500.0;    // Min safe thrust (N)
const double MAX_THRUST = 4500.0;    // Max safe thrust (N)

class Sensor {
public:
    double temperature; // in degrees Celsius
    double pressure;    // in bars
    double thrust;      // in Newtons

    // Constructor: Generate random sensor data
    Sensor() {
        temperature = 20.0 + (rand() % 81);      // 20-100°C
        pressure = 0.5 + (rand() % 51) / 10.0;   // 0.5-5.5 bar
        thrust = 1000.0 + (rand() % 4001);       // 1000-5000 N
    }

    // Display sensor readings
    void display() {
        std::cout << "Temp: " << temperature << " degC, Pressure: " << pressure
            << " bar, Thrust: " << thrust << " N";
    }

    // Check if readings are within safe limits
    bool isSafe() {
        if (temperature > MAX_TEMP) {
            std::cout << " - ALERT: Overheating! Reduce fuel flow.";
            return false;
        }
        if (pressure > MAX_PRESSURE) {
            std::cout << " - ALERT: Overpressure! Vent system.";
            return false;
        }
        if (thrust < MIN_THRUST || thrust > MAX_THRUST) {
            std::cout << " - ALERT: Thrust out of range! Adjust throttle.";
            return false;
        }
        return true;
    }
};

int main() {
    srand(time(0));
    std::vector<Sensor> readings;

    // User prompt to start simulation
    std::cout << "Press Enter to start rocket test simulation...\n";
    std::cin.get();

    // Open file for logging
    std::ofstream file("rocket_data.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file!\n";
        return 1;
    }
    file << "Temp,Pressure,Thrust\n";

    // Simulate up to 10 readings
    for (int i = 0; i < 10; i++) {
        Sensor s;
        readings.push_back(s);
        std::cout << "Reading " << i + 1 << ": ";
        s.display();
        file << s.temperature << "," << s.pressure << "," << s.thrust << "\n";
        if (!s.isSafe()) {
            std::cout << " Stopping simulation.\n";
            break;
        }
        std::cout << "\n";
        Sleep(1000);
    }

    file.close();

    // Calculate and display average temperature with error handling
    double sum = 0.0;
    for (int i = 0; i < readings.size(); i++) {
        sum += readings[i].temperature;
    }
    double average = (readings.size() > 0) ? sum / readings.size() : 0.0;
    std::cout << "\nAverage Temperature: " << average << " degC\n";
    std::cout << "Data saved to rocket_data.txt\n";

    return 0;
}