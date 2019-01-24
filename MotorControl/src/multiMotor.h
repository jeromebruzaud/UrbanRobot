//
// Created by larnal on 23/01/19.
//

#ifndef ARDUINO2_MULTIMOTOR_H
#define ARDUINO2_MULTIMOTOR_H

#include "motorDriver.h"
#include "Arduino.h"

namespace driver{
    class multiMotor{
    private:
        motorDriver mMotor1;
        motorDriver mMotor2;
        motorDriver mMotor3;
        motorDriver mMotor4;
        motorDriver mMotor5;
        motorDriver mMotor6;

    public:
        multiMotor(motorDriver m1, motorDriver m2, motorDriver m3, motorDriver m4, motorDriver m5, motorDriver m6);
        void setSpeed(float s1, float s2, float s3, float s4, float s5, float s6)
        void stop();
        int[] getEncoders();

    };
}

#endif //ARDUINO2_MULTIMOTOR_H
