//
// Created by larnal on 23/01/19.
//

#include "multiMotor.h"
namespace driver{

    multiMotor::multiMotor(motorDriver *m0, motorDriver *m1, motorDriver *m2, motorDriver *m3, motorDriver *m4, motorDriver *m5) {
        mMotors[0] = m0;
        mMotors[1] = m1;
        mMotors[2] = m2;
        mMotors[3] = m3;
        mMotors[4] = m4;
        mMotors[5] = m5;
        stop();
    }

    multiMotor::multiMotor(motorDriver *motors[6]){
        for (int i = 0; i < 6; ++i) {
            mMotors[i] = motors[i];
        }
        stop();
    }

    void multiMotor::setSpeed(float s0, float s1, float s2, float s3, float s4, float s5){
        mMotors[0]->run(s0);
        mMotors[1]->run(s1);
        mMotors[2]->run(s2);
        mMotors[3]->run(s3);
        mMotors[4]->run(s4);
        mMotors[5]->run(s5);
    }

    void multiMotor::setSpeed(float s[6]){
        for (int i = 0; i < 6; ++i) {
            mMotors[i]->run(s[i]);
        }
    }

    void multiMotor::stop(){
        float speed[6] = {0.0};
        setSpeed(speed);
    }

    float *multiMotor::getSpeeds(){
        float speeds[6];
        for (int i = 0; i < 6; i++) {
            speeds[i] = mMotors[i]->getSpeed();
        }
        return speeds;
    }
}
