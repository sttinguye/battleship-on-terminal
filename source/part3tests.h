/*
 * part3tests.h
 *
 *  Created on: Dec 9, 2022
 *      Author: profe
 */

#ifndef PART3TESTS_H_
#define PART3TESTS_H_

#include "Board.h"
#include "ConsoleView.h"
#include <string>
#include <iostream>

/**
 * Outputs if Shot is miss, hit, sunken.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void whatShotIsThat(Shot::Impact shotType, std::string message);

/**
 * Part 3 tests
 */
void part3tests();

/**
 * Old Part 3 tests -> only use for debugging purposes
 */
void part3testsOld();

#endif /* PART3TESTS_H_ */
