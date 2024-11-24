/*
 * OwnGrid.h
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_

#include "Ship.h"
#include "Shot.h"
#include <vector>
#include <map> // for map
#include <set> // for set


//!  This class models the Player's Own Grid
/*!
  In the initial phase of the game, a player arranges the ships on his own grid by calling placeShip(const Ship& ship)
*/
class OwnGrid
{
private:

	//!  number of rows of your OwnGrid
	int rows;

	//!  number of columns of your OwnGrid
	int columns;

	//! A vector of Ship Object that OwnGrid has
	std::vector<Ship> ships;

	//! A std::map that stores the pairs "length"/"number of ships" from rules of German BattleShip Wikipedia
	std::map<int, int> availableShips;

	//! A std::set that stores GridPosition that a Shot hits Ship of OwnGrid
	/*!
	I should have implemented the std::map<GridPosition, Shot::Impact>. But I dont have much time left to do this.
	*/
	std::set<GridPosition> shotAt;

	//! A std::set that stores GridPosition that a Shot misses Ship of OwnGrid
	/*!
	 I should have implemented the std::map<GridPosition, Shot::Impact>. But I dont have much time left to do this.
	 */
	std::set<GridPosition> missShotAt;

	//! largest GridPosition of OwnGrid
	/*!
	 I was implementing lost of algorithm but I forgot why I created this data member. Because the deadline is close
	  and I don't want to risk so I keep this intead of deleting.\n */
	GridPosition largestPosition;

public:

	//! Deafult Constructor. A 10x10 grid will be created
	OwnGrid();

	//! Constructor created from individually specified number of rows and number of column arguments
	OwnGrid(int rows, int columns);

	//! A method to access the number of rows
	/*!
	 \return the number of rows
	 \sa getColumns() */
	int getRows() const;

	//! A method to access the number of columns
	/*!
	 \return the number of columns
	 \sa getRows() */
	int getColumns() const;

	//! A method to place Ship on the grid
	/*!
	 This method checks if a Ship follow the rules of German Battleship (https://de.wikipedia.org/wiki/Schiffe_versenken).
	 Return false if a condition is violated.
	 \return true or false */
	bool placeShip(const Ship& ship);

	//! A method to access the vector of Ship objects
	/*!
	 \return std::vector<Ship> of Ship objects */
	const std::vector<Ship> getShips() const;

	//! A method to access the vector of Ship objects
	/*!
	 If the shot doesn't hit a ship, the value Shot::Impact::NONE is returned. \n
	 If a ship is hit, Shot::Impact::HIT is returned. \n
	 If the hit is the final hit, i.e. the ship is sunk by the hit, Shot::Impact::SUNKEN is returned.\n
	 This method also adds the GridPosition associated with Shot::Impact either to data member this->shotAt
	 or to data member this->missShotAt.\n
	 In case of Shot::Impact::SUNKEN, the GridPosition associated with that will be added to this->shotAt
	 \return Shot::Impact::HIT, or Shot::Impact::SUNKEN, or Shot::Impact::NONE */
	Shot::Impact takeBlow(const Shot& shot);

	//! A method to access the std::set<GridPosition> of data member this->shotAt
	/*!
	 This method is used for printing on console using class ConsoleView.
	 \return std::set<GridPosition> that is associated with Shot::Impact::HIT or Shot::Impact::SUNKEN */
	const std::set<GridPosition> getShotAt() const;

	//! A method to access the std::set<GridPosition> of data member this->missShotAt
	/*!
	 This method is used for printing on console using class ConsoleView.
	 \return std::set<GridPosition> that is associated with Shot::Impact::NONE */
	const std::set<GridPosition> getMissShotAt() const;

	//! A method to access data member this->largestPosition.
	/*!
	\return the GridPosition of data member this->largestPosition */
	GridPosition getLargestPosition() const;

	//! A Destructor
	virtual ~OwnGrid();
};

#endif /* OWNGRID_H_ */
