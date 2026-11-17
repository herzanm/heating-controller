#include <Arduino.h>

void setup()
{
    pinMode(8, OUTPUT);
    Serial.begin(115200);
    delay(2000);

    Serial.println("SLAVE START");
}

void loop()
{
    Serial.println("SLAVE RUNNING");
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(1000);
}