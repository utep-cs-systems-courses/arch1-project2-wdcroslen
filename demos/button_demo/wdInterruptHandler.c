#include <msp430.h>
#include "statemachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  /* if (++blink_count ==100) {
   state_advance();
   blink_count = 0;
  }
  */
  if (++blink_count == 100 && cont) {
    advanceSounds(state);
    // state_advance();
    blink_count = 0;
  }
  //  else if(++blink_count == 100) {
  // advanceSounds(state);
    //state_advance();  dim_()
  // blink_count = 0;
  // }
  

  // if for states
  //if for brightness
}
