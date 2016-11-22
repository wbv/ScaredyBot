/* Pin Assignments */
#define LEFT_MOTOR_3A4A 6
#define LEFT_MOTOR_3A 8
#define LEFT_MOTOR_4A 7
#define RIGHT_MOTOR_1A2A 5
#define RIGHT_MOTOR_1A 10
#define RIGHT_MOTOR_2A 9

bool serial_begun = false;

#include "motors.h"
#include "sonar_scaredy.h"

void setup() {
  motors_setup();
  sonar_setup();
}

void loop() {
  //motor_selftest();
  //sonar_selftest();
//  motor_speed(LEFT_MOTOR, 100);
//  motor_speed(RIGHT_MOTOR, 100);
}
