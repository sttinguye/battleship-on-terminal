/*
 * ConsoleView.h
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

//!  This class prints the board on the console.
/*!
  This class has an Association relationship with the class Board.\n
  This class receives a pointer to an instance of Board as parameter of its constructor.
*/
#include "Board.h"

class ConsoleView
{
private:
	//!  Association relationship with the Board class. pointer board points to an instance of Board.
	Board* board;

	//! number of rows of the Player's Own Grid
	/*!
	This data member's value is obtained through this->board->getOwnGrid().getRows() */
	int ownGridRows;

	//! number of columns of the Player's Own Grid
	/*!
	This data member's value is obtained through board->getOwnGrid().getColumns() */
	int ownGridColumns;

	//! number of rows of the Player's Opponent Grid
	/*!
	 This data member's value is obtained through board->getOpponentGrid().getRows() */
	int opponentGridRows;

	//! number of columns of the Player's Opponent Grid
	/*!
	 This data member's value is obtained through  board->getOpponentGrid().getColumns() */
	int opponentGridColumns;

	//! A pointer to point to the dynamically allocated char array for Player's Own Grid.
	/*!
	This array is used to print on console. */
	char* ownGrid;

	//! A pointer to point to the dynamically allocated char array for Player's Opponent Grid.
	/*!
	 This array is used to print on console. */
	char* opponentGrid;

	//! A method that converts a 2D index to a 1D index to use on 1D array
	int convert2Dto1D(int rowIndex, int columnIndex, int columns) const;

	//! Update method. This method gets information from class Board and update the 2 char arrays before printing on console
	void update();

public:
	//!  Constructor.
	/*!
	 This constrcutor receives a pointer to an instance of Board as its parameter. */
	ConsoleView(Board* board);

	//! A Destructor
	virtual ~ConsoleView();

	//! Print method
	/*!
	This method prints Player's Own Grid and his/her Opponent Grid. Method update() is invoked inside this method. */
	void print();

	//! Print Sunken Ships method
	/*!
	This method prints his/her Opponent's sunken Ships. */
	void printSunkenShips ();

};

#endif /* CONSOLEVIEW_H_ */
