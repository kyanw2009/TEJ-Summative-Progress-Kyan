const int buttonPin = 2;

const int trigPin = 3;
const int echoPin = 4;

const int soundPin = A0;

const int redPin   = 9;
const int greenPin = 10;
const int bluePin  = 11;

const int buzzerPin = 12;

bool systemOn = false;
void setup() {
  Serial.begin(9600);

  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  setColor(0, 0, 255);

}

void loop() {
  // put your main code here, to run repeatedly:

}
