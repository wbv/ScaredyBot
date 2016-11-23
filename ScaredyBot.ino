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
  Serial.begin(9600);
}

void loop() {

  
  //motor_selftest();
  //sonar_selftest();
//  motor_speed(LEFT_MOTOR, 100);
//  motor_speed(RIGHT_MOTOR, 100);

//CC 90
//if (distance_cm(SFRONT) < 10.0 && distance_cm(SFRONT) != 0){
//  motor_speed(LEFT_MOTOR, -100);
//  motor_speed(RIGHT_MOTOR, 100);
//  delay(250);
//  motor_speed(LEFT_MOTOR, 0);
//  motor_speed(RIGHT_MOTOR, 0);  
//}



if (distance_cm(SFRONT) < 10.0 && distance_cm(SFRONT) != 0){
   //backwards
   Serial.println("SFRONT < 10.0");
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, -100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}   
else if (distance_cm(SFRONT_L) < 10.0 && distance_cm(SFRONT_L) != 0){
   //turn 45 CC
   Serial.println("SFRONT_L < 10.0");
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(125);
   //Go backwards
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, -100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}   
else if (distance_cm(SLEFT) < 10.0 && distance_cm(SLEFT) != 0){
   //turn 90 CC
   Serial.println("SLEFT < 10.0");
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(250);
   //Go backwards
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, -100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}   
else if (distance_cm(SBACK_L) < 10.0 && distance_cm(SBACK_L) != 0){
   //turn 45 C
   Serial.println("SBACK_L < 10.0");
   motor_speed(LEFT_MOTOR, 100);
   motor_speed(RIGHT_MOTOR, -100);
   delay(125);
   //Go forwards
   motor_speed(LEFT_MOTOR, 100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}   
else if (distance_cm(SBACK) < 10.0 && distance_cm(SBACK) != 0){
   //go forward
   Serial.println("SBACK < 10.0");
   motor_speed(LEFT_MOTOR, 100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}  
else if (distance_cm(SBACK_R) < 10.0 && distance_cm(SBACK_R) != 0){
   //turn 45 CC
   Serial.println("SBACK_R < 10.0");
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(125);
   //go forward
   motor_speed(LEFT_MOTOR, 100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}   
else if (distance_cm(SRIGHT) < 10.0 && distance_cm(SRIGHT) != 0){
   //turn 90 CC
   Serial.println("SRIGHT < 10.0");
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(250);
   //go forward
   motor_speed(LEFT_MOTOR, 100);
   motor_speed(RIGHT_MOTOR, 100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}  
else if (distance_cm(SFRONT_R) < 10.0 && distance_cm(SFRONT_R) != 0){
   // turn 45 C
   Serial.println("SFRONT_R < 10.0");
   motor_speed(LEFT_MOTOR, 100);
   motor_speed(RIGHT_MOTOR, -100);
   delay(125);
   //go backward
   motor_speed(LEFT_MOTOR, -100);
   motor_speed(RIGHT_MOTOR, -100);
   delay(400);
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}   
else {
   //stay still
   Serial.println("Everything is ok");
   motor_speed(LEFT_MOTOR, 0);
   motor_speed(RIGHT_MOTOR, 0);
   delay(49);
}



}
