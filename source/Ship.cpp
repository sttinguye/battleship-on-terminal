/*
 * Ship.cpp
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#include "Ship.h"
#include <cassert> // for assert()
#include <cstdlib> // for std::abs()

Ship::Ship(const GridPosition &bow, const GridPosition &stern) : bow{bow}, stern{stern}
{
	//assert(isValid() && "Length of Ship must be between 2 and 5");
}

bool Ship::isValid() const
{
	// check if bow and stern are valid
	if( !bow.isValid() || !stern.isValid() )
	{
		return false;
	}

	// check if object Ship is diagonal or not
	if (bow.getRow() != stern.getRow() && bow.getColumn() != stern.getColumn())
	{
		return false;
	}

	// check if length is between 2 and 5
	if (length() < 2 || length() > 5)
	{
		return false;
	}

	return true;
}

GridPosition Ship::getBow() const
{
	return this->bow;
}

GridPosition Ship::getStern() const
{
	return this->stern;
}

int Ship::length() const
{
	// This method assumes the object Ship is NOT diagonal.
	if (bow.getRow() == stern.getRow())
	{
		return std::abs(bow.getColumn() - stern.getColumn()) + 1;
	}
	else
	{
		return std::abs(bow.getRow() - stern.getRow()) + 1;
	}
}

const std::set<GridPosition> Ship::occupiedArea() const
{
	//this method assumes that the ship are NOT placed diagonally (i.e., either placed vertically or horizontally)

	// initially add bow and stern to the occupiedArea() set
	std::set<GridPosition> occupiedArea = {this->bow, this->stern};

	if (this->bow < this->stern)
	{
		if (bow.getRow() == stern.getRow())
		{
			// do not count the bow and stern of ship
			int remainingColumns{ length() - 2 };

			for (int columnIndex{0}; columnIndex < remainingColumns; ++columnIndex)
			{
				occupiedArea.insert(GridPosition(bow.getRow(), bow.getColumn() + 1 + columnIndex));
			} // end of for loop

		}// end of if (bow.getRow() == stern.getRow())
		else // else if ( bow.getColumn() == stern.getColumn() ) ?
		{

			int remainingRows{ length() - 2 };

			for (int rowIndex{ 0 }; rowIndex < remainingRows; ++rowIndex)
			{
				occupiedArea.insert(GridPosition(bow.getRow() + 1 + rowIndex, bow.getColumn()));
			} // end of for loop

		}// end of else if bow.getColumn() equals to stern.getColumn()

	}// end of if (this->bow < this->stern)
	else // else if (this->stern < this->bow) ?
	{
		if (stern.getRow() == bow.getRow())
		{

			int remainingColumns{ length() - 2 };

			for (int columnIndex{ 0 }; columnIndex < remainingColumns; ++columnIndex)
			{
				occupiedArea.insert(GridPosition(stern.getRow(), stern.getColumn() + 1 + columnIndex));
			} // end of for loop

		} // end of if (stern.getRow() == bow.getRow())
		else // else if ( stern.getColumn() == bow.getColumn() ) ?
		{

			int remainingRows{ length() - 2 };

			for (int rowIndex{ 0 }; rowIndex < remainingRows; ++rowIndex)
			{
				occupiedArea.insert(GridPosition(stern.getRow() + 1 + rowIndex, stern.getColumn()));
			} // end of for loop

		} // end of else if( stern.getColumn() == bow.getColumn() ) ?

	}// end of else if (this->stern < this->bow) ?

	return occupiedArea;
}

const std::set<GridPosition> Ship::blockedArea() const
{
	std::set<GridPosition> blockedArea = this->occupiedArea();

	for (GridPosition index : occupiedArea())
	{
		// check East => (row, column + 1)
		if (GridPosition(index.getRow(), index.getColumn() + 1).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow(), index.getColumn() + 1));
		}

		// check West => (row, column - 1)
		if (GridPosition(index.getRow(), index.getColumn() - 1).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow(), index.getColumn() - 1));
		}

		// check South => (row + 1, column)
		if (GridPosition(index.getRow() + 1, index.getColumn()).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow() + 1, index.getColumn()));
		}

		// check North => (row - 1, column)
		if (GridPosition(index.getRow() - 1, index.getColumn()).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow() - 1, index.getColumn()));
		}

		// check East North => (row - 1, column + 1)
		if (GridPosition(index.getRow() - 1, index.getColumn() + 1).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow() - 1, index.getColumn() + 1));
		}

		// check East South => (row + 1, column + 1)
		if (GridPosition(index.getRow() + 1, index.getColumn() + 1).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow() + 1, index.getColumn() + 1));
		}

		// check West North => (row - 1, column - 1)
		if (GridPosition(index.getRow() - 1, index.getColumn() - 1).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow() - 1, index.getColumn() - 1));
		}

		// check West South => (row + 1, column - 1)
		if (GridPosition(index.getRow() + 1, index.getColumn() - 1).isValid())
		{
			blockedArea.insert(GridPosition(index.getRow() + 1, index.getColumn() - 1));
		}
	}

	return blockedArea;
}

Ship::~Ship()
{
	// TODO Auto-generated destructor stub
}
