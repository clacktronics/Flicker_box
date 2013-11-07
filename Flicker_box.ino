/*
***********************************
Bulb flicker program by Ben Barwise
***********************************
Version (alpha) 0.2  - 07/11/2013
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Status:
This code is currently untested until I try it out
on a working arduino. Variables are not set properly

About:
I wrote this program to learn about git (and github)
so I can develop my programming skills and develop
my understanding on how to release code, code versioning
and licencing.

This program is used to control an LED strip on and off 
in patterns that simulate the faliure of a flourecent lamp.
Similar code I created was used to make a lighbox flicker 
for a piece of work by Ryan Gander.

I reccomend using a MOSFET like IRF540 to drive the strip.

Typically the pattern seems to be a burst of flickers ended
by a held period before it fails.

There are variables that can be changed to simulate different 
feels.

such as 
* Try to start, breif on period then off and restart
* Constant fast random flickering
* on with Intermittent off flickers
* Long periods of off with occasional signs of life

********************************************************

*/
// Master fixed variables that make it easier to change parameters
const int max_flicker_time = 100;
const int min_flicker_time = 100;
const int max_flicker_length = 100;
const int min_flicker_length = 100;
const int off_variation_offset = 100;

// Variables used in the program
int flicker_length,hold_on,hold_off,flick_off,flick_on;


void setup() {
  pinMode(13,OUTPUT);
}

void loop() {
  
flicker_length = random(0,100); // min and max flicker loop length

hold_on = random(100,200);
hold_off = random(100,200);


// Startup flashes
for (int i; i < flicker_length; i++){
  digitalWrite(13,0);
  delay(flick_off);
  digitalWrite(13,1);
  delay(flick_on);
  flick_off = random(100,200);  //on and off varies during loop 
  flick_on = random(100,200);   // Unsure if this adds noticable time to the flicker on
}

delay(hold_on); // Loop ends with on so this delay then decides sucess hold
digitalWrite(13,0); // This is then the faliure
delay(hold_off); // how long to wait before next startup attempt

}
