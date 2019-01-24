//
// Created by larnal on 23/01/19.
//

#include "motorDriver.h"

#define FORWARD 1
#define BACKWARD -1
#define STOP 0

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
        //attachInterrupt(digitalPinToInterrupt(encoder1), encoderChange, CHANGE);

        mCounter = 0;
        mPwm_value = 0;
        mDirection = STOP;
    }

    void motorDriver::run(float pwm_value){
        /* Make the motor run or stop if pwm_value is 0.
         * pwm_value must be given between -1 and 1, -1 is maximum speed backward and 1 maximum speed forward. 0 means
         * you stop the motor.
         */
        mPwm_value = max(-1, min(1, pwm_value)); // mPwm_value between -1 and 1

        if (mPwm_value == 0) { // if 0, stop the motor and set direction forward
            this->stop();
        } else {
            int direction = (mPwm_value > 0 ? FORWARD : BACKWARD); // direction is -1 or +1
            if (direction != mDirection) {
                this->stop();
                this->direction(direction);
            }
            mDirection = direction;
            this->rotate((unsigned int)fabs(mPwm_value));
        }

    }

    void motorDriver::direction(int direction){
        /*
         * change motor direction from bridge gate control.
         * -1 = backward
         * 0 = emergency stop
         * +1 = forward
         */
        if (direction == BACKWARD) {
            digitalWrite(mBridge1, HIGH);
            digitalWrite(mBridge2, LOW);
        } else if (direction == FORWARD) {
            digitalWrite(mBridge1, LOW);
            digitalWrite(mBridge2, HIGH);
        } else {
            digitalWrite(mBridge1, LOW);
            digitalWrite(mBridge2, LOW);
        }
    }

    void motorDriver::stop(){
        /*
         * Stop the motor by sending a 0 pwm
         */
        this->rotate(0);
    }

    void motorDriver::rotate(unsigned int pwm_value){
        // apply a pwm.
        pwm_value = map(pwm_value, 0, 1, 0, 255);
        analogWrite(mPwm, pwm_value);
        delay(30);
    }

    // void motorDriver::encoderChange(){
    //     /*
    //      * Method called by an interrupt.
    //      * Increment the encoder counter if rotating forward
    //      * Decrement if rotating backward
    //      */
    //     if ((digitalRead(mEncoder1) == HIGH and digitalRead(mEncoder2) == HIGH)
    //         or (digitalRead(mEncoder1) == LOW and digitalRead(mEncoder2) == LOW)) {
    //         mCounter++;
    //     } else {
    //         mCounter--;
    //     }
    // }

    // int getEncoder(){
    //     /*
    //      * Return the value of the counter
    //      */
    //     return mCounter;
    // }

}
