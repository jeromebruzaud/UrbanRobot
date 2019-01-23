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
        double mSpeed;
        double mAngular_speed;

    public:
        multiMotor(motorDriver m1, motorDriver m2, motorDriver m3, motorDriver m4, motorDriver m5, motorDriver m6);
        void forward();
        void backward();
        void speed(double speed);
        void turnLeft();
        void turnRight();
        void stop();
        int[] getEncoders();

    };
}

#endif //ARDUINO2_MULTIMOTOR_H
