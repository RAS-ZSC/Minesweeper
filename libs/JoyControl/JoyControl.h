#ifndef _JOYCONTROL_H
#define _JOYCONTROL_H

#include <Arduino.h>
#include <HBridge.h>

union data {
  byte bytes[2];
  short value;
};

class JoyControl {
private:
  int state = 0;
  int x = 0, y = 0;
  union data d1, d2;
  HBridge& hbridge;  /* Attached H-Bridge */

public:
  JoyControl(HBridge&);
  void handle(char);
};

#endif
