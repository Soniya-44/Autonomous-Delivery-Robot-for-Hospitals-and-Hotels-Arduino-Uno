
# Autonomous-Delivery-Robot-for-Hospitals-and-Hotels-Arduino-Uno
Arduino Uno based autonomous delivery robot using HC-SR04 ultrasonic sensor and L298N motor driver for hospitals/hotels. Moves forward, measures distance continuously, avoids obstacles &lt;20cm by turning. Enables contactless delivery of medicines/food, reduces human workload. Low-cost, battery-operated, coded in Embedded C.
#define TRIG_PIN 9
#define ECHO_PIN 10
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6

long duration; int distance; int safeDistance = 20;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT); pinMode(ECHO_PIN, INPUT);
  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
}
int measureDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}
void forward(){ digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW); }
void backward(){ digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH); digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH); }
void turnRight(){ digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); }
void stopRobot(){ digitalWrite(IN1, LOW); digitalWrite(IN2, LOW); digitalWrite(IN3, LOW); digitalWrite(IN4, LOW); }
void loop() {
  distance = measureDistance();
  if (distance > safeDistance) forward();
  else { stopRobot(); delay(500); backward(); delay(300); turnRight(); delay(700); }
}
