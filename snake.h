/*-------------------------------------------------------------------------
file name: snake.h
by: Jaysson Balbuena
organization: COP 2001, spring 2020
for: Header file for a snake class object 
---------------------------------------------------------------------------*/
#pragma once

#include "snakedefs.h"
#include "block.h"

class Snake {
private:

	Block head;			//root of the snake body

	Block* tail;		//pointer to last block in body

	Block prevTail;		//for erasing and appending 

	Block speed;		//traveling velocity in the x/y-coordinates

	int size;			//number of body blocks in snake

	Direction current;	//current direction snake is traveling
	Direction next;		//direction player has input 

public: 

	//-------------------------------------------
	//Constructors 
	//-------------------------------------------
	
	Snake();
	Snake(int startColumn, int startRow);

	//-------------------------------------------
	//Accessors
	//-------------------------------------------
	Block* getHead();
	Block* getTail();
	Block* getPrevTail();
	int getSize();
	Direction getCurrentDirection();
	Direction getNextDirection();

	//-------------------------------------------
	//Methods
	//-------------------------------------------
	void setDirection(int input);
	void turn();
	void move();
	bool isMoving();
	void grow();
	void collision();
	bool intersects(Block other, bool withHead);

	
};	//end class Snake 