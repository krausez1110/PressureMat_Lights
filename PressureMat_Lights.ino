/* FSR testing sketch. 
 
Connect one end of FSR to 5V, the other end to Analog 0.
Then connect one end of a 10K resistor from Analog 0 to ground
Connect LED from pin 11 through a resistor to ground 
 
For more information see www.ladyada.net/learn/sensors/fsr.html */
 
int fsrAnalogPin = 0; // FSR is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int fsrReading;       // the analog reading from the FSR resistor divider
long times;           //  set for the current time that the project is running
                      //  used for the millis delay
                      

 //Inital setup of the board 
void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);  //seting the LEDpin to be an output port to be how bright we want to set it
}

void timer()
{
  
  times=millis();                           // sets the current time project has been running 
                                            // this is done in milliseconds
                                            
  while(millis() < times+60000)             // adds current time plus 1 min 
  {                                         // used when the auto shut off would trigger
    
  fsrReading = analogRead(fsrAnalogPin);    // still reading inputs from the sensor even while delayed
  
  Serial.print("Analog reading = ");        // These two lines allowed for checking to see if the
  Serial.println(fsrReading);               // sensor was reading right and printed to the Serial Monitor

                                            // Adding a way to turn off the auto timer
  if(fsrReading>=300)                       // Check to see if some one stepped back on it 300 is just a
    {                                       // baseline number can be set higher or higher to ignore pets
      analogWrite(LEDpin, 0);               // Turns the led off
      delay(10000);                         // 10 sec grace period so lights won't flicker on and off
      break;                                // ends the loop if the auto shut off wasn't triggered
    }
  }
}
 
void loop(void) {
  
  fsrReading = analogRead(fsrAnalogPin);    // taking in the input from the sensor and setting to the varible
  Serial.print("Analog reading = ");        // These two lines allowed for checking to see if the
  Serial.println(fsrReading);               // sensor was reading right and printed to the Serial Monitor
 
  
  if(fsrReading>=300)                       // Check to see if some one stepped back on it 300 is just a
  {                                         // baseline number can be set higher or lower to ignore pets
  
  analogWrite(LEDpin, 255);                 // If reading is over the baseline turns LEDs on
  delay(10000);                             // 10 sec grace period so lights won't flicker on and off
  timer();                                  // calling the timer function
  }
  else                                      
  {
    analogWrite(LEDpin, 0);                 // Keeping LEDs off when not triggerend
  }
  
}
