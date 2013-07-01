/***********************************************************
 * My First Sound v2
 * (Now delay is in microseconds)
 * 
 * M. Musick - 2013 for NYU SIMT 
 *
 * This example plays a single tone from the piezo element
 *
 * the delay time will determine the frequency of this tone
 *
 * For a Fritzing schematic look at piezoTone.fzz
 *  (This sketch does not use the LED portion of the circuit)
 *  Alternatively your headphones can be used
 *  Add a resistor (220 or 330) between the ground connection
 *  Simply touch the connection wires that would go to the piezo
 *  To the tip and sleeve of your headphone plug
 *
 **********************************************************/
 
// The piezo speaker pin
int speakerPin = 10;

 
// delay length is in microSeconds 
int delayLength = 500;
/* 
   (delayLength = frequency in Hz)
   (2000 = 250Hz) 
   (1000 = 500Hz)
   (500  = 1000Hz)
   (250  = 2000Hz)
   
   --to determine Hz
      (1 / ((delayLength*2) * 0.000001))
      we are determining how many cycles occur in a second
        so we divide 1 second by the length of each loop
        This tells us how many cycles occured in a second
        Which is the frequency
      because we call our delay twice each loop
        we must account for that full delay length (delayLength*2)
      also these are in microsecond so we multiply by 0.000001
        to convert to seconds
*/

 
//setup function
void setup() {
  pinMode(speakerPin, OUTPUT);
}
 
//loop function
void loop() {
  digitalWrite(speakerPin, HIGH);
  delayMicroseconds(delayLength);
  digitalWrite(speakerPin, LOW);
  delayMicroseconds(delayLength);
}
