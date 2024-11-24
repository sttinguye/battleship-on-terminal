/*
 * Board.cpp
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#include "Board.h"

Board::Board() : rows{10}, columns{10}, ownGrid{10, 10}, opponentGrid{10, 10}
{
}

Board::Board(int rows, int columns) : rows{rows}, columns{columns},
		ownGrid(rows, columns), opponentGrid(rows, columns)
{
}

Board::~Board()
{
	// TODO Auto-generated destructor stub
}

int Board::getRows() const
{
	return this->rows;
}

int Board::getCols() const
{
	return this->columns;
}

OwnGrid& Board::getOwnGrid()
{
	return this->ownGrid;
}

OpponentGrid& Board::getOpponentGrid()
{
	return this->opponentGrid;
}
