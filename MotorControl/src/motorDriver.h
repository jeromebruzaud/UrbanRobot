//
// Created by larnal on 23/01/19.
//

#ifndef ARDUINO_MOTORDRIVER_H
#define ARDUINO_MOTORDRIVER_H

namespace driver{

    class motorDriver{
// counters for each encoder
    private:
        volatile int mCounter;

        unsigned int mPwm;
        unsigned int mBridge1;
        unsigned int mBridge2;
        unsigned int mEncoder1;
        unsigned int mEncoder2;

    public:
        motorDriver(unsigned int pwm, unsigned int bridge1, unsigned int bridge2, unsigned int encoder1, unsigned int encoder2);
        void encoderChange();
        void run(unsigned int pwm_value);
        void stop();
        void direction(int direction);
        int getEncoder();
    }
}

#endif //ARDUINO_MOTORDRIVER_H
