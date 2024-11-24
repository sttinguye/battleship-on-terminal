/*
 * Ship.h
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

//!  This class represents a ship
/*!
 A ship has as data members two grid fields, named bow and stern. Of course, the two are
 indistinguishable when looking at the ships' representation on the paper. But these names are
 better than "end1" and "end2" or something alike.\n
 Just like GridPosition, class Ship is immutable. The values for bow and stern are passed to the
 constructor as arguments.
*/
class Ship
{
private:

	//!  bow of a ship
	GridPosition bow;

	//!  stern of a ship
	GridPosition stern;

public:
	//!  A Constructor. The values for bow and stern are passed to the constructor as arguments.
	Ship(const GridPosition& bow, const GridPosition& stern);

	//! Method that checks the validity of a coordinate
	/*!
	 Method isValid() checks if the grid positions for bow and stern are valid, whether the ship is positioned
	 horizontally or vertically and whether the length is between 2 and 5.
	 \return true or false */
	bool isValid() const;

	//! A method to access the Bow of the Ship
	/*!
	 \return GridPosition of the Bow
	 \sa getStern() */
	GridPosition getBow() const;

	//! A method to access the Stern of the Ship
	/*!
	 \return GridPosition of the Stern
	 \sa getBow() */
	GridPosition getStern() const;

	//! Member function length returns the length of the ship, calculated from the distance between bow and stern.
	/*!
	 \return returns the length of the Ship */
	int length() const;

	//! The method occupiedArea returns all grid positions that are occupied by the ship
	/*!
	 If e.g. the ship's bow is at B2 and its stern at E2, then the function return B2, C2, D2, E2.
	 \return std::set<GridPosition> of the GridPosition that the Ship occupies */
	const std::set<GridPosition> occupiedArea() const;

	//! The method returns the set of grid positions occupied by the ship and all surrounding grid positions
	/*!
	If e.g. the ship's bow is at A1 and its stern at A3, then the function return A1, B1, A2, B2, A3, B3, A4, B4.\n\n
	The purpose of this method is to use with occupiedArea() of another ship and implement the  "ships mustn't touch" rule.
	For a ship to be placed on the grid check for each ship already on the grid that
	 the intersection of the already placed ship's blocked area and the new ship's occupied
	area is the empty set.\n\n
	Algorithm: \n
	1. Start with an empty result set\n
	2. For each grid position from occupied area, add the position and all eight surrounding positions to the result
	\return std::set<GridPosition> of the GridPosition that the Ship blocks */
	const std::set<GridPosition> blockedArea() const;

	//! A destructor
	virtual ~Ship();
};

#endif /* SHIP_H_ */
