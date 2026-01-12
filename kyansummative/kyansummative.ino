const int buttonPin = 2;

const int trigPin = 3;
const int echoPin = 4;

const int soundPin = A0;

const int redPin   = 9;
const int greenPin = 10;
const int bluePin  = 11;

const int buzzerPin = 12;

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
  if (!systemon) {
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
  Serial.print(distance);
  Serial.print(soundValue);




}
