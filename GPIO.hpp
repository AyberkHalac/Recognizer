/*
 * GPIO.hpp
 *
 *  Created on: 30 Mar 2015
 *      Author: AyberkHalac
 */

#ifndef GPIO_HPP_
#define GPIO_HPP_

#include <fstream>
#include <iostream>
#include <string>

class GPIO {

private:
	std::string GPIO_DIR, pin, direction;
	std::ofstream os; //OFSTREAM
	std::ifstream is; //IFSTREAM

public:

	GPIO(std::string GPIO_Pin, std::string dir) :
			pin(GPIO_Pin), direction(dir) {
		setup();
	}

	// Export gpio with given parameters via constructor
	void setup();

	// Set value of corresponding gpio
	void set_value(int state);

	// Get value from corresponding gpio
	int get_value();

	// Get direction of corresponding gpio
	std::string get_direction();

	// Unexport gpio
	void remove();

};

#endif /* GPIO_HPP_ */
