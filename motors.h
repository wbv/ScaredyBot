/* Custom-written "library" for interacting with the robot.
 * Call motor_speed() with a motor side and a speed (-255, 255)
 * where -255 is full throttle backwards, 255 is full forwards,
 * and 0 is stop.
 */

/* Arduino pin assignments, these should be made in the 
 * document which uses the library, but in case they aren'table
 * defined, we fall back to these defaults */
#ifndef LEFT_MOTOR_3A4A
#define LEFT_MOTOR_3A4A 6
#endif

#ifndef LEFT_MOTOR_3A
#define LEFT_MOTOR_3A 8
#endif

#ifndef LEFT_MOTOR_4A
#define LEFT_MOTOR_4A 7
#endif

#ifndef RIGHT_MOTOR_1A2A
#define RIGHT_MOTOR_1A2A 5
#endif

#ifndef RIGHT_MOTOR_1A
#define RIGHT_MOTOR_1A 10
#endif

#ifndef RIGHT_MOTOR_2A
#define RIGHT_MOTOR_2A 9
#endif

int left_speed;
int right_speed;

/* constants for each motor */
typedef enum {
	LEFT_MOTOR,
	RIGHT_MOTOR
} 
motor_t;

/* constants referring to motor directions */
typedef enum {
	CW,  
	CCW,
	STOP
} 
control_t;


/* Call with a motor side and a direction to 
 * change the "mode" of the h-bridge motor controller
 */
void hbridge_mode(int m_side, int c_type) {
  switch (m_side) { 
    case LEFT_MOTOR: 
    switch (c_type) { 
      case CCW: // set the Left Motor CW 
        digitalWrite(LEFT_MOTOR_3A, HIGH);
        digitalWrite(LEFT_MOTOR_4A, LOW); 
        break;
      case CW: // set the Left Motor CCW 
        digitalWrite(LEFT_MOTOR_3A, LOW);
        digitalWrite(LEFT_MOTOR_4A, HIGH); 
        break; 
      case STOP: // set the Left Motor stop 
        analogWrite(LEFT_MOTOR_3A4A, 0); // set Left Motor enable high for braking 
        digitalWrite(LEFT_MOTOR_3A, LOW); 
        digitalWrite(LEFT_MOTOR_4A, LOW); 
        break; 
      default: break; // Should never get here  
    } 
    case RIGHT_MOTOR: 
    /* Your code here for right motor */ 
    switch (c_type) { 
      case CCW: // set right motor clockwise
        digitalWrite(RIGHT_MOTOR_1A, HIGH); 
        digitalWrite(RIGHT_MOTOR_2A, LOW); 
        break; 
      case CW: //set the right motor counter clockwise 
        digitalWrite(RIGHT_MOTOR_1A, LOW); 
        digitalWrite(RIGHT_MOTOR_2A, HIGH); 
        break; 
      case STOP: //Set to stop 
        analogWrite(RIGHT_MOTOR_1A2A, 0); 
        digitalWrite(RIGHT_MOTOR_1A, LOW); 
        digitalWrite(RIGHT_MOTOR_2A, LOW); 
        break; 
	  default: break; // should never get here
    } 
  }
}


/* Call this with a motor side (RIGHT MOTOR, LEFT MOTOR)
 * and a speed (-100, 100).
 */
void motor_speed(int m_side, int speed) {
	// if setting the motor speed to 0
	if (speed == 0) {
		hbridge_mode( m_side, STOP );
		return;
	}

 if (speed > 100) speed = 100;
 if (speed < -100) speed = -100;
	
	if (speed < 0) {
		speed *= -1;
		hbridge_mode( m_side, CW );
	} else {
		hbridge_mode( m_side, CCW );
	}
	
	if (m_side == LEFT_MOTOR)
		analogWrite( LEFT_MOTOR_3A4A, round(map(speed, 0, 100, 0, 255)));
	else
		analogWrite( RIGHT_MOTOR_1A2A, round(map(speed, 0, 100, 0, 255)));
	return;
}
//
int counter_clockwise(int duration, int velocity){
  motor_speed(LEFT_MOTOR, velocity);
  motor_speed(RIGHT_MOTOR, -1*velocity);
  delay(duration);
  motor_speed(LEFT_MOTOR, 0);
  motor_speed(RIGHT_MOTOR, 0);   
}
int clockwise(int duration, int velocity){
  motor_speed(LEFT_MOTOR, -1*velocity);
  motor_speed(RIGHT_MOTOR, velocity);
  delay(duration);
  motor_speed(LEFT_MOTOR, 0);
  motor_speed(RIGHT_MOTOR, 0);
}
int backwards(int duration, int velocity){
  motor_speed(LEFT_MOTOR, -1*velocity);
  motor_speed(RIGHT_MOTOR, -1*velocity);
  delay(duration);
  motor_speed(LEFT_MOTOR, 0);
  motor_speed(RIGHT_MOTOR, 0);
}
int forward(int duration, int velocity){
  motor_speed(LEFT_MOTOR, velocity);
  motor_speed(RIGHT_MOTOR, velocity);
  delay(duration);
  motor_speed(LEFT_MOTOR, 0);
  motor_speed(RIGHT_MOTOR, 0);
}

void motors_setup() {
  /* Set up pins */
  pinMode(LEFT_MOTOR_3A4A, OUTPUT);
  pinMode(LEFT_MOTOR_3A, OUTPUT);
  pinMode(LEFT_MOTOR_4A, OUTPUT);
  pinMode(RIGHT_MOTOR_1A2A, OUTPUT);
  pinMode(RIGHT_MOTOR_1A, OUTPUT);
  pinMode(RIGHT_MOTOR_2A, OUTPUT);
  motor_speed(LEFT_MOTOR, 0);
  motor_speed(RIGHT_MOTOR, 0);
}

void motor_selftest() {
	int motors[2] = {LEFT_MOTOR, RIGHT_MOTOR};

  // for each motor, speed up, slow down,
  // go into reverse, go back to stop.
  for (int motor = 0; motor <= 1; motor++) { 
    for (int i = 0; i <= 100; i++) {
      motor_speed(motors[motor], i);
      delay(10);
      Serial.print(i); Serial.print(" ...\n");
    }
    for (int i = 100; i >= -100; i--) {
      motor_speed(motors[motor], i);
      delay(10);
      Serial.print(i); Serial.print(" ...\n");
    }
    for (int i = -100; i <= 0; i++) {
      motor_speed(motors[motor], i);
      delay(10);
      Serial.print(i); Serial.print(" ...\n");
    }
    delay(1000);
  }

  delay(2000);
}
