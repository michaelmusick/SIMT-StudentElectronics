/***********************************************************
 * My First Sound!!!
 * 
 * M. Musick - 2013 for NYU SIMT 
 *
 * This example plays a single tone from the piezo element
 *
 * the delay time will determine the frequency of this tone
 *
 * For a Fritzing schematic look at piezoTone.fzz
 *  Alternatively your headphones can be used
 *  Add a resistor (220 or 330) between the ground connection
 *  Simply touch the connection wires that would go to the piezo
 *  To the tip and sleeve of your headphone plug
 *
 **********************************************************/
 
// The piezo speaker pin
int speakerPin = 10;
// The LED PIN
int led = 9;
// the pot
int pot = A0;
 
// delay length is 1 second
int delayLength = 5;
 
 
//setup function
void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(led, OUTPUT);  
}
 
//loop function
void loop() {
  delayLength = map(analogRead(pot), 0, 1023, 1, 1000);
  digitalWrite(speakerPin, HIGH);
  digitalWrite(led, HIGH);
  delay(delayLength);
  digitalWrite(speakerPin, LOW);
  digitalWrite(led, LOW);  
  delay(delayLength);
}
