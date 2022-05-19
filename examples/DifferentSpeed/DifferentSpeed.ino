#include <BrushedMotor.h>

BrushedMotor motor(5, 6);

void setup() {
}

void loop() {
    motor.run(150);
    delay(1000);
    motor.run(50);
    delay(1000);
    motor.run(-100);
    delay(1000);
    motor.brake();
    delay.(1000);
    motor.run();
    delay(1000);
    motor.stop();
    delay(3000);
}