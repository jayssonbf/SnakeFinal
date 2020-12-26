/*-------------------------------------------------------------------------
file name: snakedefs.h
by: Jaysson Balbuena
organization: COP 2001, spring 2020
for: Global 
---------------------------------------------------------------------------*/
#pragma once

#include "console.h"
/*---------------------------------------------------
Global constants and Data structures
--------------------------------------------------*/

//Global constant (Window configuration)
const int WIDTH = 50;
const int HEIGHT = 50;
const int SCALE = 10;

//Start position for head of snake
const int START_POSITION_X = 25;
const int START_POSITION_Y = 25;

const Color BACKGROUND_COLOR = Black;
const Color SNAKE_COLOR = White;
const Color FOOD_COLOR = Red;
/*----------------------------------------
Enumerations data types
----------------------------------------*/
enum Direction {
	None,
	Left,
	Right,
	Up,
	Down,
	Quit = -1
};