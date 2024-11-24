/*
 * Board.h
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "OwnGrid.h"		/**< ... */
#include "OpponentGrid.h"	/**< ... */

//!  This class models the game (consisting two grids: the player's own grid and his/her opponent's grid) from one player's perspective.
/*!
  In order to be able to adapt to the different board sizes mentioned in Wikipedia,
  the number of rows and columns can be specified when creating the board.\n
  Apart from returning the specified dimensions, Board's only capabilities are to provide
  access to the grids using the getter-functions
*/
class Board
{
private:

	//! The number of rows of the game
	int rows;

	//! The number of columns of the game
	int columns;

	//! Composition relationship. Object Board has 1 OwnGrid Object.
	OwnGrid 		ownGrid;

	//! Composition relationship. Object Board has 1 OpponentGrid Object.
	OpponentGrid	opponentGrid;


public:

	//! Default Constructor. A game of 10x10 size will be created.
	Board();

	//! A Constructor taking 2 arguments (number of rows and number of columns) to create the Board Object
	Board(int rows, int columns);

	//! A Destructor
	virtual ~Board();

	//! A method to access the number of rows of the Board Object
	/*!
	 \return the number of rows of the Board Object
	 \sa getCols() */
	int getRows() const;

	//! A method to access the number of columns of the Board Object
	/*!
	 \return the number of columns of the Board Object
	 \sa getRows() */
	int getCols() const;

	//! A method to access the Own Grid Object
	/*!
	 \return the Own Grid Object
	 \sa getOpponentGrid() */
	OwnGrid& getOwnGrid();

	//! A method to access the Opponent Grid Object
	/*!
	 \return the Opponent Grid Object
	 \sa getOwnGrid() */
	OpponentGrid& getOpponentGrid();
};

#endif /* BOARD_H_ */
