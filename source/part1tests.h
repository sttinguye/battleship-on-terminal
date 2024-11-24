/*
 * part1tests.h
 *
 *  Created on: Dec 9, 2022
 *      Author: profe
 */

#ifndef PART1TESTS_H_
#define PART1TESTS_H_

#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, string failedMessage);

/**
 * Part 1 tests
 */
void part1tests ();


#endif /* PART1TESTS_H_ */
