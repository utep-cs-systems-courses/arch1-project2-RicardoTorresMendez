#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"

char switch_state_1, switch_state_2, switch_state_3, switch_state_4, switch_state_changed; /* effectively boolean */

static char 
switch_update_interrupt_sense() {
  char p1val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p1val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p1val | ~SWITCHES);	/* if switch down, sense up */
  return p1val;
}

void 
switch_init(){  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void switch_interrupt_handler(){

  char p1val = switch_update_interrupt_sense();
  switch_state_1 = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  switch_state_2 = (p1val & SW2) ? 0 : 1; /* 0 when SW2 is up */
  switch_state_3 = (p1val & SW3) ? 0 : 1; /* 0 when SW3 is up */
  switch_state_4 = (p1val & SW4) ? 0 : 1; /* 0 when SW4 is up */
  switch_state_changed = 1;
  led_update();

  if( switch_state_1 == 1 ){ buzzer_set_period( 1000 ); }
  else if( switch_state_2 == 1 ){ buzzer_set_period( 500 ); }
  else if( switch_state_3 == 1 ){ buzzer_set_period( 250 ); }
  else if( switch_state_4 == 1 ){ buzzer_set_period( 125 ); }
  else{ buzzer_set_period( 0 ); }
}
