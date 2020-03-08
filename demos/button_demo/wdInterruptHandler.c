#include <msp430.h>
#include "statemachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){ /* 250 interrupts/sec */
  static char blink_count = 0;
  //advance sounds
  if (cont && ++blink_count == 33) {
    advanceSounds(state);
    blink_count = 0;
  }
  //advance the lights at different speeds
  if(switch_state_down4) {
    if(secondSpeed==1){
      if(++blink_count == 20){
         state_advance();
	 blink_count = 0;
      }
    }
    else{
      if(++blink_count == 100){
	state_advance();
        blink_count = 0;
      }
    }
  }
}
