/*
 * quaternion.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: mu
 */

#include "quaternion.h"
Quaternion::Quaternion(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}
Quaternion::Quaternion(int num1, int num2, int num3, int num4){
	a = num1;
	b = num2;
	c = num3;
	d = num4;
}
Quaternion::Quaternion(int r){
	a = r;
	b = 0;
	c = 0;
	d = 0;
}

bool Quaternion::operator==(const Quaternion &other) const {
	if(this->a == other.a && this->b == other.b && this->c == other.c && this->d == other.d){
		return true;
	}
	return false;
	// Compare the values, and return a bool result.
}
bool Quaternion::operator!=(const Quaternion &other) const {
	return !(*this == other);
	// Compare the values, and return a bool result.
}
bool Quaternion::operator>(const Quaternion &other) const {
	int thisSum = this->a * 1000 + this->b * 100 + this->c * 10 + this->d;
	int otherSum = other.a * 1000 + other.b * 100 + other.c * 10 + other.d;
	if (thisSum > otherSum){
		return true;
	}
	else{
		return false;
	}

	// Compare the values, and return a bool result.
}
bool Quaternion::operator<(const Quaternion &other) const {
	if(*this != other){
		if(*this > other){
			return false;
		}
		else{
			return true;
		}
	}
	return false;
	// Compare the values, and return a bool result.
}
