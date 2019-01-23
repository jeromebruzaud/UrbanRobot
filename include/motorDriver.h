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
        void encoderChange();
        void run(unsigned int pwm_value);
        void stop();
        void direction(int direction);
    }
}

#endif //ARDUINO_MOTORDRIVER_H
