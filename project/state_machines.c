#include "state_machines.h"
#include "switches.h"
#include "draw_shapes.h"

unsigned int buzzer_counter;
unsigned int buzzer_limit;
unsigned int draw_counter;
unsigned int draw_limit;

static int screen_counter = 0;
static int screen_limit = 1200;

void
check_switches(void) {
  screen_counter ++;
  if (screen_counter > screen_limit) {
    screen_counter = 0;
    clearScreen(COLOR_BLUE);
  }
  if (switch_pressed) {
    // clearScreen(COLOR_BLUE);
    switch_pressed = 0;
  }
  if (switch1_down) {
    draw_pos1(30);
  }
  else if (switch2_down) {
    draw_pos2(30);
  }
  else if (switch3_down) {
    draw_pos3(30);
  }
}
