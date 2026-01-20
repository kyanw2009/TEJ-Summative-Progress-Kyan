// Define Pins
const int buttonPin = 2;

const int trigPin = 3;
const int echoPin = 4;

const int soundPin = A0;

const int redPin   = 9;
const int greenPin = 10;
const int bluePin  = 11;

const int buzzerPin = 12;

// Variables
bool systemOn = false;

long duration;
int distance;
int soundValue;

const int distanceThreshold = 10; //10 cm for alert
const int soundThreshold    = 100; //sound to trigger alert

void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setColor(0, 0, 255); //System color light set to blue to show its off

}

void loop() {

  //Button turns system on manually ensuring no false starts
  if (!systemOn) {
    if (digitalRead(buttonPin) == LOW) {
      systemOn = true;
      delay(500);
    }
    return; //do nothing until button is pressed
  }
  setColor(0, 255, 0); //System color light turns green meaning system is active

  // Reading ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  //Read sound sensor
  soundValue = analogRead(soundPin);

  //Serial print
  Serial.print("Distance (cm): ");
  Serial.print(distance);
  Serial.print(" | Sound Level: ");
  Serial.println(soundValue);

  //Alert Conditions
  //OR Condition
  if (distance <= distanceThreshold || soundValue >= soundThreshold) { 
    setColor(255, 0, 0);   //Red
    digitalWrite(buzzerPin, HIGH);
  }
  else {
    digitalWrite(buzzerPin, LOW);
  }

  delay(200);
}

//RGB LED function
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
