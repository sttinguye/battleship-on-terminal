/*
 * OwnGrid.cpp
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#include "OwnGrid.h"
#include <algorithm> // for std::set_intersection
#include <iostream> // for debugginbf


// Using direct initialization, we can create a vector with 10 elements,
// each element is Object Ship. If we use brace initialization, the vector would
// have 1 element, a 10, which will return error.
OwnGrid::OwnGrid() : rows{10}, columns{10}, availableShips { { 5, 1 }, { 4, 2 }, { 3, 3 }, { 2, 4 } }
	,largestPosition{ GridPosition{ 'J', 10 } }
{
}

Shot::Impact OwnGrid::takeBlow(const Shot &shot)
{
	for (size_t shipIndex{0}; shipIndex < this->ships.size(); ++shipIndex)
	{
		for (GridPosition index : this->ships[shipIndex].occupiedArea())
		{
			if (index == shot.getTargetPosition())
			{
				std::set<GridPosition> intersect;

				std::set_intersection(
						this->ships[shipIndex].occupiedArea().begin(),
						this->ships[shipIndex].occupiedArea().end(),
						shotAt.begin(),
						shotAt.end(),
						std::inserter(intersect, intersect.begin()));

				if (this->ships[shipIndex].length() - intersect.size() == 1)
				{
					this->shotAt.insert(shot.getTargetPosition());
					return Shot::Impact::SUNKEN;
				}
				else
				{
					this->shotAt.insert(shot.getTargetPosition());
					return Shot::Impact::HIT;
				}
			}

		}
	}

	// this include cases where player choose to shoot at invalid Position.
	// e.g., "@2" or "A0"
	if (!shot.getTargetPosition().isValid())
	{
		// does not add invalid shot to the set missShotAt
		return Shot::Impact::NONE;
	}

	if ( this->columns < shot.getTargetPosition().getColumn() )
	{
		// does not add invalid shot to the set missShotAt
		return Shot::Impact::NONE;
	}

	if ( this->rows < (shot.getTargetPosition().getRow() - 'A' + 1)  )
	{
		// does not add invalid shot to the set missShotAt
		return Shot::Impact::NONE;
	}


	this->missShotAt.insert(shot.getTargetPosition());
	return Shot::Impact::NONE;
}

const std::set<GridPosition> OwnGrid::getShotAt() const
{
	return this->shotAt;
}

const std::set<GridPosition> OwnGrid::getMissShotAt() const
{
	return this->missShotAt;
}

#if 1
GridPosition OwnGrid::getLargestPosition() const
{
	return this->largestPosition;
}
#endif

OwnGrid::~OwnGrid()
{
	// TODO Auto-generated destructor stub
}

OwnGrid::OwnGrid(int rows, int columns) : rows{rows}, columns{columns},
		availableShips { { 5, 1 }, { 4, 2 }, { 3, 3 }, { 2, 4 } }
		,largestPosition{ GridPosition{ static_cast<char>(this->getRows() + 'A' - 1), this->columns } }
		// minus 1 because we dont count 'A' here. Check ASCII table!
{
}

int OwnGrid::getRows() const
{
	return this->rows;
}

int OwnGrid::getColumns() const
{
	return this->columns;
}

bool OwnGrid::placeShip(const Ship &ship)
{
	// Ships may not touch each other
	std::set<GridPosition> newShipOccupiedArea = ship.occupiedArea();

#if 0
	std::cout << "\n inside method 1: \n";
	for (auto index : newShipOccupiedArea)
	{
		std::cout << index.getRow() << "-" << index.getColumn() << '\n';
	}

	std::cout << "\n this->ships.size() =  " << this->ships.size();
#endif
	std::set<GridPosition> forLoopShipBlockedArea;
	std::set<GridPosition> intersect;

	for (std::size_t shipIndex{0}; shipIndex < this->ships.size(); ++shipIndex)
	{
		forLoopShipBlockedArea = this->ships[shipIndex].blockedArea();

		// for debugging
#if 0
		std::cout << "\n inside method 2: \n";
		for (auto index : forLoopShipBlockedArea)
		{
			std::cout << index.getRow() << "-" << index.getColumn() << '\n';
		}
#endif

		std::set_intersection(
				newShipOccupiedArea.begin(),
				newShipOccupiedArea.end(),
				forLoopShipBlockedArea.begin(),
				forLoopShipBlockedArea.end(),
			    std::inserter( intersect, intersect.begin() ) );
	}
	// for debugging
#if 0
	std::cout << "\n inside method 3: \n";
	for (auto index : intersect)
	{
		std::cout << index.getRow() << "-" << index.getColumn() << '\n';
	}
	std::cout << '\n';
	std::cout << "??: " << intersect.empty();
#endif

	if(!intersect.empty())
	{
		return false;
	}

	// Ship must be valid: NOT diagonal, must be between 2 and 5, GridPosition is valid
	if (!ship.isValid())
	{
		return false;
	}

	// must not place ship cross the border of board
	// original code --> very hard to read
#if 1
	// must not place ship cross the border of board
	auto newShipBow { ship.getBow() };
	auto newShipStern { ship.getStern() };
	auto newShipLength {ship.length() };

	if (newShipBow < newShipStern)
	{
		if (newShipBow.getRow() == newShipStern.getRow())
		{
			// minus 1 here because row starts from 1 while column starts from 0
			if ( this->columns < (newShipBow.getColumn() + newShipLength - 1))
			{
				return false;
			}
		}
		else // else if ( bow.getColumn() == stern.getColumn() ) ?
		{
			if ( this->rows < (newShipBow.getRow() - 'A' + newShipLength ))
			{
				return false;
			}
		}
	}
	else // else if (newShipStern < newShipBow)
	{
		if (newShipBow.getRow() == newShipStern.getRow())
		{
			// minus 1 here because row starts from 1 while column starts from 0
			if (this->columns < (newShipStern.getColumn() + newShipLength - 1))
			{
				return false;
			}
		}
		else // else if ( bow.getColumn() == stern.getColumn() ) ?
		{
			if (this->rows < (newShipStern.getRow() - 'A' + newShipLength ))
			{
				return false;
			}
		}
	}
#endif

	// must not place ship cross the border of board
	// new code --> easier to read
	// however, wrong. the board will act strangely
	// just stick to the old code
#if 0
	if ( this->largestPosition < ship.getBow() )
	{
		return false;
	}

	if ( this->largestPosition < ship.getStern() )
	{
		return false;
	}
#endif

	std::map<int, int>::iterator it;
	for (it = this->availableShips.begin(); it != this->availableShips.end(); ++it)
	{
		if (it->first == ship.length())
		{
			if (it->second > 0)
			{
				--(it->second);
				this->ships.push_back(ship);
				return true;
			}
			else
			{
				return false;
			}
		}
	}


	// this step will never be reached. I put return false here so that the compiler won't complain
	//this->ships.push_back(ship);
	return false;
}

const std::vector<Ship> OwnGrid::getShips() const
{
	return this->ships;
}
