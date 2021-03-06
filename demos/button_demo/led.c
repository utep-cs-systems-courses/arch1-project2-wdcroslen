#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0, green_on = 0;
unsigned char led_changed = 0;
static char redVal[] = {0, LED_RED}, greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS; // bits attached to leds are output
  switch_state_changed = 1;
  led_changed=1;
  led_update();
}
void led_update(){
  if(switch_state_changed){
    //switches between red and green SW1
    if(switch_state_down){
       if(green_on && red_on){
	red_on = 0;
      }
       else if (red_on) {
	green_on = 1;
	red_on = 0;
      }
       else if (green_on){
	red_on = 1;
	green_on = 0;
      }
       else if (!green_on && !red_on){
	green_on =1;
      }
    }
    //switches between red and green SW2
    if(switch_state_down2){
        if(green_on && red_on){
	red_on = 0;
      }
       else if (red_on) {
	green_on = 1;
	red_on = 0;
      }
       else if (green_on){
	red_on = 1;
	green_on = 0;
      }
      else{
	red_on =1;
      }
    }
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
    P1OUT |= ledFlags;         // set bits for on leds
  }
  if(switch_state_down4){
    char ledFlags = redVal[red_on] | greenVal[green_on];
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}
