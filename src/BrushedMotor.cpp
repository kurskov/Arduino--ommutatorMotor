/*
    See BrushedMotor.h for all information.

    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
*/

#include "BrushedMotor.h"


// Constructor

BrushedMotor::BrushedMotor(uint8_t pinA, uint8_t pinB, uint8_t pinC) {
    _pinA = pinA;
    _pinB = pinB;
    _pinC = pinC;

    pinMode(_pinA, OUTPUT);
    digitalWrite(_pinA, LOW);
    pinMode(_pinB, OUTPUT);
    digitalWrite(_pinB, LOW);
    
    if (_pinC != 255) {
        pinMode(_pinC, OUTPUT);
        digitalWrite(_pinC, LOW);
    }
}


// Basic function

void BrushedMotor::run(uint16_t ms) {
    if (_speed == 0) {
        brake();
        digitalWrite(_pinA, LOW);
        digitalWrite(_pinB, LOW);
    }
    if (_speed > 0) {
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinB, LOW);
    } else {
        digitalWrite(_pinA, LOW);
        digitalWrite(_pinB, HIGH);
    }
}

void BrushedMotor::stop(uint16_t ms) {
    setSpeed(0);
}

void BrushedMotor::setSpeed(int16_t speed) {
    _speed = speed;
    run();
}

void BrushedMotor::brake() {
    digitalWrite(_pinA, HIGH);
    digitalWrite(_pinB, HIGH);
}
       

// State

int8_t BrushedMotor::getState() {
    if (_speed == 0) return 0;  // motor stopped
    if (_speed > 0) return 1;   // CW
    return -1;                  // CCW
}
