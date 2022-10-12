/*----------------------------------------------------------------------
 * This program is used after a fatal crash. On crash of the Teensy,
 * a small text file is saved, and is available on the next reboot.
 * this program finds it and prints it, then blinks the light.
 ----------------------------------------------------------------------*/


void setup() {
  Serial.begin(9600); // With TeensyDuino 1.54 Serial.begin() may return connected
  if ( Serial && CrashReport ) 
  { // Make sure Serial is alive and there is a CrashReport stored.
    Serial.print(CrashReport); // Once called any crash data is cleared
    // In this case USB Serial is used - but any Stream capable output will work : SD Card or other UART Serial
  }
  else 
  {
    // Following code will cause a Fault of the processor from writing to a NULL pointer
    // Don't run it again until the next restart showing normal after a fault
    uint32_t *y = 0;
    y[0] = 5; // Comment or remove this line to preevent causing a Crash
  }
  pinMode( LED_BUILTIN, OUTPUT );
}

elapsedMillis blinkTime;
void loop() {
  if ( blinkTime > 1000 ) {
    digitalToggle( LED_BUILTIN );
    blinkTime = 0;
  }
}
