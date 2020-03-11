#include <msp430.h>
#include "statemachines.h"
#include "led.h"
#include "switches.h"
#include "soundStates.h"

void advanceSounds(int st){
  buzzer_set_period(sans[st]);
  state++;
}
void newTune(int st){
 buzzer_set_period(tetris[st]);
 state++;
}
