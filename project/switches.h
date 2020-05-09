#ifndef switches_included
#define switches_included

#define SW1 BIT0		// p 2.0
#define SWITCHES SW1		/* only 1 switch on this board */

void switch_init();
void switch_interrupt_handler();

extern char switch_state_down, switch_state_changed; /* effectively boolean */

#endif // included