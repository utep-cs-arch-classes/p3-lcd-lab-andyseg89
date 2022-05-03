#include "switches.h"
#include "draw_ship.h"

int switches = 0;
int switch_pressed =  0;
char switch_state = 0;

/* Updates when the interrupt fires and returns current state of switches */
static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init(void)		/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
}

void
switch_interrupt_handler(void)
{
  char p2val = switch_update_interrupt_sense();
  switches = ~p2val & SWITCHES;

  if (p2val & SW1) {
    move_left = 0;
  }
  else {
    move_left = 1;
    switch_state = 1;
  }
  if (p2val & SW2) {
    move_right = 0;
  }
  else {
    move_right = 1;
    switch_state = 2;
  }
  if (p2val & SW3) {
    shoot = 0;
  }
  else {
    shoot = 1;
    switch_state = 3;
  }
  if (p2val & SW4) {
    honk = 0;
  }
  else {
    honk = 1;
    switch_state = 4;
  }
  state();
  // move_left = (p2val & SW1) ? 0 : 1;
  //move_right = (p2val & SW2) ? 0 : 1;
  //shoot = (p2val & SW3) ? 0 : 1;
  //honk = (p2val & SW4) ? 0 : 1;
}

