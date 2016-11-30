
typedef struct {
  int trig;
  int echo;
} sonar_pinout_t;

const size_t sonar_sensors_size = 8;
const sonar_pinout_t sonar_sensors[sonar_sensors_size] = {
  {32, 33}, {30, 31}, {28, 29}, {26, 27}, 
  {24, 25}, {22, 23}, {36, 37}, {34, 35}
};

void sonar_setup() {
  for (size_t i = 0; i < sonar_sensors_size; i++) {
    pinMode(sonar_sensors[i].trig, OUTPUT);
    pinMode(sonar_sensors[i].echo, INPUT);
  }
}

double distance_cm(int trigpin, int echopin) {
  long unsigned duration;
  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigpin, LOW);
  delayMicroseconds(100);
  /* sonar not meant to be called more than once per
     60ms anyway, so timeout at 60ms */
  duration = pulseIn(echopin, HIGH, 60000);
  if (duration > 0)
    delayMicroseconds(60000 - duration);
  return duration / 58.24;
}

float distance_cm(sonar_pinout_t s) {
  return distance_cm(s.trig, s.echo);
}


void sonar_selftest() {
  /* TEST SONAR */
  Serial.begin(9600);

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

double* sonar_sweep() {
  /* sweep through all the sonar sensors */
  for (size_t i = 0; i < sonar_sensors_size; i++) {
    // do things
  }
}

