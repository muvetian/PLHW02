/*
 * quaternion.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: mu
 */
#include <iostream>
#include "quaternion.h"
Quaternion::Quaternion(){
	a = 0;
	b = 0;
	c = 0;
	d = 0;
}
Quaternion::Quaternion(double num1, double num2, double num3, double num4){
	a = num1;
	b = num2;
	c = num3;
	d = num4;
}
Quaternion::Quaternion(double r){
	a = r;
	b = 0;
	c = 0;
	d = 0;
}

double Quaternion::getA() const{
	return a;
};
double Quaternion::getB() const{
	return b;
}
double Quaternion::getC() const{
	return c;
}
double Quaternion::getD() const{
	return d;
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
	if(this->a > other.a){
		return true;
	}
	else{
		if(this->b > other.b){
			return true;
		}
		else{
			if(this->c >  other.c){
				return true;
			}
			else{
				if(this->d > other.d){
					return true;
				}
				return false;
			}
		}
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
bool Quaternion::operator<=(const Quaternion &other) const {
	if(*this == other && *this < other){
		return true;
	}
	else{
		return false;
	}
	// Compare the values, and return a bool result.
}
bool Quaternion::operator>=(const Quaternion &other) const {
	if(*this == other && *this > other){
		return true;
	}
	else{
		return false;
	}
	// Compare the values, and return a bool result.
}
Quaternion& Quaternion::operator+(const Quaternion &other){
	Quaternion q(this->a + other.a, this->b + other.b, this->c + other.c, this->d + other.d);
	return q;
}
Quaternion& Quaternion::operator-(const Quaternion &other){
	Quaternion q(this->a - other.a, this->b - other.b, this->c - other.c, this->d - other.d);
	return q;
}
Quaternion& Quaternion::operator*(const Quaternion &other){
	double newA = this->a * other.a - this->b * other.b - this->c * other.c - this->d * other.d;
	double newB = this->a * other.b + this->b * other.a + this->c * other.d - this->d * other.c;
	double newC = this->a * other.c - this->b * other.d + this->c * other.a + this->d * other.b;
	double newD = this->a * other.d + this->b * other.c - this->c * other.b + this->d * other.a;
	Quaternion q(newA,newB,newC,newD);
	return q;
}
Quaternion& Quaternion::operator+=(const Quaternion &other){
	*this = *this + other;
	return *this;
}
Quaternion& Quaternion::operator*=(const Quaternion &other){
	 *this = *this * other;
	 return *this;
}
//Quaternion& Quaternion::operator-=(const Quaternion &other){
//	return *this;
//}
//Quaternion& Quaternion::operator=(const Quaternion &other){
//	return *this;
//}

//should this be a non-class method or class method
// const function

//istream& operator>> (istream& is,Quaternion& quat){
//	return is;
//}
ostream& operator<<(ostream& os,Quaternion& quat){
	os << '(' << quat.getA() << ',' << quat.getB() << ',' << quat.getC() << ',' << quat.getD() << ')' ;
	return os;
}
