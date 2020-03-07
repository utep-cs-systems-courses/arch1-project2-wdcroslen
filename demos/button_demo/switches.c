#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "statemachines.h"
int nums[] = {1174,1174,2349,1760,1720,1600,1400,1174,1397,1568};
char state, switch_state_down, switch_state_down2, switch_state_down3,switch_state_down4, switch_state_changed; /* effectively boolean */
static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}
void switch_init()/* setup switch */
{
 // P1REN |= SWITCHES;		/* enables resistors for switches */
  // P1IE = SWITCHES;		/* enable interrupts from switches */
  // P1OUT |= SWITCHES;		/* pull-ups for switches */
  // P1DIR &= ~SWITCHES;		/* set switches' bits for input */
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE = SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  //Need same logic for P2
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  switch_state_down = (p2val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_down2 = (p2val & SW2) ? 0 : 1;
  switch_state_down3 = (p2val & SW3) ? 0 : 1;
  switch_state_down4 = (p2val & SW4) ? 0 : 1; 
  switch_state_changed = 1;
  if(state == 10){
  state = 0;
  }
  led_update();

  int notes[] = {293, 293, 587};
  if (switch_state_down){
    advanceSounds(state);
    // buzzer_set_period(400);
    // _enable_interrupts();
    // buzzer_set_period(587);
  }
  if (!switch_state_down){
    buzzer_set_period(0);
  }
  
  /* 0 when SW1 is up */
  // switch_state_down3 = (p1val & SW3) ? 0 : 1; /* 0 when SW1 is up */
  //advance state
}
