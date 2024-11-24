/*
 * ConsoleView.cpp
 *
 *  Created on: Dec 6, 2022
 *      Author: profe
 */

#include "ConsoleView.h"
#include <iostream>
#include <vector>
#include <set>

ConsoleView::ConsoleView(Board *board) : board{board},
	ownGridRows{ board->getOwnGrid().getRows() },
	ownGridColumns{ board->getOwnGrid().getColumns() },
	opponentGridRows{ board->getOpponentGrid().getRows() },
	opponentGridColumns{ board->getOpponentGrid().getColumns() },
	ownGrid{ new char[ board->getOwnGrid().getRows() * board->getOwnGrid().getColumns() ] {} },
	opponentGrid{ new char[ board->getOpponentGrid().getRows() * board->getOpponentGrid().getColumns() ] {} }
{
	for (int rowIndex{ 0 }; rowIndex < ownGridRows; ++rowIndex)
	{
		for (int columnIndex{ 0 }; columnIndex < ownGridColumns; ++columnIndex)
		{
			ownGrid[convert2Dto1D(rowIndex, columnIndex, ownGridColumns)] = '~';
		}
	}

	for (int rowIndex{ 0 }; rowIndex < opponentGridRows; ++rowIndex)
	{
		for (int columnIndex{ 0 }; columnIndex < opponentGridColumns; ++columnIndex)
		{
			opponentGrid[convert2Dto1D(rowIndex, columnIndex, opponentGridColumns)] = '~';
		}
	}
}

ConsoleView::~ConsoleView()
{
	delete[] ownGrid;
	ownGrid = nullptr;
	delete[] opponentGrid;
	opponentGrid = nullptr;
}

int ConsoleView::convert2Dto1D(int rowIndex, int columnIndex, int columns) const
{
	return ((rowIndex * columns) + columnIndex);
}

void ConsoleView::update()
{
	std::vector<Ship> ownGridShips = this->board->getOwnGrid().getShips();
	std::map<GridPosition, Shot::Impact> opponentGridShips = this->board->getOpponentGrid().getShotAt();

	for (std::size_t shipIndex{0}; shipIndex < ownGridShips.size(); ++shipIndex)
	{
		for (GridPosition index : ownGridShips[shipIndex].occupiedArea())
		{
			ownGrid[convert2Dto1D(
					index.getRow() - 'A',
					index.getColumn() - 1,
					ownGridColumns)] = '#';
		}
	}

	// hit shots
	for (GridPosition index : this->board->getOwnGrid().getShotAt())
	{
		ownGrid[convert2Dto1D(index.getRow() - 'A', index.getColumn() - 1,
				ownGridColumns)] = 'O';
	}

	// miss shots
	for (GridPosition index : this->board->getOwnGrid().getMissShotAt())
	{
		ownGrid[convert2Dto1D(index.getRow() - 'A', index.getColumn() - 1,
				ownGridColumns)] = '^';
	}


#if 1

	std::map<GridPosition, Shot::Impact>::iterator it;
	for ( it = opponentGridShips.begin(); it != opponentGridShips.end(); ++it )
	{
		if ( it->second == Shot::Impact::SUNKEN )
		{
			opponentGrid[convert2Dto1D(it->first.getRow() - 'A',
							it->first.getColumn() - 1, opponentGridColumns)] = '#';
		}

		if ( it->second == Shot::Impact::HIT )
		{
			opponentGrid[ convert2Dto1D(it->first.getRow() - 'A', it->first.getColumn() - 1,
					opponentGridColumns) ] = 'O';
		}

		if ( it->second == Shot::Impact::NONE )
		{
			opponentGrid[convert2Dto1D(it->first.getRow() - 'A',
					it->first.getColumn() - 1, opponentGridColumns)] = '^';
		}


	}
#endif

}

void ConsoleView::print()
{
	this->update();

	std::cout << "\n  ";

	if (ownGridColumns>=10)
	{
		for (int columnIndex{ 0 }; columnIndex < ownGridColumns; ++columnIndex)
		{
			if (columnIndex >= 9)
			{
				std::cout << static_cast<char>((columnIndex+1) / 10 % 10 + '0') << ' ';
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << "   ";
	}

	if (opponentGridColumns >= 10)
	{
		for (int columnIndex{ 0 }; columnIndex < opponentGridColumns; ++columnIndex)
		{
			if (columnIndex >= 9)
			{
				std::cout << static_cast<char>((columnIndex + 1) / 10 % 10 + '0') << ' ';
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << '\n';
	}

	if (ownGridColumns >= 10)
	{
		std::cout << "  ";
		for (int columnIndex{ 0 }; columnIndex < ownGridColumns; ++columnIndex)
		{
			if (columnIndex >= 9)
			{
				std::cout << static_cast<char>((columnIndex + 1) % 10 + '0') << ' ';
			}
			else
			{
				std::cout << columnIndex + 1 << ' ';
			}
		}
		std::cout << "   ";
	}

	if (opponentGridColumns >= 10)
	{
		for (int columnIndex{ 0 }; columnIndex < opponentGridColumns; ++columnIndex)
		{
			if (columnIndex >= 9)
			{
				std::cout << static_cast<char>((columnIndex + 1) % 10 + '0') << ' ';
			}
			else
			{
				std::cout << columnIndex + 1 << ' ';
			}
		}
		std::cout << '\n';
	}

	if (ownGridColumns<10)
	{
		for (int columnIndex{ 0 }; columnIndex < ownGridColumns; ++columnIndex)
		{
			std::cout << columnIndex + 1 << ' ';
		}
		std::cout << "  ";
	}

	if (opponentGridColumns < 10)
	{
		for (int columnIndex{ 0 }; columnIndex < opponentGridColumns; ++columnIndex)
		{
			std::cout << columnIndex + 1 << ' ';
		}
		std::cout << '\n';
	}




	for (int rowIndex{0}; rowIndex < ownGridRows; ++rowIndex)
	{
		std::cout << static_cast<char>(rowIndex + 'A') << " ";

		for (int columnIndex{0}; columnIndex < ownGridColumns; ++columnIndex)
		{
			std::cout << ownGrid[convert2Dto1D(rowIndex, columnIndex, ownGridColumns)] << ' ';
		}

		std::cout << " ";

		std::cout << static_cast<char>(rowIndex + 'A') << " ";

		for (int innerColumnIndex {0}; innerColumnIndex < opponentGridColumns; ++innerColumnIndex)
		{
			std::cout << opponentGrid[convert2Dto1D(rowIndex, innerColumnIndex, opponentGridColumns)] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << '\n';


}

void ConsoleView::printSunkenShips()
{
	//std::cout <<"- Printing Bow and Stern of Ship: ";
	for (std::size_t shipIndex{0};
			shipIndex < this->board->getOpponentGrid().getSunkenShips().size(); ++shipIndex)
	{
		std::cout << "- Printing Bow and Stern of Ship: (Bow: "
				<< this->board->getOpponentGrid().getSunkenShips()[shipIndex].getBow().getRow()
				<< this->board->getOpponentGrid().getSunkenShips()[shipIndex].getBow().getColumn()
				<< ", Stern: "
				<< this->board->getOpponentGrid().getSunkenShips()[shipIndex].getStern().getRow()
				<< this->board->getOpponentGrid().getSunkenShips()[shipIndex].getStern().getColumn()
				<< ')'
				<< '\n';


		std::cout <<"----> Corresponding occupied area: ";
		for (GridPosition index : this->board->getOpponentGrid().getSunkenShips()[shipIndex].occupiedArea())
		{
			std::cout << index.getRow() << index.getColumn() << ", ";
		}

			std::cout <<'\n' << '\n';
	}



}
