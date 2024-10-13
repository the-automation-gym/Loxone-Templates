// Pico C Cheat Sheet - Quick Reference

// 1. Variable Declaration and Initialization
int temperature = 22;
float humidity = 60.5;
char letter = 'A';

// 2. Output to Text
setoutputtext(0, "Hello, Pico C!"); // Output string to text output 0

// 3. Output to Analog/Digital
setoutput(0, temperature); // Set analog output 0 to temperature

// 4. If-Else Conditional
if (temperature < 20) {
    setoutput(1, 1); // Turn on heater if temp < 20
    setoutputtext(0, "Heater ON");
} else {
    setoutput(1, 0); // Turn off heater if temp >= 20
    setoutputtext(0, "Heater OFF");
}

// 5. While Loop
int count = 0;
while (count < 5) {
    setoutputtext(0, "Count is " + count);
    count++;
    sleep(1000); // Sleep for 1 second to reduce CPU usage
}

// 6. For Loop
for (int i = 0; i < 5; i++) {
    setoutputtext(0, "Iteration " + i); // Loop with a counter
}

// 7. Function Definition and Use
int add(int a, int b) {
    return a + b; // Add two integers
}

void main() {
    int result = add(5, 10);
    setoutput(0, result); // Output the sum of 5 and 10
}

// 8. Memory Management
char *response = httpget("api.example.com", "/data"); // HTTP GET request
if (response != NULL) {
    setoutputtext(0, response); // Display the response
    free(response); // Free allocated memory after use
}

// 9. Buffers and Strings
char buffer[256];
strcpy(buffer, "Hello, Buffer!");
setoutputtext(0, buffer); // Output content of buffer

// 10. Event Handling
while (TRUE) {
    int event = getinputevent(); // Check for input events
    if (event & 0x01) { // If the first input changed
        float temp = getinput(0); // Get the value of the first input
        setoutputtext(0, "Temperature: " + temp); // Output the temperature
    }
    sleep(500); // Sleep to reduce CPU usage
}

// 11. File I/O
FILE *file = fopen("/dev/tty/my_rs232_extension", "w");
if (file != NULL) {
    fprintf(file, "Data written to RS232\n"); // Write to RS232 stream
    fclose(file); // Close the file/stream
}

// 12. HTTP Request and Response Handling
char *weather_data = httpget("api.open-meteo.com", "/v1/forecast?latitude=35&longitude=139&hourly=temperature_2m");
if (weather_data != NULL) {
    setoutputtext(0, weather_data); // Output fetched data
    free(weather_data); // Free memory after use
}

// 13. Sleep and CPU Management
sleep(1000); // Sleep for 1 second (1000 ms)

// Main Program Structure
void main() {
    // Your code here
}
main(); // Start the program
