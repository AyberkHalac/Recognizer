/*
 * GPIO.cpp
 *
 *  Created on: 30 Mar 2015
 *      Author: AyberkHalac
 */

#include "GPIO.hpp"

inline void GPIO::setup() {

	GPIO_DIR = "/sys/class/gpio/";

	// Open a file for writing.
	os.open((GPIO_DIR + "export").c_str());
	// Write pin number to file
	os << pin;
	// Close file stream
	os.close();

	// Set pin direction (in/out)
	GPIO_DIR += "gpio" + pin + "/";
	os.open((GPIO_DIR + "direction").c_str());
	if (direction.compare("out") == 0 || direction.compare("in") == 0) {
		os << direction;
	} else {
		std::cout << "Wrong direction";

	}

	os.close();
}

inline void GPIO::set_value(int state) {
	//Set GPIO pin Value.
	GPIO_DIR = "/sys/class/gpio/gpio" + pin + "/value";

	os.open((GPIO_DIR).c_str());
	os << state;
	os.close();
}

inline int GPIO::get_value() {
	//Get GPIO Pin Value.
	char value;
	GPIO_DIR = "/sys/class/gpio/gpio" + pin + "/value";

	is.open((GPIO_DIR).c_str());
	is >> value;
	is.close();

	int num = value;
	return num - 48;
}

inline std::string GPIO::get_direction() {
	//Get direction.
	std::string direction;
	GPIO_DIR = "/sys/class/gpio/gpio" + pin + "/direction";

	is.open((GPIO_DIR).c_str());
	is >> direction;
	is.close();
	return direction;
}

inline void GPIO::remove() {
	//Unexport GPIO Pin.
	GPIO_DIR = "/sys/class/gpio/unexport";

	os.open((GPIO_DIR).c_str());
	os << pin;
	os.close();
}
