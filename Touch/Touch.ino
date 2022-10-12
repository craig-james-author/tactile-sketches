#include <Arduino.h>
#include "Tactile.h"

Tactile *t;

void setup() {

  // Don't modify this setup() statement.
  t = Tactile::setup();

  // LOG LEVEL.
  // How much is printed on the Arduino Serial Monitor window?
  //   0: nothing
  //   1: normal info
  //   2: verbose (for code development and debugging

  t->setLogLevel(1);

  // TOUCH/RELEASE THRESHOLD.
  // For simple touch sensing, (95, 60) is a good choice. For
  // proximity-as-volume (see below), (10, 5) is a good starting place. The
  // first number (Touch) must always be higher than the second number
  // (Release).

  t->setTouchReleaseThresholds(95, 60);

  // FADE-IN/FADE-OUT.
  // By default a track starts playing at full volume, and stops
  // immediately when the sensor is released. If you specify a fade-in
  // and/or fade-out time, then the track's volume fades or out for the
  // specified length (in milliseconds, e.g.  1500 is 1.5 seconds).
  
  t->setFadeInTime(1000);
  t->setFadeOutTime(1000);

  // MULTI-TRACK MODE.
  // Setting this to "true" enables multiple simultaneous tracks.  The
  // default "false" means only one track plays at a time.

  t->setMultiTrackMode(true);

  // CONTINUE-TRACK MODE.
  // When a track is playing and the sensor is released, then touched
  // again, does the track resume where it left off ("true"), or start from
  // the beginning ("false")?

  t->setContinueTrackMode(true);

  // INACTIVITY TIMEOUT.
  // If you set continue-track mode (above) to "true", then the inactivity
  // timeout specifies an idle time; if that time passes with no activity
  // (no sensors touched), then all tracks are reset and will start playing
  // from the beginning the next time a sensor is touched. Time is in
  // seconds.

  t->setInactivityTimeout(60);

  // RANDOM-TRACK MODE.
  // Four directories (which must be named E1, E2, E3, and E4) can
  // contain two or more .WAV file, which are selected randomly
  // when the corresponding sensor is touched.
  
  t->setPlayRandomTrackMode(false);


  // TOUCH-TO-STOP MODE.
  // Normally the sensors operated as touch-play-release-stop. That is,
  // the track plays while the sensor is being touched. If you set
  // touch-to-stop mode to "true", then it will operate as touch-
  // start-touch-stop; that is, releases are ignored, and the track
  // plays until the sensor is touched again.
  
  t->setTouchToStop(false);


  // PROXIMITY-AS-VOLUME MODE.
  // When set to "true", the proximity of the user's hand to the sensor
  // is used to set the volume; the closer the user's hand, the louder
  // the volume. When set to "false", touch mode is enabled, and the
  // volume is fixed.
  //
  // NOTE: You should set the touch-release threshold (above) to fairly
  // low numbers for proximity-as-volume mode.
  //
  // NOTE: Fade-in and fade-out are ignored in proximity-as-volume mode.

  t->setProximityAsVolumeMode(false);

  // PROXIMITY MULTIPLIER.
  // The proximity-multiplier feature can be used to make the sensor
  // more or less sensitive. Each sensor (0 to 3) is specified separately.
  // A value greater than 1 increases sensitivity, and less than one
  // decreases it. For example 2.0 will double sensitivity; 0.5 will
  // cut sensitivity in half. NOTE: reducing sensitivity also reduces
  // the total volume you'll ever get, e.g. a multiplier of 0.5 means
  // you'll never get more than 50% volume.
  //
  // Note that the multiplier also affects touch mode and the
  // touch/release threshold.

  t->setProximityMultiplier(0, 1.0);     // 1.0 is no amplification, more increases sensitivity.
  t->setProximityMultiplier(1, 1.0);     // Sensors can be individually amplified or attenuated.
  t->setProximityMultiplier(2, 1.0);
  t->setProximityMultiplier(3, 1.0);

  
  // AVERAGING (SMOOTHING) STRENGTH.
  // You probably don't need to modify this. This is the number of sensor
  // readings that are averaged together to get the sensor's value. Higher
  // numbers mean more smoothing, but also mean a slower response
  // time. Lower numbers mean less smoothing (noiser signal) and faster
  // response. Only change this if you have a noisy situation, usually
  // indicated if your audio tracks "stutter" (start and stop rapidly).
  
  t->setAveragingStrength(200);

}

// Don't modify this loop() function.
void loop() {
  t->loop();
}
    
