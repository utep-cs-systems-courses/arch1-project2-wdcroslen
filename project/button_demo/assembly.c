/*#include <msp430.h>
#include "statemachines.h"
#include "led.h"
#include "switches.h"

void assembly(){
  char changed = 0;  
  static enum {R=0, G=1} color = G;
  switch (color) {
  case R: changed = toggle_red(); color = G; break;
  case G: changed = toggle_green(); color = R; break;
  }
  led_changed = changed;
  led_update();
}
*/
