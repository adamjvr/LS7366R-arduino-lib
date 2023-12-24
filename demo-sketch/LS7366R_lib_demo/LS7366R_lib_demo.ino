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
