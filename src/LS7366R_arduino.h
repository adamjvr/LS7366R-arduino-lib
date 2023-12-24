#ifndef LS7366R_ARDUINO_H
#define LS7366R_ARDUINO_H

#include <Arduino.h>
#include <SPI.h>

class LS7366R {
public:
    LS7366R(uint8_t csPin, SPIClass& spiPort); // Updated constructor
    void init();
    void sendCommand(uint8_t command);
    uint32_t readCounter();
    void clearCounter();

private:
    uint8_t csPin;
    SPIClass& spiPort; // Reference to the SPI port
};

#endif /* LS7366R_ARDUINO_H */
