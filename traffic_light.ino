int Lane1[] = {13, 12, 11}; // red, yellow, green
int Lane2[] = {10, 9, 8};   // red, yellow, green
int Lane3[] = {7, 6, 5};    // red, yellow, green
int Lane4[] = {4, 3, 2};    // red, yellow, green
int ButtonPin1 = 1;          // Pin for the push button
int ButtonPin2 = 0;          // Pin for the second push button
int PotPin = A0;             // Pin for the potentiometer

int Gotime = 3000; // Default go time
int waitTime = 500; // Adjust the value according to your needs

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(Lane1[i], OUTPUT);
    pinMode(Lane2[i], OUTPUT);
    pinMode(Lane3[i], OUTPUT);
    pinMode(Lane4[i], OUTPUT);
  }

  pinMode(ButtonPin1, INPUT_PULLUP); // Internal pull-up resistor for the push button
  pinMode(ButtonPin2, INPUT_PULLUP); // Internal pull-up resistor for the second push button

  for (int i = 0; i < 3; i++) {
    digitalWrite(Lane1[i], LOW);
    digitalWrite(Lane2[i], LOW);
    digitalWrite(Lane3[i], LOW);
    digitalWrite(Lane4[i], LOW);
  }
}

void blinkAllYellowLights() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(Lane1[1], HIGH);
    digitalWrite(Lane2[1], HIGH);
    digitalWrite(Lane3[1], HIGH);
    digitalWrite(Lane4[1], HIGH);
    delay(250);
    digitalWrite(Lane1[1], LOW);
    digitalWrite(Lane2[1], LOW);
    digitalWrite(Lane3[1], LOW);
    digitalWrite(Lane4[1], LOW);
    delay(250);
  }
}

void turnOffAllLights() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(Lane1[i], LOW);
    digitalWrite(Lane2[i], LOW);
    digitalWrite(Lane3[i], LOW);
    digitalWrite(Lane4[i], LOW);
  }
}

void loop() {
  if (digitalRead(ButtonPin1) == LOW) {
    blinkAllYellowLights();
    delay(10); // Debounce
  } else if (digitalRead(ButtonPin2) == LOW) {
    turnOffAllLights();-
    delay(20); // Debounce
  } else {
    // Read potentiometer value and map it to the desired go time range
    Gotime = map(analogRead(PotPin), 0, 100, 200, 500);

    // Normal  traffic light sequence
    digitalWrite(Lane1[2], HIGH);
    digitalWrite(Lane3[0], HIGH);
    digitalWrite(Lane4[0], HIGH);
    digitalWrite(Lane2[0], HIGH);
    delay(Gotime);

    delay(waitTime);
    digitalWrite(Lane1[2], LOW);
    digitalWrite(Lane3[0], LOW);
    digitalWrite(Lane1[1], HIGH);
    digitalWrite(Lane3[1], HIGH);
    delay(waitTime);
    digitalWrite(Lane1[1], LOW);
    digitalWrite(Lane3[1], LOW);
    digitalWrite(Lane1[0], HIGH);
    digitalWrite(Lane3[2], HIGH);
    delay(Gotime);
    digitalWrite(Lane3[2], LOW);
    digitalWrite(Lane4[0], LOW);
    digitalWrite(Lane3[1], HIGH);
    digitalWrite(Lane4[1], HIGH);
    delay(waitTime);
    digitalWrite(Lane3[1], LOW);
    digitalWrite(Lane4[1], LOW);
    digitalWrite(Lane3[0], HIGH);
    digitalWrite(Lane4[2], HIGH);
    delay(Gotime);
    digitalWrite(Lane4[2], LOW);
    digitalWrite(Lane2[0], LOW);
    digitalWrite(Lane4[1], HIGH);
    digitalWrite(Lane2[1], HIGH);
    delay(waitTime);
    digitalWrite(Lane4[1], LOW);
    digitalWrite(Lane2[1], LOW);
    digitalWrite(Lane4[0], HIGH);
    digitalWrite(Lane2[2], HIGH);
    delay(Gotime);
    digitalWrite(Lane1[0], LOW);
    digitalWrite(Lane2[2], LOW);
    digitalWrite(Lane1[1], HIGH);
    digitalWrite(Lane2[1], HIGH);
    delay(waitTime);
    digitalWrite(Lane2[1], LOW);
    digitalWrite(Lane1[1], LOW);
    digitalWrite(Lane3[1], LOW);
    digitalWrite(Lane4[1], LOW);
  }
}
