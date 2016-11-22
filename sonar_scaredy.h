
typedef struct {
  int trig;
  int echo;
} sonar_pinout_t;

const sonar_pinout_t SFRONT =   {32, 33}, 
                     SFRONT_L = {30, 31}, 
                     SLEFT =    {28, 29}, 
                     SBACK_L =  {26, 27}, 
                     SBACK =    {24, 25}, 
                     SBACK_R =  {22, 23}, 
                     SRIGHT =   {36, 37}, 
                     SFRONT_R = {34, 35};

const int sonar_sensors_size = 8;
const sonar_pinout_t sonar_sensors[sonar_sensors_size] = {
  SFRONT, SFRONT_L, SLEFT, SBACK_L,
  SBACK, SBACK_R, SRIGHT, SFRONT_R
};

void sonar_setup() {
  for (int i = 0; i < sonar_sensors_size; i++) {
    pinMode(sonar_sensors[i].trig, OUTPUT);
    pinMode(sonar_sensors[i].echo, INPUT);
  }
}

float distance_cm(int trigpin, int echopin) {
  /* DELAY TO ALLOW OTHER SENSORS TIME TO FINISH */
  delay(10);
  
  digitalWrite(trigpin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(20); // Added this line
  digitalWrite(trigpin, LOW);
  
  return pulseIn(echopin, HIGH, 9001) / 58.2;
}

float distance_cm(sonar_pinout_t s) {
  return distance_cm(s.trig, s.echo);
}


void sonar_selftest() {
  /* TEST SONAR */
  if (!serial_begun) {
    Serial.begin(9600);
    serial_begun = true;
  }

  size_t time_to_run = millis();
  size_t n = 0; // for formatting
  Serial.println("FRONT   FRONT_L LEFT    BACK_L  BACK    BACK_R  RIGHT   FRONT_R ");
  for (size_t i = 0; i < sonar_sensors_size; i++) {
    n = Serial.print(distance_cm(sonar_sensors[i]));
    while (n++ < 8) Serial.print(' ');
  }
  Serial.print("\nTime to run:");
  Serial.print(millis() - time_to_run);
  Serial.print("\n");
  delay(1000);
}

