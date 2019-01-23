//
// Created by larnal on 23/01/19.
//

#include "../include/motorDriver.h"

using namespace std;

namespace driver{
    motorDriver::motorDriver(unsigned int pwm, unsigned int bridge1, unsigned int bridge2, unsigned int encoder1, unsigned int encoder2) : mPwm(pwm), mBridge1(bridge1), mBridge2(bridge2), mEncoder1(encoder1), mEncoder2(encoder2), mCounter(0){
        //PWM
        pinMode(mPwm, OUTPUT);
        // H-bridge direction control
        pinMode(mBridge1, OUTPUT);
        pinMode(mBridge2, OUTPUT);
        // encoders
        pinMode(mEncoder1, INPUT);
        pinMode(mEncoder2, INPUT);

        analogWrite(mPwm, 0); //set PWM to 0
        digitalWrite(mBridge1, LOW); // set H-bridge to STOP
        digitalWrite(mBridge2, LOW);

        // interrupt for encoders
        attachInterrupt(digitalPinToInterrupt(encoder1), encoderChange, CHANGE);

        mCounter = 0;
    }

    void motorDriver::encoderChange(){
        if ((digitalRead(mEncoder1) == HIGH and digitalRead(mEncoder2) == HIGH)
            or (digitalRead(mEncoder1) == LOW and digitalRead(mEncoder2) == LOW)) {
            mCounter++;
        } else {
            mCounter--;
        }
    }

    void motorDriver::run(unsigned int pwm_value){
        pwm_value = max(pwm_value, 255)
        analogWrite(mPwm, pwm_value);
    }

    void motorDriver::stop(){
        analogWrite(mPwm, 0);
    }

    void motorDriver::direction(int direction){
        if (direction == -1) {
            digitalWrite(mBridge1, HIGH);
            digitalWrite(mBridge2, LOW);
        } else if (direction == 1) {
            digitalWrite(mBridge1, LOW);
            digitalWrite(mBridge2, HIGH);
        } else {
            digitalWrite(mBridge1, LOW);
            digitalWrite(mBridge2, LOW);
        }
    }

}