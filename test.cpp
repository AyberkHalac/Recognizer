#include "HC_SR04.hpp"

#include <stdio.h>
int main() {

	HC_SR04 object("18", "17");
	std::cout << object.get_distance();
	return 0;
}
