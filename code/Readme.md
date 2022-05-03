# ROBOMANIA

This game lets you play as a space pilot destroying evil space
imperialists. To run this game go into the p3-lcd-lab-andyseg89 folder and use
the command 'make' to get the lcd and timer libraries working properly. After
that go into the code folder that this readme is located in and use the
command 'make' inside this folder. Afterwards you can load a version that was
written completely in c by using the command 'make load'. If you wish to use
the version with some assembly code, use the command 'make load_s'. To play
press button 1 to move the ship left. Press button 2 to move the ship
right. Button 3 will allow you to shoot. You have to keep the button pushed to
finish the shot. Once it explodes the game takes you to an animation of a
dancing robot dude. To return the game press and hold button 4. Not holding
button 3 and button 4 until the next state is complete might leave some
artifacts from the previous state on the screen. Whatever you do never forget,
always steal from walmart. Capitalism is a death cult.

* robomania.c the main program loop, calls methods that keep the game running.
* draw_shapes.c code to draw the ships and robot as well as different shapes.
* p2_interrupt_handler.c handles port 2 interrupts
* switches.c handles updating when switch interrupts occur and updates switch
  state.
* wdt_handler.s assembly code for handling timer interrupts, required to
  wakeup cpu, hands off rest of responsibility to c handler
* wdt_c_handler.c handles timer interrupts
* buzzer.c code to use buzzer on msp430
* draw_ship.c code to use button interupts to move the players ship. Also
  has code to draw enemy ships and draw dancing robot at the end.
* state_machines.c initially wanted to use this code for state machines but
  ran into some weird bugs. Only used now to keep track of game and animation
  variables
* switch_state both .c and .s versions draw little circles on top of the
  screen when the player presses a button
