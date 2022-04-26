/*
    Morse code
    
    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
    GitHub: https://github.com/kurskov/Arduino-MorseCode
    Version: 1.0.0

    MIT license
*/

#ifndef _DK_CMotor_h
#define _DK_CMotor_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

class CMotor {
    public:
        CMotor(uint8_t pinA, uint8_t pinB, uint8_t pinC);

        void run(uint16_t ms);

        void stop(uint16_t ms);

        // positive is CW
        // negative is CCW
        void setSpeed(int16_t value);
        
        // State of the motor.
        // Returns one of three chooses:
        // -1 - motor rotates counterclockwise (CCW)
        //  0 - motor stopped
        //  1 - motor rotates clockwise (CW)
        int8_t getState();

    private:
        int16_t _speed = 0;
};

#endif // _DK_CMotor_h
