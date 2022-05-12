/*
    See BrushedMotor.h for all information.

    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
*/

#include "BrushedMotor.h"


// Constructor

BrushedMotor::BrushedMotor() {}


// Basic function

void BrushedMotor::run(uint16_t ms) {}

void BrushedMotor::stop(uint16_t ms) {
    setSpeed(0);
}

void BrushedMotor::setSpeed(int16_t speed) {
    _speed = speed;
}
       

// State

int8_t BrushedMotor::getState() {
    if (_speed == 0) return 0;  // motor stopped
    if (_speed > 0) return 1;   // CW
    return -1;                  // CCW
}
