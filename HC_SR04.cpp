/*
 * HC_SR04.cpp
 *
 *  Created on: 30 Mar 2015
 *      Author: AyberkHalac
 */

#include "HC_SR04.hpp"

double HC_SR04::get_distance() {

	timeval begin;
	timeval end;

	// 0 reset(LOW)
	echo.set_value(0);
	usleep(500);

	// 1 set(HIGH)
	echo.set_value(1);

	usleep(5);
	// 0 reset(LOW)
	echo.set_value(0);

	// Read while input become HIGH.
	while (trigger.get_value() == 0) {
	}

	gettimeofday(&begin, 0); // Get first time.

	// Read while input become LOW.
	while (trigger.get_value() != 0) {
	}

	gettimeofday(&end, 0); // Get last time.

	double Elapsed = (end.tv_usec - begin.tv_usec); // Last time - First time = Elapsed.

	//The speed of sound is 340 m/s or 29 microseconds per centimeter. Taking half the total distance (there and back) Program can use the divisor 58.
	Elapsed /= 58;

	return Elapsed;
}

