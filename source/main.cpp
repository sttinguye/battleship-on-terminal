// Standard (system) header files
#include <iostream>
#include <cstdlib>

// Add your project's header files here
#include "part1tests.h"
#include "part2tests.h"
#include "part3tests.h"


int main()
{
	std::cout <<"##### Part 1 Tests #####\n";
	part1tests();
	std::cout <<"___Part 1 Tests Done!___\n\n";

	std::cout <<"#####Part 2 Tests #####\n";
	part2tests();
	std::cout <<"___Part 2 Tests Done!___\n\n";

	std::cout <<"##### Part 3 Tests #####\n";
	part3tests();
	std::cout <<"___Part 3 Tests Done!___\n\n";

	return 0;
}
