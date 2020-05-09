#include <msp430.h>
#include "switches.h"
#include "led.h"

void __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static char blink_count = 0;

  switch( current_state ){
      case 0:
        if (++blink_count >= 50) {
        	turn_off();
  		}
  		if(++blink_count >= 100){
  			led_update();
  			blink_count = 0;
  		}
  		break;
      case 1:
        if (++blink_count >= 30) {
        	turn_off();
  		}
  		if(++blink_count >= 60){
  			led_update();
  			blink_count = 0;
  		}
  		break;
      case 2:
        if (++blink_count >= 10) {
        	turn_off();
  		}
  		if(++blink_count >= 20){
  			led_update();
  			blink_count = 0;
  		}
  		break;
      default:
        if (++blink_count >= 50) {
        	turn_off();
  		}
  		if(++blink_count >= 100){
  			led_update();
  			blink_count = 0;
  		}
  		break;
    }

}
