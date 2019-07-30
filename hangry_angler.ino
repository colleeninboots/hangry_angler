const int INPUT_PIN = A0;
const int LURE_RED_PIN = 9;
const int LURE_GREEN_PIN = 10;
const int LURE_BLUE_PIN = 11;
const int EYE_RED_PIN = 3;
const int EYE_GREEN_PIN = 5;
const int EYE_BLUE_PIN = 6;

void setup() {
  pinMode(LURE_RED_PIN, OUTPUT);
  pinMode(LURE_GREEN_PIN, OUTPUT);
  pinMode(LURE_BLUE_PIN, OUTPUT);
  pinMode(EYE_RED_PIN, OUTPUT);
  pinMode(EYE_GREEN_PIN, OUTPUT);
  pinMode(EYE_BLUE_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int inputVal = analogRead(INPUT_PIN);
  Serial.print(inputVal);
  if (inputVal < 10) { // No voltage, no fish
    setLureColor(255, 255, 255); // White Color
    setEyeColor(0, 0, 0); // Eye is off
    Serial.println(" | NO FISH :(");
  }
  // Plug in your max and min values for the Blue Fish here
  else if (inputVal < 800 && inputVal > 500) { // 400 ohm, Blue fish. 
    setLureColor(0, 0, 255); // Blue Color
    setEyeColor(0, 0, 255); // Blue Color
    Serial.println(" | BLUE fish! nom.");
  }
  // Plug in your max and min values for the Purple Fish here
  else if (inputVal < 500 && inputVal > 300) { // 1.2k ohm, Purple fish
    setLureColor(170, 0, 255); // Purple Color
    setEyeColor(170, 0, 255); // Purple Color
    Serial.println(" | PURPLE fish! nom.");
  }
  // Plug in your max and min values for the Yellow Fish here
  else if (inputVal < 300 && inputVal > 100) { // 5k ohm, Yellow fish
    setLureColor(255, 255, 0); // Yellow Color
    setEyeColor(255, 255, 0); // Yellow Color
    Serial.println(" | YELLOW fish! nom.");
  }
  else { // This shouldn't happen
    setLureColor(255, 255, 255); // White Color
    setEyeColor(0, 0, 0); // Eye is off
    Serial.println(" | NO FISH :(");
  }

  delay(2); // A couple ms delay for analogRead stability
}

// Sets the RGB values of the lure's LED. 
void setLureColor(int redValue, int greenValue, int blueValue) {
  setColor(LURE_RED_PIN, LURE_GREEN_PIN, LURE_BLUE_PIN, 
            redValue, greenValue, blueValue); 
}

// Sets the RGB value of the eye's LED.
void setEyeColor(int redValue, int greenValue, int blueValue) {
  setColor(EYE_RED_PIN, EYE_GREEN_PIN, EYE_BLUE_PIN, 
             redValue, greenValue, blueValue);
}

// Sets the RGB value of the given RGB LED pins.
// Assumes common anode, so offsets the colors from 255.
void setColor(int redPin, int greenPin, int bluePin, int redValue, 
                int greenValue, int blueValue) {
  analogWrite(redPin, 255 - redValue);
  analogWrite(greenPin, 255 - greenValue);
  analogWrite(bluePin, 255 - blueValue);
}

// When a fish is sensed cycles through a range of similar 
// colors, rather than setting to one solid color
void colorCycle(int rMin, int rMax, int gMin, int gMax, 
                  int bMin, int bMax) {
  // TODO: cycle through the colors specified
}
