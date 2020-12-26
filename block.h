/*-------------------------------------------------------------------------
file name: block.h
by: Jaysson Balbuena
organization: COP 2001, spring 2020
for: Header file for a point class object by column and row
---------------------------------------------------------------------------*/
#pragma once		// Only include this header file in the
					// preparser output file once

class Block {
private:
	int column;  // x-coordinates
	int row;	 // y-coordinate

	Block* forward;		// Points at body block in from of this one or null
	Block* backward;	// Points at body block behind this one or null

public: 

	//-------------------------------------------
	//Constructors 
	//-------------------------------------------
	Block();
	Block(int columnIn, int rowIn);
	Block(Block* other);

	//-------------------------------------------
	//Accessors
	//-------------------------------------------
	int getColumn();
	void setColumn(int columnIn);

	int getRow();
	void setRow(int rowIn);

	Block* getForward();
	Block* getBackward();

	//-------------------------------------------
	//Methods
	//-------------------------------------------
	bool equals(Block other);
	bool isEmpty();
	void copy(Block* other);
	void append(Block* other);


}; // end class block