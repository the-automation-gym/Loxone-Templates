#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> // for sleep function

// Simulate setoutputtext function with printf
void setoutputtext(int line, const char* message) {
    printf("Output[%d]: %s\n", line, message);
}

// Simulate setoutput function to show heater ON/OFF
void setoutput(int output_id, int state) {
    printf("Output device %d state: %s\n", output_id, state ? "ON" : "OFF");
}

// Simulate temperature input
int getinput(int id) {
    return 22; // Simulate constant temperature input
}

int main() {
    // 1. Variable Declaration and Output
    int temperature = 22;
    float humidity = 55.2;
    char status[] = "Normal";

    char msg[50];

    // Displaying values
    sprintf(msg, "Temperature: %d°C", temperature);
    setoutputtext(0, msg);

    sprintf(msg, "Humidity: %.1f%%", humidity);
    setoutputtext(1, msg);

    setoutputtext(2, status);

    // 2. Math Operations (Calculate Average Temperature)
    int temp1 = 22, temp2 = 18, temp3 = 20;
    int avg_temp = (temp1 + temp2 + temp3) / 3;

    sprintf(msg, "Average Temperature: %d°C", avg_temp);
    setoutputtext(0, msg);

    // 3. If-Else Conditional Logic (Control Heater)
    if (temperature < 20) {
        setoutput(1, 1);  // Turn heater ON
        setoutputtext(0, "Heater ON");
    } else {
        setoutput(1, 0);  // Turn heater OFF
        setoutputtext(0, "Heater OFF");
    }

    // 5. For Loop (Checking Multiple Sensors)
    int num_sensors = 3;
    int sensors[3] = {22, 18, 21};  // Simulated sensor readings
    for (int i = 0; i < num_sensors; i++) {
        sprintf(msg, "Sensor %d Temp: %d°C", i + 1, sensors[i]);
        setoutputtext(i, msg);
    }

    // 6. While Loop (Continuous Monitoring)
    for (int i = 0; i < 2; i++) { // Limit to 2 iterations for demo
        int temp = getinput(0);  // Get temperature reading
        sprintf(msg, "Current Temperature: %d°C", temp);
        setoutputtext(0, msg);
        sleep(5);  // Sleep for 5 seconds
    }

    // 7. Working with Strings (System Status)
    char system_status[50];
    if (temperature > 30) {
        strcpy(system_status, "Temperature too high");
    } else {
        strcpy(system_status, "Temperature normal");
    }
    setoutputtext(0, system_status);  // Output the status message

    // 9. Debugging and Testing (Basic Output Test)
    sprintf(msg, "Testing: Temperature is %d°C", temperature);
    setoutputtext(0, msg);

    // 10. Testing Strings (Display System Status)
    setoutputtext(0, system_status);

    return 0;
}
