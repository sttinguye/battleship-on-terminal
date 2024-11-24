/*
 * GridPosition.h
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <string>

//!  The most basic class represents a grid position, i.e. a row and a column on the board
/*!
  The class is immutable. Once an object is created, its state cannot be modified.\n
  A GridPosition can be created from individually specified row and column arguments or from a string such as "B10".
*/
class GridPosition
{
private:

	//!  Coordinate row. char type
	char row;

	//!  Coordinate column. int type
	int column;

public:

	//! Constructor create from individually specified row and column arguments
	/*!
	 \param row Coordinate Row
	 \param column Coordinate column
	 \sa GridPosition(std::string position) */
	GridPosition(char row, int column);

	//! Constructor create from a string such as "B10"
	/*!
	 \param position string containing row and column
	 \sa GridPosition(char row, int column) */
	GridPosition(std::string position);

	//! Method that checks the validity of a coordinate
	/*!
	 Because we have to create an object no matter what arguments are passed to the constructor (e.g.
	'@' and -15) the created object may have invalid values in its data members. The validity can be
	checked by calling isValid. The method checks that 'A' <= row <= 'Z' and column > 0.
	\return true or false */
	bool isValid() const;

	//! A method to access the row coordinate
	/*!
	 \return the row coordinate in char type
	 \sa getColumn() */
	char getRow() const;

	//! A method to access the column coordinate
	/*!
	 \return the column coordinate in int type
	 \sa getRow() */
	int getColumn() const;

	//! The overloaded cast to string returns the concatenation of the row and the column (e.g. "B10")
	/*!
	\return std::string that represents row and column*/
	operator std::string() const;

	//! The operator == that checks equality comparision between two GridPosition objects
	/*!
	\return true or false*/
	bool operator==(GridPosition other) const;

	//! The operator < assumes the fields to be ordered from top left to bottom right (e.g. A1 ... J10).
	/*!
	We need this operator for many reasons but the most specific reason is that
	later on we will use std::set<GridPosition> and std::set only works with operator < \n
	For example, set_interset() gives desirable behavior if and only if the operator < gives desirable behavior\n
	The algorithm to determine which GridPosition is less than which is Pythagorean theorem.
	Calculate the 2 Pythagorean distance and do comparision to determine which is less than another.
	\return true or false */
	bool operator<(GridPosition other) const;

	//! Destructor.
	virtual ~GridPosition();
};

#endif /* GRIDPOSITION_H_ */
