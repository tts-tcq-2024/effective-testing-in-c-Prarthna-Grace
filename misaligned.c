#include <stdio.h>
#include <assert.h>
#include<string.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%d | %s | %s\n", i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return i * j;
}

// Function to capture output from printColorMap
char* captureOutput(char* outputBuffer) {
    // Clear the buffer
    memset(outputBuffer, 0, 1000);
    // Set buffer for stdout
    setvbuf(stdout, outputBuffer, _IOFBF, 1000);

    printColorMap(); // Call the function

    fflush(stdout); // Flush to ensure all output is captured
    return outputBuffer; // Return the captured output
}

int main() {
    char output[1000];
    int result = printColorMap(); // Call the function to print and get the result
    assert(result == 25); 
    
    // Capture the output
    char* capturedOutput = captureOutput(output);
    
     // Expected output
    const char* expectedOutput =
        "0 | White | Blue\n"
        "1 | White | Orange\n"
        "2 | White | Green\n"
        "3 | White | Brown\n"
        "4 | White | Slate\n"
        "5 | Red | Blue\n"
        "6 | Red | Orange\n"
        "7 | Red | Green\n"
        "8 | Red | Brown\n"
        "9 | Red | Slate\n"
        "10 | Black | Blue\n"
        "11 | Black | Orange\n"
        "12 | Black | Green\n"
        "13 | Black | Brown\n"
        "14 | Black | Slate\n"
        "15 | Yellow | Blue\n"
        "16 | Yellow | Orange\n"
        "17 | Yellow | Green\n"
        "18 | Yellow | Brown\n"
        "19 | Yellow | Slate\n"
        "20 | Violet | Blue\n"
        "21 | Violet | Orange\n"
        "22 | Violet | Green\n"
        "23 | Violet | Brown\n"
        "24 | Violet | Slate\n";

    // Validate output content
    assert(strcmp(output, expectedOutput) == 0);
    printf("All is well (maybe!)\n");
    return 0;
}
