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
    pinMode(_pinB, OUTPUT);
    
    if (_pinC != 255) {
        pinMode(_pinC, OUTPUT);
    }

    stop();
}


// Basic function

void BrushedMotor::run(int16_t speed) {
    if (speed > 1024) {
        speed = _speed;
    }

    _speed = constrain(speed, -255, 255);
    
    if (_speed == 0) {
        return stop();
    }

    if (_speed > 0) {
        digitalWrite(_pinA, HIGH);
        digitalWrite(_pinB, LOW);
    } else {
        digitalWrite(_pinA, LOW);
        digitalWrite(_pinB, HIGH);
    }

    if (_pinC == 255) {
        analogWrite(_pinA, abs(_speed));
    } else {
        analogWrite(_pinC, abs(_speed));
    }

}

void BrushedMotor::stop() {
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, LOW);
    
    if (_pinC != 255) {
        pinMode(_pinC, OUTPUT);
        digitalWrite(_pinC, LOW);
    }
}

void BrushedMotor::brake() {
    digitalWrite(_pinA, HIGH);
    digitalWrite(_pinB, HIGH);
    
    if (_pinC != 255) {
        pinMode(_pinC, OUTPUT);
        analogWrite(_pinC, abs(_speed));
    }
}
   

// State

int8_t BrushedMotor::getState() {
    if (_speed == 0) return 0;  // motor stopped
    if (_speed > 0) return 1;   // forward
    return -1;                  // backward
}
