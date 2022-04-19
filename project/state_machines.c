#include "state_machines.h"
#include "switches.h"
#include "draw_shapes.h"
#include "buzzer.h"

unsigned int buzzer_counter;
unsigned int buzzer_limit;
unsigned int draw_counter;
unsigned int draw_limit;

static int screen_counter = 0;
static int screen_limit = 1200;
static int center_counter = 0;
static int sw1_counter = 0;
static int sw2_counter = 0;
static int sw3_counter = 0;
static int sw4_counter = 0;

void
check_switches(void) {
  screen_counter ++;
  if (screen_counter > screen_limit) {
    screen_counter = 0;
    // clearScreen(COLOR_BLUE);
  }
  if (switch_pressed == 1) {
    // clearScreen(COLOR_RED);
    switch_pressed = 0;
  }
  if (switch1_down) {
    sw1_sequence();
  }
  else if (switch2_down) {
    sw2_sequence();
  }

}

void sw1_sequence(void){
    sw1_counter++;
    if (sw1_counter == 1) {
      clearScreen(COLOR_BLUE);
      draw_pos1(30);
      buzzer_set_period(1000);
      char message[] = "look at him go!";
      drawString5x7(25, 100, message, COLOR_RED, COLOR_BLUE); 
    }
    else if (sw1_counter > 15 && sw1_counter < 17) {
      clearScreen(COLOR_BLUE);
      buzzer_set_period(0);
    }
    else if (sw1_counter > 17 && sw1_counter < 32) {
      draw_pos3(30);
      buzzer_set_period(2000);
      char message[] = "he's on a mission";
      drawString5x7(25, 100, message, COLOR_RED, COLOR_BLUE);
    }
    else if (sw1_counter > 32 && sw1_counter < 34) {
      clearScreen(COLOR_BLUE);
      buzzer_set_period(0);
    }
    else if (sw1_counter > 34 && sw1_counter < 50) {
      draw_pos4(30);
      buzzer_set_period(3000);
      char message[] = "to destroy capitalism";
      drawString5x7(5, 100, message, COLOR_RED, COLOR_BLUE); 
    }
    else if (sw1_counter > 50) {
      clearScreen(COLOR_BLUE);
      sw1_counter = 0;
      switch1_down = 0;
      buzzer_set_period(0);
    }
 
}

void sw2_sequence() {
  sw2_counter++;
  if (sw2_counter == 1) {
    clearScreen(COLOR_RED);
  }
  else if (sw2_counter == 2) {
    draw_ship(30, 20, COLOR_GREEN);
    draw_ship2(60, 120, COLOR_GREEN);
  }
  else if (sw2_counter > 60 && sw2_counter < 62) {
    draw_ship(50, 20, COLOR_GREEN); 
  }
  else if (sw2_counter > 150 && sw2_counter < 152) {
    draw_ship(70, 20, COLOR_GREEN);
  }
  else if (sw2_counter > 250 && sw2_counter < 252) {
    draw_ship(90, 20, COLOR_GREEN);
    draw_ship2(60, 120, COLOR_RED);
    draw_ship2(30, 120, COLOR_GREEN);
  }
  else if (sw2_counter > 275 && sw2_counter < 277) {
    draw_ship(30, 20, COLOR_RED);
    draw_ship(30, 40, COLOR_GREEN);
    buzzer_set_period(3000);
  }
  else if (sw2_counter > 310 && sw2_counter < 312) {
    draw_ship(50, 20, COLOR_RED);
    draw_ship(50, 40, COLOR_GREEN);
    buzzer_set_period(4000);
  }
  else if (sw2_counter > 340 && sw2_counter < 342) {
    draw_ship(70, 20, COLOR_RED);
    draw_ship(70, 40, COLOR_GREEN);
    buzzer_set_period(2000);
  }
  else if (sw2_counter > 365 && sw2_counter < 367) {
    draw_ship(90, 20, COLOR_RED);
    draw_ship(90, 40, COLOR_GREEN);
    draw_ship2(30, 120, COLOR_RED);
    draw_ship2(90, 120, COLOR_GREEN);
    buzzer_set_period(0);
  }
  else if (sw2_counter > 1500) {
    switch2_down = 0;
    clearScreen(COLOR_BLUE);
    sw2_counter = 0;
  }
}

void sw3_sequence() {
  sw3_counter++;
}

void sw4_sequence() {
  sw4_counter++;
}
void center_mover(void) {
  center_counter = 1;
}
