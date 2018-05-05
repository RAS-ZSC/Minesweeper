#ifndef _ROTARY_ENCODER_H
#define _ROTARY_ENCODER_H

#define PIN_INT0  0
#define PIN_INT1  1
#define PIN_INT2  2
#define PIN_INT3  3
class RotaryEncoder {
public:
  int state = 3;
  float mps;

public:
  long pos = 0;
  bool dir = true;
  RotaryEncoder(int, float);
  float getDistance();
};

#endif
