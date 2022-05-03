#include "draw_shapes.h"
#include "switches.h"

void state(void) {
  switch(switch_state) {
     case 0:
       break;
     case 1:
       draw_circle(30, 10, 2, COLOR_RED);
       break;
     case 2:
       draw_circle(50, 10, 2, COLOR_GREEN);
       break;
     case 3:
       draw_circle(70, 10, 2, COLOR_YELLOW);
       break;
     case 4:
       draw_circle(90, 10, 2, COLOR_ORANGE);
       break;
  }
  return;
}
