/*
 * NOTES:
 * 
 * Motors work at 12V, probably run at 9V
 * 
 * Connect Power supply to 12V input on H-Bridge
 * Connect Arduino/H-Bridge ground to ground on Power supply
 * 
 * OUT2/OUT3: DC+
 * OUT1/OUT4: DC-
 */


// Left Motor Pins
int PIN_IN1 = 8;
int PIN_IN2 = 9;
int PIN_ENA = 3;

// Right Motor Pins
int PIN_IN3 = 12;
int PIN_IN4 = 13;
int PIN_ENB = 2;

// Helper functions
void driveForward(int power) {
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  analogWrite(PIN_ENA, power);

  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENB, power); 
}

void driveBackwards(int power) {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  analogWrite(PIN_ENA, power);

  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
  analogWrite(PIN_ENB, power); 
}

void turnLeft(int power) {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  analogWrite(PIN_ENA, 0);

  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENB, power); 
}

void turnRight(int power) {
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  analogWrite(PIN_ENA, power);

  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENB, 0); 
}

void setup() {
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_ENA, OUTPUT);

  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  driveForward(255);
  delay(2000);
  driveBackwards(255);
  delay(2000);
}
