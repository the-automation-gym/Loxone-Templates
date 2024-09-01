//Pull a string information from HTTP - Save it in a buffer, then parse through it and output the desired string
void main() {
    char *response;
    char buffer[1024];
    char *start_ptr;
    int output_length = 100;
    char output_text[101];  // 100 characters + 1 for null terminator

    char url[256]=getinputtext(0);         // Buffer to store the URL input
    char path[256]=getinputtext(1);        // Buffer to store the path input
    char search_text[256]=getinputtext(2); // Buffer to store the search text input

    // Send HTTP GET request
    response = httpget(url, path);

    // Copy the response into a buffer (assuming the buffer is large enough)
    strncpy(buffer, response, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';  // Ensure null-termination

    // Use strstrskip to find the search text and move the pointer to the text after it
    start_ptr = strstrskip(buffer, search_text);

    // Check if the pointer is not NULL (which would indicate the substring was found)
    if (start_ptr != 0) {
        // Copy the next 100 characters after the search text into output_text
        strncpy(output_text, start_ptr, output_length);

        // Ensure the output is null-terminated
        output_text[output_length] = '\0';

        // Output the extracted substring to Output 1 (O1)
        setoutputtext(0, output_text);
    } else {
        setoutputtext(0, "Error: Search text not found");  // Handle error case
    }

    // Free the memory allocated for the HTTP response
    free(response);
}

main();
