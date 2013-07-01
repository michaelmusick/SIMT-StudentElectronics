/***********************************************************
 * Button Plus Speaker and Pot
 * (Turn the sound on and off and control frequency)
 *
 * Button code adapted from http://arduino.cc/en/Tutorial/Button
 * 
 * M. Musick - 2013 for NYU SIMT 
 *
 * For a Fritzing schematic look at PotAndButton_PlusSpeaker.fzz
 *
 **********************************************************/
 
// Declare PIN vars
const int speakerPin = 10;
const int button = 2;
const int potPin = A0;

// declare a base frequency and number of octaves
const int baseFreq = 200;
const int numOfOct = 4;

// vars to track button state and potentiometer value
int buttonState = 0;
int potValue = 0;

// initial variables for related functions
int delayLength = 500;
double pitchMult;

 
//setup function
void setup() {
  pinMode(button, INPUT);      // Make this an input pin
  pinMode(speakerPin, OUTPUT);

}
 
//loop function
void loop() {
  
  // check the state of the button at the start of each cycle
  buttonState = digitalRead(button);
  // check the value of the potentiometer
  potValue = analogRead(potPin);
  
  // map the value
     // map pot value to a raw scale value
     pitchMult = pow( (((potValue)/1023.0) + 1), numOfOct );
     // get final freq from base freq and scale value
     delayLength = (((1000/(baseFreq * pitchMult))*1000)/2);
  
  
  // if the button is pressed then play the cycle
  if(buttonState == LOW) {   
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(delayLength);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(delayLength);
  } else {
    delayMicroseconds(delayLength);
  }

}

