/*
 * part2tests.h
 *
 *  Created on: Dec 9, 2022
 *      Author: profe
 */

#ifndef PART2TESTS_H_
#define PART2TESTS_H_

#include "Board.h"
#include "ConsoleView.h"
#include <string>
#include <iostream>


/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTruePart2(bool condition, std::string failedMessage);

/**
 * Part 2 tests
 */
void part2tests();

/**
 * Old Part 2 tests -> only use for debugging purposes
 */
void part2testsOld();


#endif /* PART2TESTS_H_ */
