/***********************************************************
 * Button Plus Speaker 
 * (Turn the sound on and off)
 *
 * Button code adapted from http://arduino.cc/en/Tutorial/Button
 * 
 * M. Musick - 2013 for NYU SIMT 
 *
 * For a Fritzing schematic look at ButtonPlusSpeaker.fzz
 *
 **********************************************************/
 
// Declare PIN vars
const int speakerPin = 10;
const int button = 2;
// var to track button state
int buttonState = 0;

// delay length is in microSeconds (This sets frequency)
int delayLength = 500;


 
//setup function
void setup() {
  pinMode(button, INPUT);      // Make this an input pin
  pinMode(speakerPin, OUTPUT);
}
 
//loop function
void loop() {
  
  // check the state of the button at the start of each cycle
  buttonState = digitalRead(button);
  
  // if the button is pressed then play the cycle
  if(buttonState == LOW) {   
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(delayLength);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(delayLength);
  }
  // else keep checking
}
