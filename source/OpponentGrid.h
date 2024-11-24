/*
 * OpponentGrid.h
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map> // for std::map
#include <set>

//!  This class models the Player's Opponent Grid
/*!
  Recording your shots on the OpponentGrid by invoking method shotResult(const Shot& shot, Shot::Impact impact)
*/
class OpponentGrid
{
private:

	//!  number of rows of your OpponentGrid
	int rows;

	//!  number of columns of your OpponentGrid
	int columns;

	//! A vector of sunken Ships
	std::vector<Ship> sunkenShips;

	//! A data member that records the shots and their associated GridPosition
	std::map<GridPosition, Shot::Impact> shots;

public:

	//! Deafult Constructor. A 10x10 grid will be created
	OpponentGrid();

	//! Constructor created from individually specified number of rows and number of column arguments
	OpponentGrid(int rows, int columns);

	//! A method to access the number of rows
	/*!
	 \return the number of rows
	 \sa getColumns() */
	int getRows() const;

	//! A method to access the number of columns
	/*!
	 \return the number of columns
	 \sa getColumns() */
	int getColumns() const;

	//! A method to access the vector of sunken Ship objects
	/*!
	 \return std::vector<Ship> of sunken Ship objects */
	const std::vector<Ship> getSunkenShips() const;

	//! A method to to include the information about the opponent's ships into our model.
	/*!
	 The method adds the shot and its result to the data member this->shots and updates the list of sunken ships */
	void shotResult(const Shot& shot, Shot::Impact impact);

	//! A method to access the map of GridPosition and its associated Shot result (hit, miss, or sunken)
	/*!
	 This method is used for printing on console using ConsoleView class */
	const std::map<GridPosition, Shot::Impact>& getShotAt() const;

	//! A method to check if this direction can be flipped to be Shot::Impact::SUNKEN
	/*!
	This method is similar to a method in Reversi Game that check if a move of a player can flip the whole line\n
	This method is invoked when method void shotResult(const Shot& shot, Shot::Impact impact) received a Shot that is
	associated with Shot::Impact::SUNKEN
	\return true or false
	\sa sunkShipInThisDirection*/
	bool canSunkShipInThisDirection (
			char row_plus_delta,
			int column_plus_delta,
			int delta_row,
			int delta_column);

	//! A method to flip GridPosition that has Shot::Impact::HIT to be Shot::Impact::SUNKEN
	/*!
	 This method is similar to a method in Reversi Game that flip in the direction after determining that
	 this direction can be flipped.\n
	 This method is invoked when method canSunkShipInThisDirection returns true.
	 \return the last GridPosition to be changed to Shot::Impact::SUNKEN, so that later on we can use it as sunken Ship's Bow or Stern
	 \sa sunkShipInThisDirection*/
	GridPosition sunkShipInThisDirection(
			char row_plus_delta,
			int column_plus_delta,
			int delta_row,
			int delta_column);

	//! A Destructor
	virtual ~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
