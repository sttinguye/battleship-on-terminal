/*
 * Shot.h
 *
 *  Created on: Dec 8, 2022
 *      Author: profe
 */

#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

//!  This class represents a Shot
/*! The Opponent will shoot a Shot at your OwnGrid. You have to announce if the Shot hit your Ship, miss your Ship,
 * or sink your whole Ship */
class Shot
{
private:
	//!  GridPosition of a Shot
	GridPosition targetPosition;

public:
	//! An enum that represents a missed Shot, a hit Shot, and a Shot that sink the whole Ship
	/*! A Shot is either miss, hit, or a shot that sink the ship. */
	enum Impact
	{
		NONE,	/*!< A missed Shot */
		HIT,	/*!< A hit Shot */
		SUNKEN,	/*!< A Shot that sink the whole Ship*/
	};

	//! A Constructor taking one GridPosition as its argument
	Shot(GridPosition targetPosition);

	//! A method to access GridPosition of a Shot
	/*!
	 \return the GridPosition of a Shot */
	GridPosition getTargetPosition() const;

	//! A Destructor
	virtual ~Shot();
};

#endif /* SHOT_H_ */
