//
// Created by larnal on 23/01/19.
//

#include "motorDriver.h"

#define FORWARD 1
#define BACKWARD -1
#define STOP 0

using namespace std;

namespace driver{
    motorDriver::motorDriver(unsigned int pwm, unsigned int bridge1, unsigned int bridge2, unsigned int encoder1, unsigned int encoder2, unsigned int gearRatio, unsigned int encoder_res) : mPwm(pwm), mBridge1(bridge1), mBridge2(bridge2), mEncoder1(encoder1), mEncoder2(encoder2), mGearRatio(gearRatio), mEncoderRes(encoder_res), mPwm_value(0), mDirection(STOP), mTimer(0){
    }

    void motorDriver::init() {
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

        mTimer = millis();
    }

    void motorDriver::run(float pwm_value){
        /* Make the motor run or stop if pwm_value is 0.
         * pwm_value must be given between -1 and 1, -1 is maximum speed backward and 1 maximum speed forward. 0 means
         * you stop the motor.
         */
        mPwm_value = max(-1, min(1, pwm_value)); // mPwm_value between -1 and 1

        if (mPwm_value == 0) { // if 0, stop the motor and set direction forward
            stop();
        } else {
            int dir = (mPwm_value > 0 ? FORWARD : BACKWARD); // direction is -1 or +1
            if (dir != mDirection) {
                stop();
                direction(dir);
            }
            mDirection = dir;
            rotate(fabs(mPwm_value));
        }

    }

    void motorDriver::direction(int dir){
        /*
         * change motor direction from bridge gate control.
         * -1 = backward
         * 0 or else = emergency stop
         * +1 = forward
         */
        if (dir == BACKWARD) {
            digitalWrite(mBridge1, LOW);
            digitalWrite(mBridge2, HIGH);
        } else if (dir == FORWARD) {
            digitalWrite(mBridge1, HIGH);
            digitalWrite(mBridge2, LOW);
        } else {
            digitalWrite(mBridge1, LOW);
            digitalWrite(mBridge2, LOW);
        }
    }

    void motorDriver::stop(){
        /*
         * Stop the motor by sending a 0 pwm
         */
        rotate(0);
    }

    void motorDriver::rotate(float pwm_value){
        // apply a pwm.
        unsigned int pwm = (unsigned int) (pwm_value * 255);
        analogWrite(mPwm, 70);
        delay(30);
    }

    void motorDriver::encoderChange(){
        /*
         * Method called by an interrupt.
         * Increment the encoder counter if rotating forward
         * Decrement if rotating backward
         */
        mSpeed = (float) mGearRatio / ((float) mEncoderRes * (millis() - mTimer));
        if (digitalRead(mEncoder1) != digitalRead(mEncoder2)) {
            mSpeed = -mSpeed;
        }
        mTimer = millis();
    }

    float motorDriver::getSpeed(){
        /*
         * Return the value of the counter
         */
        return mSpeed;
    }

}
