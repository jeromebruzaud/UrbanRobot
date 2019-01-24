#include <Arduino.h>



#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WProgram.h>
#endif

#include <multiMotor.h>
#include <ros.h>
#include <geometry_msgs/Twist.h>

//pin for PWM
// 1 pwm L = bridge 1, motor Left
#define bridge1pwmL 13
#define bridge1pwmR 12

#define bridge2pwmL 11
#define bridge2pwmR 10

#define bridge3pwmL 9
#define bridge3pwmR 8

//pin for H-bridge
#define bridge1in1 37
#define bridge1in2 35
#define bridge1in3 33
#define bridge1in4 31

#define bridge2in1 36
#define bridge2in2 34
#define bridge2in3 32
#define bridge2in4 30

#define bridge3in1 47
#define bridge3in2 45
#define bridge3in3 43
#define bridge3in4 41

//input pin for encoders
// 1L = bridge 1, motor Left, encoder with interrupt
// 1L2 = bridge 1, motor Left, encoder without interrupt
#define en1L 2
#define en1R 3
#define en2L 18
#define en2R 19
#define en3L 20
#define en3R 21

#define en1L2 24
#define en1R2 25
#define en2L2 26
#define en2R2 27
#define en3L2 28
#define en3R2 29

ros::NodeHandle  nh;

motorDriver m1L;
motorDriver m1R;
motorDriver m2L;
motorDriver m2R;
motorDriver m3L;
motorDriver m3R;
multiMotor robotMotors;


void robot_command( const std_msgs::Twist& cmd_msg){
    float speed = (float) cmd_msg.linear.x;
    robotMotors.setSpeed(speed, speed, speed, speed, speed, speed);
}

ros::Subscriber<std_msgs::Twist> sub("cmd_vel", robot_command);

void setup() {
    m1L; = new motorDriver(bridge1pwmL, bridge1in1, bridge1in2, en1L, en1L2);
    m1R; = new motorDriver(bridge1pwmR, bridge1in3, bridge1in4, en1R, en1R2);
    m2L; = new motorDriver(bridge2pwmL, bridge2in1, bridge2in2, en2L, en2L2);
    m2R; = new motorDriver(bridge2pwmR, bridge2in3, bridge2in4, en2R, en2R2);
    m3L; = new motorDriver(bridge3pwmL, bridge3in1, bridge3in2, en3L, en3L2);
    m3R; = new motorDriver(bridge3pwmR, bridge3in3, bridge3in4, en3R, en3R2);

    robotMotors = new multiMotor(m1L, m1R, m2L, m2R, m3L, m3R);

    nh.initNode();
    nh.subscribe(sub);
}

void loop() {
    nh.spinOnce();
    delay(1);
}
