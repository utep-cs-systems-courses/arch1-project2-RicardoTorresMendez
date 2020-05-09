#include <msp430.h>
#include "led.h"
#include "switches.h"

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
  led_update();
}

void turn_off(){
  char ledFlags = 0; /* by default, no LEDs on */

  P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
  P1OUT |= ledFlags;         // set bits for on leds
  switch_state_changed = 0;
}

void led_update(){
  char ledFlags = 0; /* by default, no LEDs on */

  ledFlags |= switch_state_changed ? LED_GREEN : 0;
  ledFlags |= switch_state_changed ? 0 : LED_RED;

  P1OUT &= (0xff - LEDS) | ledFlags; // clear bits for off leds
  P1OUT |= ledFlags;         // set bits for on leds
  switch_state_changed = 0;
}
