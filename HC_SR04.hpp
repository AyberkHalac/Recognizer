/*
 * HC_SR04.hpp
 *
 *  Created on: 30 Mar 2015
 *      Author: AyberkHalac
 */

#ifndef HC_SR04_HPP_
#define HC_SR04_HPP_

#include "GPIO.cpp"
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

class HC_SR04 {
private:

	GPIO trigger, echo;

public:

	//Setup GPIO.
	HC_SR04(std::string trigger, std::string echo) :
			trigger(trigger, "in"), echo(echo, "out") {

	}

	double get_distance();

};

#endif /* HC_SR04_HPP_ */
