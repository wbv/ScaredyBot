/* Pin Assignments */
#define LEFT_MOTOR_3A4A 6
#define LEFT_MOTOR_3A 8
#define LEFT_MOTOR_4A 7
#define RIGHT_MOTOR_1A2A 5
#define RIGHT_MOTOR_1A 10
#define RIGHT_MOTOR_2A 9
#define VELOCITY 100

bool serial_begun = false;

#include "motors.h"
#include "sonar_scaredy.h"

void setup() {
  motors_setup();
  sonar_setup();
  Serial.begin(9600);
}

void loop() {

  cry();
  //motor_selftest();
  //sonar_selftest();
//  motor_speed(LEFT_MOTOR, 100);
//  motor_speed(RIGHT_MOTOR, 100);


if (distance_cm(SFRONT) < 10.0 && distance_cm(SFRONT) != 0){
   //backwards
   Serial.println("backwards");
   backwards(1000, VELOCITY);
   delay(49);
}   
else if (distance_cm(SFRONT_L) < 10.0 && distance_cm(SFRONT_L) != 0){
   //turn 45 CC
   Serial.println("turn 45 CC and go backwards");
   counter_clockwise(125, VELOCITY);
   backwards(500, VELOCITY);
   delay(49);
}   
else if (distance_cm(SLEFT) < 10.0 && distance_cm(SLEFT) != 0){
   //turn 90 CC
   Serial.println("turn 90 cc and go backwards");
   counter_clockwise(250, VELOCITY);
   backwards(500, VELOCITY);
   delay(49);
}   
else if (distance_cm(SBACK_L) < 10.0 && distance_cm(SBACK_L) != 0){
   //turn 45 C
   Serial.println("45 C forwards");
   clockwise(125, VELOCITY);
   forward(500, VELOCITY);
   delay(49);
}   
else if (distance_cm(SBACK) < 10.0 && distance_cm(SBACK) != 0){
   //go forward
   Serial.println("forwards");
   forward(500, VELOCITY);  
   delay(49);
}  
else if (distance_cm(SBACK_R) < 10.0 && distance_cm(SBACK_R) != 0){
   //turn 45 CC
   Serial.println("45 CC and forward");
   counter_clockwise(125, VELOCITY);
   forward(500, VELOCITY);
   delay(49);
}   
else if (distance_cm(SRIGHT) < 10.0 && distance_cm(SRIGHT) != 0){
   //turn 90 CC
   Serial.println("90 CC forwards");
   counter_clockwise(250, VELOCITY);
   forward(500, VELOCITY);
   delay(49);
}  
else if (distance_cm(SFRONT_R) < 10.0 && distance_cm(SFRONT_R) != 0){
   // turn 45 C
   Serial.println("45 C backwards");
   clockwise(125, VELOCITY);
   backwards(500, VELOCITY);
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
void cry(){
  for(int i = 0; i < 1000; i++){
    tone(11, i);
    delay(15);
  }
  for(int j = 0; j < 1000; j++){
    tone(11, 1000-j);
    delay(15);
  }
}
