/*
 * part3tests.cpp
 *
 *  Created on: Dec 9, 2022
 *      Author: profe
 */

#include "part3tests.h"
#include <string>
#include <iostream>

void whatShotIsThat(Shot::Impact shotType, std::string message)
{
	switch (shotType)
	{
	case Shot::Impact::HIT:
		std::cout << message << " is hit!\n";
		return;

	case Shot::Impact::NONE:
		std::cout << message << " is missed!\n";
		return;

	case Shot::Impact::SUNKEN:
		std::cout << message << " is sunken!\n";
		return;

	default:
		std::cout <<"???\n";
		return;

	}
}

void part3tests()
{
	Board board2{10, 10};
	ConsoleView console2(&board2);

	std::cout <<"\nPlace ship for shooting...\n";
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"A1"}, GridPosition{"A5"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"A7"}, GridPosition{"A9"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"J8"}, GridPosition{"J10"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"D1"}, GridPosition{"F1"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"G3"}, GridPosition{"G4"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"D8"}, GridPosition{"E8"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"H7"}, GridPosition{"G7"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"I2"}, GridPosition{"I3"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"C10"}, GridPosition{"F10"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"C3"}, GridPosition{"C6"} } );
	console2.print();

	std::cout <<"\nOwn Grid gets shots...\n";

	whatShotIsThat( board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J8"} } ), "Shot at J8" );
	whatShotIsThat( board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J9"} } ), "Shot at J9" );
	whatShotIsThat( board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J10"} } ), "Shot at J10" );
	whatShotIsThat( board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J5"} } ), "Shot at J5" );
	whatShotIsThat( board2.getOwnGrid().takeBlow( Shot{ GridPosition{"I4"} } ), "Shot at I4" );
	console2.print();

	std::cout <<"\nOpponent Grid gets shots...\n";

	std::cout <<"\nHit A1, A2, A3...\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A1"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A2"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A3"} }, Shot::Impact::HIT);
	console2.print();

	std::cout <<"\nA4 is sunken\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A4"} }, Shot::Impact::SUNKEN);
	console2.print();

	std::cout <<"\nHit A9, A10...\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A9"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A10"} }, Shot::Impact::HIT);
	console2.print();

	std::cout <<"\nA8 is sunken\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A8"} }, Shot::Impact::SUNKEN);
	console2.print();

	std::cout <<"\nHit A6, B6...\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A6"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"B6"} }, Shot::Impact::HIT);
	console2.print();

	std::cout <<"\nC6 is sunken\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"C6"} }, Shot::Impact::SUNKEN);
	console2.print();

	std::cout <<"\nHit H1, J1...\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"H1"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J1"} }, Shot::Impact::HIT);
	console2.print();

	std::cout <<"\nI1 is sunken\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"I1"} }, Shot::Impact::SUNKEN);
	console2.print();

	std::cout <<"\nG10, H10 are missed, and J10 is hit!\n";
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"G10"} }, Shot::Impact::NONE);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"H10"} }, Shot::Impact::NONE);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J10"} }, Shot::Impact::HIT);
	console2.print();

	std::cout <<"\nPrinting sunken ships\n";
	console2.printSunkenShips();

}


void part3testsOld()
{
	Board board2{10, 10};
	ConsoleView console2(&board2);

	std::cout <<"Place ship for shooting\n";
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"A1"}, GridPosition{"A5"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"A7"}, GridPosition{"A9"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"J8"}, GridPosition{"J10"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"D1"}, GridPosition{"F1"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"G3"}, GridPosition{"G4"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"D8"}, GridPosition{"E8"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"H7"}, GridPosition{"G7"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"I2"}, GridPosition{"I3"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"C10"}, GridPosition{"F10"} } );
	board2.getOwnGrid().placeShip( Ship{ GridPosition{"C3"}, GridPosition{"C6"} } );

	board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J8"} } );
	board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J9"} } );
	board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J10"} } );
	board2.getOwnGrid().takeBlow( Shot{ GridPosition{"J11"} } );

	board2.getOwnGrid().placeShip( Ship{ GridPosition{"J8"}, GridPosition{"J10"} } );

	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A1"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A2"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A3"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A4"} }, Shot::Impact::SUNKEN);

	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A9"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A10"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A8"} }, Shot::Impact::SUNKEN);

	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A6"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"B6"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"C6"} }, Shot::Impact::SUNKEN);

	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"H1"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J1"} }, Shot::Impact::HIT);

#if 0
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"A10"} }, Shot::Impact::NONE);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"D1"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"E1"} }, Shot::Impact::SUNKEN);
#endif
	console2.print();

	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"I1"} }, Shot::Impact::SUNKEN);
	console2.print();

#if 0
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J7"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J8"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J10"} }, Shot::Impact::HIT);
	console2.print();
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J9"} }, Shot::Impact::SUNKEN);
	console2.print();
#endif

	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"G10"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"H10"} }, Shot::Impact::HIT);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"J10"} }, Shot::Impact::HIT);
	console2.print();
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"I10"} }, Shot::Impact::SUNKEN);
	board2.getOpponentGrid().shotResult(Shot{ GridPosition{"F10"} }, Shot::Impact::NONE);
	console2.print();

	std::cout <<"Printing sunken ships\n";
	console2.printSunkenShips();

}
