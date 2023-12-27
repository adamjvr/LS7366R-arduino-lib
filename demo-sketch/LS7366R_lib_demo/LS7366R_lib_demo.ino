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
// uses the Arduino DUE Programming Port option when selecting which board to use in the Arduino IDE 
void setup() {
    Serial.begin(9600);
    encoder.init();
}

void loop() {
    encoder.clearCounter();
    delay(1000);

    uint32_t count = encoder.readCounter();
    Serial.print("Counter: ");
    Serial.println(count);

    delay(1000);
}
