#include <msp430.h>
#include "statemachines.h"
#include "switches.h"

void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;
  if (++blink_count ==100) {
    state_advance();
    blink_count = 0;
  }
  if (++blink_count == 125 && state == 0) {
    state_advance();
    blink_count = 125;
  }

  // if for states
  //if for brightness
}
