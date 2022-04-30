#include "draw_shapes.h"
#include "state_machines.h"
#include "draw_ship.h"

/* the interupt handler for the watchdog timer */
void wdt_c_handler(void)
{
  static int secCount = 0;

  secCount ++;
  if (secCount >= 10) {		/* 10/sec */
    secCount = 0;
    game = 1;
  }
}
  
