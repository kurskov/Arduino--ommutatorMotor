/*
    See CMotor.h for all information.

    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
*/

#include "CMotor.h"


// Constructor

CMotor::CMotor() {}


// Basic function

void CMotor::run(uint16_t ms) {}

void CMotor::stop(uint16_t ms) {
    setSpeed(0);
}

void CMotor::setSpeed(int16_t value) {
    _speed = value;
}
       

// State

int8_t CMotor::getState() {
    if (_speed == 0) return 0;  // motor stopped
    if (_speed > 0) return 1;   // CW
    return -1;                  // CCW
}
