//
// Created by larnal on 23/01/19.
//

#include "multiMotor.h"
namespace driver{

    multiMotor::multiMotor(motorDriver m1, motorDriver m2, motorDriver m3, motorDriver m4, motorDriver m5, motorDriver m6) : mMotor1(m1), mMotor2(m2), mMotor3(m3), mMotor4(m4), mMotor5(m5), mMotor6(m6){
        stop();
    }

    void multiMotor::setSpeed(float s1, float s2, float s3, float s4, float s5, float s6){
        mMotor1.run(s1);
        mMotor2.run(s2);
        mMotor3.run(s3);
        mMotor4.run(s4);
        mMotor5.run(s5);
        mMotor6.run(s6);
    }

    void multiMotor::stop(){
        mMotor1.run(0);
        mMotor2.run(0);
        mMotor3.run(0);
        mMotor4.run(0);
        mMotor5.run(0);
        mMotor6.run(0);
    }

    // int[] getEncoder() {
    //     int[] counters = {mMotor1.getEncoder(),
    //                       mMotor2.getEncoder(),
    //                       mMotor3.getEncoder(),
    //                       mMotor4.getEncoder(),
    //                       mMotor5.getEncoder(),
    //                       mMotor6.getEncoder()};

    //     return counters;
    // }

}
