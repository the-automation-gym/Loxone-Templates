// Pico C Cheat Sheet - Complete Code

// 1. Variable Declaration and Output
void main() {
    // Variables
    int temperature = 22;
    float humidity = 55.2;
    char status[] = "Normal";

    // Output variables
    setoutputtext(0, "Temperature: " + temperature);
    setoutputtext(1, "Humidity: " + humidity);
    setoutputtext(2, "Status: " + status);

    // 2. Math Operations (Calculate Average Temperature)
    int temp1 = 22;
    int temp2 = 18;
    int temp3 = 20;
    int avg_temp = (temp1 + temp2 + temp3) / 3;

    // Output the average temperature
    setoutputtext(0, "Average Temperature: " + avg_temp + "°C");

    // 3. If-Else Conditional Logic (Control Heater)
    if (temperature < 20) {
        setoutput(1, 1);  // Turn heater ON
        setoutputtext(0, "Heater ON");
    } else {
        setoutput(1, 0);  // Turn heater OFF
        setoutputtext(0, "Heater OFF");
    }

    // 4. Event Handling (Monitor Temperature Changes)
    while (TRUE) {
        int event = getinputevent();  // Check for input event
        if (event & 0x01) {  // If the first input (temperature sensor) changed
            int temperature = getinput(0);
            if (temperature < 20) {
                setoutput(1, 1);  // Turn heater ON
                setoutputtext(0, "Heater ON, Temp: " + temperature + "°C");
            } else {
                setoutput(1, 0);  // Turn heater OFF
                setoutputtext(0, "Heater OFF, Temp: " + temperature + "°C");
            }
        }
        sleep(1000);  // Sleep for 1 second to reduce CPU load
    }

    // 5. For Loop (Checking Multiple Sensors)
    int num_sensors = 3;
    int sensors[3] = {22, 18, 21};  // Simulated sensor readings
    for (int i = 0; i < num_sensors; i++) {
        setoutputtext(i, "Sensor " + (i + 1) + " Temp: " + sensors[i] + "°C");
    }

    // 6. While Loop (Continuous Monitoring)
    while (TRUE) {
        int temp = getinput(0);  // Get temperature reading
        setoutputtext(0, "Current Temperature: " + temp + "°C");
        sleep(5000);  // Sleep for 5 seconds to check every 5 seconds
    }

    // 7. Working with Strings (System Status)
    char system_status[50];
    if (temperature > 30) {
        strcpy(system_status, "Temperature too high");
    } else {
        strcpy(system_status, "Temperature normal");
    }
    setoutputtext(0, system_status);  // Output the status message

    // 8. HTTP Requests (Fetching Weather Data)
    char *response;
    response = httpget("api.open-meteo.com", "/v1/forecast?latitude=35&longitude=139&hourly=temperature_2m");
    if (response != NULL) {
        setoutputtext(0, response);  // Output the weather data
        free(response);  // Free memory after use
    } else {
        setoutputtext(0, "Error: Could not fetch weather data");
    }

    // 9. Debugging and Testing (Basic Output Test)
    setoutputtext(0, "Testing: Temperature is " + temperature + "°C");

    // 10. Testing Strings (Display System Status)
    setoutputtext(0, "System Status: " + system_status);
}
main();  // Run the main program
