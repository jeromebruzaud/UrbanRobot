//
// Created by larnal on 23/01/19.
//

#include "multiMotor.h"
namespace driver{

    multiMotor::multiMotor(motorDriver m1, motorDriver m2, motorDriver m3, motorDriver m4, motorDriver m5, motorDriver m6) : mMotor1(m1), mMotor2(m2), mMotor3(m3), mMotor4(m4), mMotor5(m5), mMotor6(m6){
        mSpeed = 0;
        mAngular_speed = 0;
        stop();
    }

    void multiMotor::forward(){
        mMotor1.direction(1);
        mMotor2.direction(1);
        mMotor3.direction(1);
        mMotor4.direction(1);
        mMotor5.direction(1);
        mMotor6.direction(1);

    }

    void multiMotor::backward(){
        mMotor1.direction(-1);
        mMotor2.direction(-1);
        mMotor3.direction(-1);
        mMotor4.direction(-1);
        mMotor5.direction(-1);
        mMotor6.direction(-1);
    }

    void multiMotor::turnLeft(){
        stop();
        mMotor2.direction(-1);
        mMotor4.direction(-1);
        mMotor6.direction(-1);
        mMotor1.direction(1);
        mMotor3.direction(1);
        mMotor5.direction(1);
    }

    void multiMotor::turnRight(){
        stop();
        mMotor2.direction(1);
        mMotor4.direction(1);
        mMotor6.direction(1);
        mMotor1.direction(-1);
        mMotor3.direction(-1);
        mMotor5.direction(-1);
    }

    void multiMotor::speed(double speed){
        mSpeed = speed; // not used yet
        unsigned int pwm = (unsigned int) map(speed, 0, 1, 0, 255);
        mMotor1.run(pwm);
        mMotor2.run(pwm);
        mMotor3.run(pwm);
        mMotor4.run(pwm);
        mMotor5.run(pwm);
        mMotor6.run(pwm);
    }

    void multiMotor::stop(){
        mMotor1.run(0);
        mMotor2.run(0);
        mMotor3.run(0);
        mMotor4.run(0);
        mMotor5.run(0);
        mMotor6.run(0);
        forward();
    }

    int[] getEncoder() {
        int[] counters = {mMotor1.getEncoder(),
                          mMotor2.getEncoder(),
                          mMotor3.getEncoder(),
                          mMotor4.getEncoder(),
                          mMotor5.getEncoder(),
                          mMotor6.getEncoder()};

        return counters;
    }

}
