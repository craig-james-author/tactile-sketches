/*----------------------------------------------------------------------
 * Tests the TactileAudio module's multi-track feature. Plays every
 * combination of four tracks using start/stop, then repeats using
 * pause/resume.
 ----------------------------------------------------------------------*/

#include <Arduino.h>
#include "TactileCPU.h"
#include "TactileAudio.h"

TactileCPU     *tc;
TactileAudio   *ta;

int n = 0;

bool play[4];
bool pause;

void setup() {
  tc = TactileCPU::setup();
  ta = TactileAudio::setup(tc);
  tc->setLogLevel(1);
  ta->setVolume(30);
}

void loop() {

  play[0] = (n & 0x01) != 0;
  play[1] = (n & 0x02) != 0;
  play[2] = (n & 0x04) != 0;
  play[3] = (n & 0x08) != 0;
  pause   = (n & 0x10) != 0;

  if (pause)
    Serial.print("Pause mode: ");
  else
    Serial.print("Stop mode:  ");

  for (int i = 0; i < 4; i++) {
    Serial.print(play[i]);
    Serial.print(" ");
    bool playing = ta->isPlaying(i);
    bool paused  = ta->isPaused(i);
    if (pause) {
      if (play[i] && !playing)
        ta->startTrack(i);
      else if (play[i] && paused)
        ta->resumeTrack(i);
      else if (!play[i] && !paused)
        ta->pauseTrack(i);
    }
    else {
      if (play[i] && !playing)
        ta->startTrack(i);
      else if (!play[i] && playing)
        ta->stopTrack(i);
    }
  }
  Serial.println(n);
  n++;
  delay(2000);
}
    
