/*-------------------------------------------------------------------------
file name: block.cpp
by: Jaysson Balbuena
organization: COP 2001, spring 2020
for: Implementation file for a point class object by column and row
---------------------------------------------------------------------------*/
#include "block.h"

//-------------------------------------------
//Constructors 
//-------------------------------------------

/**********************************************************
Default constructor of a point block class object, will 
instantiate an empty block
parameters:
Returns:
	Block(-1,-1)
**********************************************************/
Block::Block() {
	column = -1;
	row = -1;

	forward = nullptr;
	backward = nullptr;

}

/**********************************************************
Instantiate a point block class object at column and row
parameters:
columnIn	- x coordinate
rowIn		- y coordinate
Returns:
	Block(columnIn, rowIn)
**********************************************************/
Block::Block(int columnIn, int rowIn) {
	column = columnIn;
	row = rowIn;

	forward = nullptr;
	backward = nullptr;
}

/**********************************************************
Copy constructor sets block column and row from another
block
parameters:
	other		- pointer to block to copy		
Returns:
**********************************************************/
Block::Block(Block* other) {
	copy(other);	//Copy the column and row values

	forward = nullptr;
	backward = nullptr;
}

//-------------------------------------------
//Accessors
//-------------------------------------------

/**********************************************************
Return the current column property value 
parameters:
Returns:
	int - column value or -1 if empty
**********************************************************/
int Block::getColumn() {
	return column;
}

/**********************************************************
Modify the current column property value
parameters:
  columnIn - column value to set
Returns:
	void
**********************************************************/
void Block::setColumn(int columnIn) {
	column = columnIn;
}

/**********************************************************
Return the current row property value
parameters:
Returns:
	int - row value or -1 if empty
**********************************************************/
int Block::getRow() {
	return row;

}

/**********************************************************
Modify the current row property value
parameters:
	rowIn	- row value to set
Returns:
	void
**********************************************************/
void Block::setRow(int rowIn) {
	row = rowIn; 

}

/**********************************************************
Return a pointer to the block in front of this one 
parameters:
Returns:
	Block - pointer to block or null
**********************************************************/
Block* Block::getForward() {
	return forward;
}

/**********************************************************
Return a pointer to the block in back of this one
parameters:
Returns:
	Block - pointer to block or null
**********************************************************/
Block* Block::getBackward() {
	return backward; 
}
//-------------------------------------------
//Methods
//-------------------------------------------

/**********************************************************
Determine if another block is the same as this one by
column and row
parameters:
	other	- block to check for equality
Returns:
	bool	- true if same column and row
**********************************************************/
bool Block::equals(Block other) {
	return column == other.getColumn() && row == other.getRow();
}

/**********************************************************
Determine if this block is empty Block(-1,-1)
parameters:
	other	- block to copy
Returns:
	void
**********************************************************/
bool Block::isEmpty() {
	Block empty = Block();
	return equals(empty);         
}


/**********************************************************
Copy the values of another block to this one
parameters:
	other	- block to copy
Returns:
	void
**********************************************************/
void Block::copy(Block* other) {
	column = other->getColumn();
	row = other->getRow();
	return;
}

/**********************************************************
Link another block to the bakward pointer of this one
parameters:
	other	- block to line
Returns:
	void
**********************************************************/
void Block::append(Block* other) {
	backward = new Block(other->getColumn(), other->getRow());
	backward->forward = this;
	return;
}