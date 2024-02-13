#include <Wire.h>

char serinput;
void setup() {
 Serial.begin(9600); /* begin serial comm. */
 Wire.begin(8); /* join i2c bus as master */
 Serial.println("Ready");
}

void loop() {
    if (Serial.available()) {
        serinput = Serial.read();
        char message;
        if ((char)serinput == 'r' || (char)serinput == 'R' ||
            (char)serinput == 'b' || (char)serinput == 'B' ||
            (char)serinput == 'y' || (char)serinput == 'Y') {
            message = serinput;
            Wire.beginTransmission(8); /* begin with device address 8 */
            Wire.write(message);
            Wire.endTransmission();    /* stop transmitting */
            delay(1000);
        }
    }
}