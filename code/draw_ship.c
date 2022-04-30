#include "state_machines.h"
#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"

char move_left;
char move_right;
char shoot;
char honk;

static char x = 60;
static char y = 120;
static char old_x = 0;
static char velocity = 2;
static char redraw_screen = 0;

void ship(void){
  if (redraw_screen == 0) {
    break;
  }
  if (move_left) {
    if (x - velocity > 10) {
      old_x = x;
      x -= velocity;
      redraw_screen = 1;
    }
  }
  if (move_right) {
    if (x + velocity < 100) {
      old_x = x;
      x += velocity;
      redraw_screen = 1;
    }
  }
  if (redraw_screen) {
    draw_player(old_x, y, COLOR_RED);
    draw_player(x, y, COLOR_BLUE);
    redraw_screen = 0;
  }
}

void gun(void) {
  if (shoot){
    shoot = 0;
  }
}
