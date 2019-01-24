//
// Created by larnal on 23/01/19.
//

#ifndef ARDUINO2_MULTIMOTOR_H
#define ARDUINO2_MULTIMOTOR_H

#include "motorDriver.h"

namespace driver{
    class multiMotor{
    private:
        motorDriver *mMotors[6];

    public:
        multiMotor(motorDriver *m0, motorDriver *m1, motorDriver *m2, motorDriver *m3, motorDriver *m4, motorDriver *m5);
        multiMotor(motorDriver *motors[6]);
        void setSpeed(float s0, float s1, float s2, float s3, float s4, float s5);
        void setSpeed(float s[6]);
        void stop();
        float *getSpeeds();

    };
}

#endif //ARDUINO2_MULTIMOTOR_H
