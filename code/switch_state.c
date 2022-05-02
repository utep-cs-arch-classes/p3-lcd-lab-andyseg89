#include "draw_shapes.h"
#include "switches.h"

void state(void) {
  switch(switch_state) {
     case 0:
       break;
     case 1:
       draw_circle(80, 15, 2, COLOR_RED);
       break;
     case 2:
       draw_circle(20, 20, 20, COLOR_GREEN);
       break;
     case 3:
       draw_circle(80, 15, 2, COLOR_YELLOW);
       break;
     case 4:
       draw_circle(20, 20, 1, COLOR_ORANGE);
       break;
  }
  return;
}
