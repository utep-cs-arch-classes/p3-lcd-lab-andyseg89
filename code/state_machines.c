#include "state_machines.h"
#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"
#include "draw_ship.h"

unsigned int game = 1;
unsigned int animation = 0;

static int dance_counter = 0;
static int game_counter = 0;
static int enemy_counter = 0;

void run_game(void) {
  if (game) {
    ship();
  }
}




