#include "ls7366r_arduino.h"

// Updated constructor to accept SPI port as a parameter
LS7366R::LS7366R(uint8_t csPin, SPIClass& spiPort) : csPin(csPin), spiPort(spiPort) {}

void LS7366R::init() {
    pinMode(csPin, OUTPUT);
    digitalWrite(csPin, HIGH);
    spiPort.begin(); // Initialize the selected SPI port
}

void LS7366R::sendCommand(uint8_t command) {
    digitalWrite(csPin, LOW);
    spiPort.transfer(command);
    digitalWrite(csPin, HIGH);
}

uint32_t LS7366R::readCounter() {
    uint32_t count = 0;

    digitalWrite(csPin, LOW);
    spiPort.transfer(LS7366R_READ_COUNTER);
    count |= (uint32_t)spiPort.transfer(0) << 24;
    count |= (uint32_t)spiPort.transfer(0) << 16;
    count |= (uint32_t)spiPort.transfer(0) << 8;
    count |= (uint32_t)spiPort.transfer(0);
    digitalWrite(csPin, HIGH);

    return count;
}

void LS7366R::clearCounter() {
    sendCommand(LS7366R_CLEAR_COUNTER);
}
