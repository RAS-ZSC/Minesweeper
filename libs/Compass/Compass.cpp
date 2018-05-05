#include <Compass.h>

Compass::Compass(): Adafruit_HMC5883_Unified(12345) {
  
}

void Compass::begin() {
  if (!Adafruit_HMC5883_Unified::begin()) { // to make sure that the connection is right 
    Serial.println("Ooops, no HMC5883 detected ... Check your wiring!");
    while (1);
  }
}

float *Compass::getField() {
  static float ret[3];
  sensors_event_t event;
  getEvent(&event);

  ret[0] = event.magnetic.x;
  ret[1] = event.magnetic.y;
  ret[2] = event.magnetic.z;
  return ret;
}

float Compass::getDegree() {
  sensors_event_t event;
  getEvent(&event);

  float heading  = atan2(event.magnetic.x, event.magnetic.z);

  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (4.0 + (29.0 / 60.0)) / (180 / M_PI);
  heading += declinationAngle;

  if (heading < 0)
    heading += 2 * PI;
  else if (heading > 2 * PI)
    heading -= 2 * PI;

  headingDegrees = heading * 180 / M_PI;
  degree = preHeading + headingDegrees;

  if (degree < 0)
    degree += 2 * 180;
  else if (degree > 2 * 180)
    degree -= 2 * 180;

  return degree;
}

void Compass::init() {
  getDegree();
  preHeading = -headingDegrees;
}
