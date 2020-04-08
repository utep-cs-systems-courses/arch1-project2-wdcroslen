#include <msp430.h>
#include "statemachines.h"
#include "led.h"
#include "switches.h"
#include "soundStates.h"

void advanceSounds(){
  // st = get_elem(sans);
  buzzer_set_period(st);
  state++;
}
void newTune(){
 buzzer_set_period(tet);
 state++;
}
