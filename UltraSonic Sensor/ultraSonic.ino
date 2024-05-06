const int TRIG_PIN   = 9; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN   = 10; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int BUZZER_PIN = 2; // Arduino pin connected to Piezo Buzzer's pin
const int DISTANCE_THRESHOLD = 30; // centimeters

// variables will change:
float duration_us, distance_cm;

void setup() {
  Serial.begin (9600);         // initialize serial port
  pinMode(TRIG_PIN, OUTPUT);   // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);    // set arduino pin to input mode
  pinMode(BUZZER_PIN, OUTPUT); // set arduino pin to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us;

  if(distance_cm < DISTANCE_THRESHOLD)
    {
      digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
      delay(100);
      digitalWrite(BUZZER_PIN, LOW);
      delay(3);
      if(distance_cm <15){
       digitalWrite(BUZZER_PIN, HIGH); // turn on Piezo Buzzer
       
      }
   
    }
  else
    digitalWrite(BUZZER_PIN, LOW);  // turn off Piezo Buzzer

  // print the value to Serial Monitor
  Serial.print("distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}