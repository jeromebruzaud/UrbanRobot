//
// Created by larnal on 23/01/19.
//

#ifndef ARDUINO_MOTORDRIVER_H
#define ARDUINO_MOTORDRIVER_H

#include <Arduino.h>

namespace driver{
 /*
  * This class control a DC motor. You can change the direction and apply a pwm to it. Speed must be given between -1
  * and 1, -1 is maximum speed backward and 1 maximum speed forward. 0 means you stop the motor.
  */
    class motorDriver{
    private:
        int mPwm_value; // pwm value between -1 and +1
        int mDirection; // direction of the motor, -1 or +1

        unsigned int mPwm; // pin for pwm
        unsigned int mBridge1; // pin for bridge control 1
        unsigned int mBridge2; // pin for bridge control 2
        unsigned int mEncoder1; // pin for encoder 1
        unsigned int mEncoder2; // pin for encoder 2

        volatile unsigned long mTimer; // timer to calculate rotation speed
        volatile float mSpeed;
        unsigned int mGearRatio;
        unsigned int mEncoderRes;

        void rotate(unsigned int pwm_value); // method to apply pwm
        void direction(int direction);
        //void encoderChange();

    public:
        motorDriver(unsigned int pwm, unsigned int bridge1, unsigned int bridge2, unsigned int encoder1, unsigned int encoder2, unsigned int gearRatio, unsigned int encoder_res);
        void encoderChange();
        void run(float pwm_value);
        void stop();
        float getSpeed();
    };
}

#endif //ARDUINO_MOTORDRIVER_H
