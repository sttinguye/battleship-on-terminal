/*
 * GridPosition.cpp
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#include "GridPosition.h"
#include <cassert>
#include <cmath> // for sqrt()

GridPosition::GridPosition(char row, int column) : row{row}, column{column}
{
	//assert(isValid() && "Position must have row between 'A' and 'Z', and column >= 1");
}

GridPosition::GridPosition(std::string position)
{
	// "extract" the first character of the std::string position to make it row index
	this->row = position[0];

	// since I "extract" the first character of the std::string position => minus by 1
	auto numberOfCharacterOfColumn{ (position.length() - 1) };

	// std::stoi returns type int
	this->column = std::stoi(position.substr(1, numberOfCharacterOfColumn));

	//assert(isValid() && "Position must have row between 'A' and 'Z', and column >= 1");
}

bool GridPosition::isValid() const
{
	return (this->row >= 'A' && this->row <= 'Z' && this->column >= 1);
}

char GridPosition::getRow() const
{
	return this->row;
}

int GridPosition::getColumn() const
{
	return this->column;
}

GridPosition::operator std::string() const
{
	std::string position(1, this->row); // std::string position{this->row};
	position += std::to_string(this->column);
	return position;
}

bool GridPosition::operator ==(GridPosition other) const
{
	return (this->row == other.getRow() && this->column == other.getColumn());
}

bool GridPosition::operator <(GridPosition other) const
{
	// old code
#if 0
	if ( this->row < other.getRow() )
	{
		return true;
	}
	else if ( this->row == other.getRow() )
	{
		if ( this->column < other.getColumn() )
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
#endif

	// new code
#if 1

	double distance{ sqrt(this->row*this->row + this->column*this->column) };
	double otherDistance{ sqrt( other.getRow() * other.getRow()  + other.getColumn()*other.getColumn()) };

	if (distance < otherDistance)
	{
		return true;
	}

	return false;
#endif
}

GridPosition::~GridPosition()
{
	// TODO Auto-generated destructor stub
}

