/*
    Brushed motor
    
    Author: Dmitrii Kurskov <dmitrii@kurskov.ru>
    GitHub: https://github.com/kurskov/Arduino-BrushedMotor
    Version: 1.0.0

    MIT license
*/

#ifndef _DK_BrushedMotor_h
#define _DK_BrushedMotor_h

#if defined(ARDUINO) && ARDUINO >= 100
    #include <Arduino.h>
#else
    #include <WProgram.h>
#endif

class BrushedMotor {
    public:
        BrushedMotor(uint8_t pinA, uint8_t pinB, uint8_t pinC);

        void run(uint16_t ms = 0);

        void stop(uint16_t ms = 0);

        // Sets the rotate speed.
        // This function not run the motor, but can change speed in the work time.
        // If you set the value as 0, the motor will stop. (?)
        // - positive is CW
        // - negative is CCW
        void setSpeed(int16_t speed);
        
        // State of the motor.
        // Returns one of three chooses:
        // -1 - motor rotates counterclockwise (CCW)
        //  0 - motor stopped
        //  1 - motor rotates clockwise (CW)
        int8_t getState();

    private:
        int16_t _speed = 0;
};

#endif // _DK_BrushedMotor_h
