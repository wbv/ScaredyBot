/* Pin Assignments */
#define LEFT_MOTOR_3A4A 6
#define LEFT_MOTOR_3A 8
#define LEFT_MOTOR_4A 7
#define RIGHT_MOTOR_1A2A 5
#define RIGHT_MOTOR_1A 10
#define RIGHT_MOTOR_2A 9

#define CRY_PIN 11

#define VELOCITY 100
#define RANGE 20.0

#include "motors.h"
#include "sonar_scaredy.h"
#include "cry.h"

typedef enum {
  SFRONT = 0,
  SFRONT_L, 
  SLEFT, 
  SBACK_L,
  SBACK,
  SBACK_R,
  SRIGHT,
  SFRONT_R
} sensor_t;

void setup() {
  motors_setup();
  sonar_setup();
  Serial.begin(9600);
}

void loop() {

  //cry_selftest();
  //cry();
  //motor_selftest();
  //sonar_selftest();
  //motor_speed(LEFT_MOTOR, 100);
  //motor_speed(RIGHT_MOTOR, 100);


//if (distance_cm(SFRONT) < RANGE && distance_cm(SFRONT) != 0){
//   //backwards
//   Serial.println("backwards");
//   //cry();
//   backwards(1000, VELOCITY);
//   delay(49);
//}   
//else if (distance_cm(SFRONT_L) < RANGE && distance_cm(SFRONT_L) != 0){
//   //turn 45 CC
//   Serial.println("turn 45 CC and go backwards");
//   //cry();
//   counter_clockwise(125, VELOCITY);
//   backwards(500, VELOCITY);
//   delay(49);
//}   
//else if (distance_cm(SLEFT) < RANGE && distance_cm(SLEFT) != 0){
//   //turn 90 CC
//   Serial.println("turn 90 cc and go backwards");
//   //cry();
//   counter_clockwise(250, VELOCITY);
//   backwards(500, VELOCITY);
//   delay(49);
//}   
//else if (distance_cm(SBACK_L) < RANGE && distance_cm(SBACK_L) != 0){
//   //turn 45 C
//   Serial.println("45 C forwards");
//   //cry();
//   clockwise(125, VELOCITY);
//   forward(500, VELOCITY);
//   delay(49);
//}   
//else if (distance_cm(SBACK) < RANGE && distance_cm(SBACK) != 0){
//   //go forward
//   Serial.println("forwards");
//   //cry();
//   forward(500, VELOCITY);  
//   delay(49);
//}  
//else if (distance_cm(SBACK_R) < RANGE && distance_cm(SBACK_R) != 0){
//   //turn 45 CC
//   Serial.println("45 CC and forward");
//   //cry();
//   counter_clockwise(125, VELOCITY);
//   forward(500, VELOCITY);
//   delay(49);
//}   
//else if (distance_cm(SRIGHT) < RANGE && distance_cm(SRIGHT) != 0){
//   //turn 90 CC
//   Serial.println("90 CC forwards");
//   //cry();
//   counter_clockwise(250, VELOCITY);
//   forward(500, VELOCITY);
//   delay(49);
//}  
//else if (distance_cm(SFRONT_R) < RANGE && distance_cm(SFRONT_R) != 0){
//   // turn 45 C
//   Serial.println("45 C backwards");
//   
//   clockwise(125, VELOCITY);
//   backwards(500, VELOCITY);
//   delay(49);
//}   
//else {
//   //stay still
//   Serial.println("Everything is ok");
//   motor_speed(LEFT_MOTOR, 0);
//   motor_speed(RIGHT_MOTOR, 0);
//   delay(49);
//}



}

