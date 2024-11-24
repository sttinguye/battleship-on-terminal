/*
 * part2tests.cpp
 *
 *  Created on: Dec 9, 2022
 *      Author: profe
 */

#include "part2tests.h"
#include <string>
#include <iostream>

void assertTruePart2(bool condition, std::string failedMessage)
{
	if (!condition)
	{
		std::cout << failedMessage << std::endl;
	}
}

void part2tests()
{
	Board board{10, 10};
	std::cout << "START!" << '\n';
	ConsoleView console(&board);
	console.print();

	assertTruePart2( !(board.getOwnGrid().placeShip( Ship{ GridPosition{"A1"}, GridPosition{"A5"} } )),
			"\nShip #1 (A1/A5)\n");
	console.print();

	assertTruePart2( !(board.getOwnGrid().placeShip( Ship{ GridPosition{"A7"}, GridPosition{"A9"} } )),
			"\nTest case #2: Ship #2 (A7/A9) -> VALID\n");
	console.print();

	assertTruePart2(board.getOwnGrid().placeShip( Ship{ GridPosition{"B3"}, GridPosition{"D3"} } ),
			"\nTest case #3: Ship #3 (B3/D3) -> touch Ship #1 (A1/A5) -> Will not display\n");
	console.print();

	assertTruePart2(board.getOwnGrid().placeShip( Ship{ GridPosition{"C5"}, GridPosition{"C10"} } ),
			"\nTest case #4: Ship #4 (C5/C10) -> length of 6 -> Will not display\n");
	console.print();

	assertTruePart2( board.getOwnGrid().placeShip( Ship{ GridPosition{"I2"}, GridPosition{"F5"} } ),
			"\nTest case #5: Ship #5 (I2/F5) -> diagonal ship -> Will not display\n" );
	console.print();

	assertTruePart2( board.getOwnGrid().placeShip( Ship{ GridPosition{"H8"}, GridPosition{"H11"} } ),
			"\nTest case #6: Ship #6 (H8/H11) -> out of border -> Will not display\n" );
	console.print();

	assertTruePart2( board.getOwnGrid().placeShip( Ship{ GridPosition{"H7"}, GridPosition{"N7"} } ),
			"\nTest case #7: Ship #7 (H7/N7) -> out of border -> Will not display\n" );
	console.print();

	assertTruePart2( board.getOwnGrid().placeShip( Ship{ GridPosition{"D6"}, GridPosition{"D10"} } ),
			"\nTest case #8: Ship #8 (D6/D10) -> another ship of size 5 -> Will not display\n" );
	console.print();

	std::cout <<"Test case #9: Place 8 remaining ships" <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"J8"}, GridPosition{"J10"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"D1"}, GridPosition{"F1"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"G3"}, GridPosition{"G4"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"D8"}, GridPosition{"E8"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"H7"}, GridPosition{"G7"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"I2"}, GridPosition{"I3"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"C10"}, GridPosition{"F10"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"C3"}, GridPosition{"C6"} } );
	console.print();

	assertTruePart2( board.getOwnGrid().placeShip( Ship{ GridPosition{"E3"}, GridPosition{"E5"} } ),
			"\nTest case #10: Place an 11th Ship (E3/E5) -> Invalid -> Will not display\n" );
	console.print();
}


void part2testsOld()
{
	Board board{10, 10};
	std::cout << "START!" << '\n';
	ConsoleView console(&board);
	console.print();

	//std::cout << "print J10" <<'\n';
	//std::cout << board.getOwnGrid().getLargestPosition().getRow() << "-" << board.getOwnGrid().getLargestPosition().getColumn()
	//		<< '\n';

	std::cout <<"Ship #1 (A1/A5)" <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"A1"}, GridPosition{"A5"} } );
	console.print();

	// for debugging
#if 0
	for (auto index : board.getOwnGrid().getShips().at(0).occupiedArea())
	{
		std::cout <<  index.getRow() << "-" << index.getColumn() << '\n';
	}
	std::cout << '\n';
	for (auto index : board.getOwnGrid().getShips().at(0).blockedArea())
	{
		std::cout <<  index.getRow() << "-" << index.getColumn() << '\n';
	}
	std::cout << '\n';
#endif

	std::cout <<"Test case #1: Ship #_ (A6/A7) -> touch Ship #1 (A1/A5) -> will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"A6"}, GridPosition{"A7"} } );
	console.print();

	//for debugging
#if 0
	for (auto index : board.getOwnGrid().getShips().at(1).occupiedArea())
	{
		std::cout << index.getRow() << "-" << index.getColumn() << '\n';
	}
	std::cout << '\n';
	for (auto index : board.getOwnGrid().getShips().at(1).blockedArea())
	{
		std::cout << index.getRow() << "-" << index.getColumn() << '\n';
	}
	std::cout << '\n';

	//std::cout << board.getOwnGrid().placeShip( Ship{ GridPosition{"A6"}, GridPosition{"A7"} } ) << '\n';



	std::cout << "print H8/H11" <<'\n';
	std::cout << board.getOwnGrid().placeShip( Ship{ GridPosition{"H8"}, GridPosition{"H11"} } )
		<< '\n';

#endif

#if 1
	std::cout <<"Test case #2: Ship #2 (A7/A9) -> VALID " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"A7"}, GridPosition{"A9"} } );
	console.print();


	std::cout <<"Test case #3: Ship #3 (B3/D3) -> touch Ship #1 (A1/A5) -> Will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"B3"}, GridPosition{"D3"} } );
	console.print();

	board.getOwnGrid().placeShip( Ship{ GridPosition{"A3"}, GridPosition{"C3"} } );

	std::cout <<"Test case #4: Ship #4 (C5/C10) -> length of 6 -> Will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"C5"}, GridPosition{"C10"} } );
	console.print();

	std::cout <<"Test case #5: Ship #5 (I2/F5) -> diagonal ship -> Will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"I2"}, GridPosition{"F5"} } );
	console.print();

	std::cout <<"Test case #6: Ship #6 (H8/H11) -> out of border -> Will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"H8"}, GridPosition{"H11"} } );
	console.print();

	std::cout <<"Test case #7: Ship #7 (H7/N7) -> out of border -> Will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"H7"}, GridPosition{"N7"} } );
	console.print();

	std::cout <<"Test case #8: Ship #8 (D6/D10) -> another ship of size 5 -> Will not display " <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"D6"}, GridPosition{"D10"} } );
	console.print();

	std::cout <<"Test case #9: Place 8 remaining ships" <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"J8"}, GridPosition{"J10"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"D1"}, GridPosition{"F1"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"G3"}, GridPosition{"G4"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"D8"}, GridPosition{"E8"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"H7"}, GridPosition{"G7"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"I2"}, GridPosition{"I3"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"C10"}, GridPosition{"F10"} } );
	board.getOwnGrid().placeShip( Ship{ GridPosition{"C3"}, GridPosition{"C6"} } );
	console.print();

	std::cout <<"Test case #10: Place an 11th Ship (E3/E5) -> Invalid -> Will not display" <<  '\n';
	board.getOwnGrid().placeShip( Ship{ GridPosition{"E3"}, GridPosition{"E5"} } );
	console.print();
#endif
}
