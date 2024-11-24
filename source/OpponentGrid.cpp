/*
 * OpponentGrid.cpp
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#include "OpponentGrid.h"
#include <iostream> // for debugging

// Using direct initialization, we can create a vector with 10 elements,
// each element is Object Ship. If we use brace initialization, the vector would
// have 1 element, a 10, which will return error.
OpponentGrid::OpponentGrid() : rows{10}, columns{10}
{
}

OpponentGrid::OpponentGrid(int rows, int columns) : rows{rows}, columns{columns}
{
}

int OpponentGrid::getRows() const
{
	return this->rows;
}

int OpponentGrid::getColumns() const
{
	return this->columns;
}

const std::vector<Ship> OpponentGrid::getSunkenShips() const
{
	return this->sunkenShips;
}

void OpponentGrid::shotResult(const Shot &shot, Shot::Impact impact)
{
#if 1
	this->shots.insert( {shot.getTargetPosition(), impact} );

	if (impact == Shot::Impact::SUNKEN)
	{
		bool westFlag{false};
		bool eastFlag{false};
		bool southFlag{false};
		bool northFlag{false};

		GridPosition westEndPoint{'A', 1};
		GridPosition eastEndPoint{'A', 1};
		GridPosition southEndPoint{'A', 1};
		GridPosition northEndPoint{'A', 1};

		// check West => (row, column - 1)
		char westRow{ shot.getTargetPosition().getRow() };
		int westColumn{ shot.getTargetPosition().getColumn() - 1 };
		if ( this->canSunkShipInThisDirection(westRow, westColumn, 0, -1) )
		{
			westFlag = true;
			westEndPoint = { this->sunkShipInThisDirection(westRow, westColumn, 0, -1) };
		}

		// check East => (row, column + 1)
		char eastRow{ shot.getTargetPosition().getRow() };
		int eastColumn{ shot.getTargetPosition().getColumn() + 1 };
		if ( this->canSunkShipInThisDirection(eastRow, eastColumn, 0, +1) )
		{
			eastFlag = true;
			eastEndPoint = { this->sunkShipInThisDirection(eastRow, eastColumn, 0, +1) };
		}

		// check South => (row + 1, column)
		char southRow{ static_cast<char>(shot.getTargetPosition().getRow() + 1) };
		int southColumn{ shot.getTargetPosition().getColumn() };
		if ( this->canSunkShipInThisDirection(southRow, southColumn, +1, 0) )
		{
			southFlag = true;
			southEndPoint = {this->sunkShipInThisDirection(southRow, southColumn, +1, 0)};
		}

		// check North => (row - 1, column)
		char northRow{ static_cast<char>(shot.getTargetPosition().getRow() - 1) };
		int northColumn{ shot.getTargetPosition().getColumn() };
		if ( this->canSunkShipInThisDirection(northRow, northColumn, -1, -0) )
		{
			northFlag = true;
			northEndPoint = { this->sunkShipInThisDirection(northRow, northColumn, -1, 0) };
		}



		if ( westFlag && eastFlag )
		{
			this->sunkenShips.push_back( Ship{ westEndPoint, eastEndPoint } );
		}

		if ( northFlag && southFlag )
		{
			this->sunkenShips.push_back( Ship{ northEndPoint, southEndPoint } );
		}

		if ( westFlag && !eastFlag )
		{
			this->sunkenShips.push_back(Ship{ westEndPoint, shot.getTargetPosition() });
		}

		if ( !westFlag && eastFlag )
		{
			this->sunkenShips.push_back(Ship{ shot.getTargetPosition(), eastEndPoint });
		}

		if ( northFlag && !southFlag )
		{
			this->sunkenShips.push_back( Ship{ northEndPoint, shot.getTargetPosition() } );
		}

		if ( !northFlag && southFlag )
		{
			this->sunkenShips.push_back( Ship{ shot.getTargetPosition(), southEndPoint } );
		}


	}
#endif
}

const std::map<GridPosition, Shot::Impact>& OpponentGrid::getShotAt() const
{
	return this->shots;
}

bool OpponentGrid::canSunkShipInThisDirection(
		char row_plus_delta,
		int column_plus_delta,
		int delta_row,
		int delta_column)
{
#if 0
	std::cout << "inside canSunkShipInThisDirection() reached!\n";
	std::cout << row_plus_delta << ' ' << column_plus_delta << ' '
			<< delta_row << ' ' << delta_column << "\n\n";
#endif



	GridPosition deltaPosition {  row_plus_delta, column_plus_delta };

	int rowIndex =  static_cast<int>(row_plus_delta - 'A' + 1); // look at ASCII
	int columnIndex = column_plus_delta;

	//std::cout << "- rowIndex: " << rowIndex << '\n';
	//std::cout << "- columnIndex: " << columnIndex << '\n';

	if ( rowIndex <= this->rows
			&& columnIndex <= this->columns
			&& deltaPosition.isValid() )
	{
		// if the map of shots has this coordinates
		if ( this->shots.count(deltaPosition) > 0 )
		{

			if (this->shots[deltaPosition] == Shot::Impact::HIT)
			{
				while (rowIndex <= this->rows
						&& columnIndex <= this->columns
						&& deltaPosition.isValid())
				{

					if ( this->shots.count(deltaPosition) > 0 )
					{

						if (this->shots[deltaPosition] != Shot::Impact::HIT)
						{
							return true;
						}
						else if (this->shots[deltaPosition]
								== Shot::Impact::HIT)
						{
							row_plus_delta += delta_row;
							column_plus_delta += delta_column;

							deltaPosition = GridPosition{ row_plus_delta, column_plus_delta };

							rowIndex =
									static_cast<int>(row_plus_delta - 'A' + 1); // look at ASCII
							columnIndex = column_plus_delta;
						}

					}
					else
					{
						return true;
					}

					return true; // new fix
				} // end of while loop

			}
			else // else if ( this->shots.at(position_plus_delta) != Shot::Impact::HIT )
			{
				return false;
			}
		}
		else
		{
			return false;
		}

	}

	return false;

}

GridPosition OpponentGrid::sunkShipInThisDirection(
		char row_plus_delta,
		int column_plus_delta,
		int delta_row,
		int delta_column)
{
	GridPosition deltaPosition {  row_plus_delta, column_plus_delta };


	while ( (this->shots.count(deltaPosition) > 0) && (this->shots[deltaPosition] == Shot::Impact::HIT) )
	{

		this->shots[deltaPosition] = Shot::Impact::SUNKEN;

		row_plus_delta += delta_row;
		column_plus_delta += delta_column;

		deltaPosition = GridPosition{ row_plus_delta, column_plus_delta };

	}
	//while (this->shots[deltaPosition] == Shot::Impact::HIT)
	//{

	//}

	row_plus_delta -= delta_row;
	column_plus_delta -= delta_column;
	deltaPosition = GridPosition{ row_plus_delta, column_plus_delta };

	return deltaPosition;

}

OpponentGrid::~OpponentGrid()
{
	// TODO Auto-generated destructor stub
}

