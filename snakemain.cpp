/*-------------------------------------------------------------------------
file name: snakemain.cpp
by: Jaysson Balbuena
organization: COP 2001, spring 2020
for: main application file for the snake game 
---------------------------------------------------------------------------*/

//Library

#include <time.h>		// for time function
#include <stdlib.h>		// srand, rad functions
#include <iostream>

#include "snake.h"

using namespace std;


//----------------------------------------
//Function prototypes
//----------------------------------------
void update(Snake& snake, Block& food);
void render(HDC hdc, Snake snake, Block food);
Block nextFood(Snake snake);


//start here
int main() {

	HDC console = initConsole(WIDTH, HEIGHT, SCALE);

	drawBorders(console, WIDTH, HEIGHT, SCALE, White);
	drawBorders(console, WIDTH, HEIGHT, SCALE, White);

	//initialize random numbers
	srand(time(NULL));

	Snake snake = Snake(START_POSITION_X, START_POSITION_Y);


	//current food location
	Block food = nextFood(snake);
	
	//main game loop
	do {
		//Process player input
		if (snake.getNextDirection() == None)
			snake.setDirection(getGameKeys());

		//Update game objects
		if (snake.getNextDirection() != Quit)
			update(snake, food);

		//Render - Draw the game 
		render(console, snake, food);

		//Pause for 1/5th of a second in milliseconds	
		Sleep(.05 * 1000); 

	} while (snake.getNextDirection() != Quit);

	drawBorders(console, WIDTH, HEIGHT, SCALE, White);

	return 0;
} //end main

/**********************************************************
Updates objects in the game
parameters:
	snake	- (out) snake structure
	food	- (out) food block
Returns:
	void
**********************************************************/
void update(Snake& snake, Block& food) {

	if (snake.getNextDirection() != None) {
		snake.turn();
	}

	//see if snake has started moving yet
	if (snake.isMoving()){

		snake.move();

		//see if snake ate food
		if (snake.getHead()->equals(food)){
			//grow snake
			snake.grow();

			food = nextFood(snake);
		}
		else {
			//see if snake has any collision
			snake.collision();
		}

	} //end isMoving

	return;
}

/**********************************************************
Draw the game board on the console 
Parameters:
	hdc		- handle to object to draw on 
	snake	- snake structure
	food	- current food block
returns:
	void
***********************************************************/
void render(HDC hdc, Snake snake, Block food){

	//draw food 
	draw(hdc, food.getColumn(), food.getRow(), SCALE, FOOD_COLOR);

	//Erase at previous position
	if (!snake.getPrevTail()->isEmpty())
	draw(hdc, snake.getPrevTail()->getColumn() , snake.getPrevTail()->getRow(), SCALE, BACKGROUND_COLOR);

	//draw head of snake at new location
	draw(hdc, snake.getHead()->getColumn(), snake.getHead()->getRow(), SCALE, SNAKE_COLOR);

	return;
}

/**********************************************************
Generenate location for new food 
Parameters:
	snake	- snake class object
returns:
	Block	- location of the next food item
***********************************************************/
Block nextFood(Snake snake) {
	Block food = Block();

	while (food.isEmpty()){
	
		food.setColumn(rand() % WIDTH); // random column 
		food.setRow(rand() % HEIGHT);// random row

		//check if snake occupies this location
		if (snake.intersects(food, true)){
			// set food to empty
			food = Block();
		}
	}
	return food;
}

