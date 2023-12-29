/*

MIT License

Copyright (c) 2023 Adam Vadala-Roth

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "ls7366r_arduino.h"

#define LS7366R_CS_PIN 10
#define LS7366R_SPI_PORT SPI // Change this to the desired SPI port

LS7366R encoder(LS7366R_CS_PIN, LS7366R_SPI_PORT);

void setup() {
    Serial.begin(9600);
    encoder.init();
}

void loop() {
    // Read and print the counter value
    uint32_t count = encoder.readCounter();
    Serial.print("Counter: ");
    Serial.println(count);

    // Clear the counter and print the cleared value
    encoder.clearCounter();
    Serial.println("Counter Cleared");

    // Read and print the status register
    uint8_t status = encoder.readStatus();
    Serial.print("Status Register: 0x");
    Serial.println(status, HEX);

    // Read and print the mode register
    uint8_t mode = encoder.readMode();
    Serial.print("Mode Register: 0x");
    Serial.println(mode, HEX);

    // Write a new mode to the mode register
    encoder.writeMode(0x0F);
    Serial.println("Mode Register Written");

    // Load a value into the counter and print the new counter value
    encoder.loadCounter(0x12345678);
    Serial.println("Counter Loaded with 0x12345678");

    // Load a value into the OTR (One Turn Register) and print the new OTR value
    encoder.loadOTR(0xABCD1234);
    Serial.println("OTR Loaded with 0xABCD1234");

    // Read and print the OTR value
    uint32_t otrValue = encoder.readOTR();
    Serial.print("OTR Value: 0x");
    Serial.println(otrValue, HEX);

    // Delay for demonstration purposes
    delay(5000);
}
