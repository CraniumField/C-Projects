#include "hit.h"

// Class Grid is defined here
Hit::Hit(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

// Getters and Setters for Node are defined here
int Hit::get_x() {

	return x;

}
void Hit::set_x(int new_x) {

	x = new_x;

}

int Hit::get_y() {

	return y;

}
void Hit::set_y(int new_y) {

	y = new_y;

}