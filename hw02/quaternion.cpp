/*
 * quaternion.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: mu
 */
#include <iostream>
#include "quaternion.h"
Quaternion::Quaternion(){
	a = 0.0;
	b = 0.0;
	c = 0.0;
	d = 0.0;
}
Quaternion::Quaternion(double num1, double num2, double num3, double num4){
	a = num1;
	b = num2;
	c = num3;
	d = num4;
}
Quaternion::Quaternion(double r){
	a = r;
	b = 0.0;
	c = 0.0;
	d = 0.0;
}
Quaternion::Quaternion(const Quaternion& copy){
	a = copy.a;
	b = copy.b;
	c = copy.c;
	d = copy.d;

}


Quaternion& Quaternion::operator=(const Quaternion& other){
	if (this != &other){
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;
	}

	return *this;

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
Quaternion& Quaternion::operator-=(const Quaternion &other){
	a -= other.a;
	b -= other.b;
	c -= other.c;
	d -= other.d;

	return *this;
}

Quaternion& Quaternion::conjugate()const{
	double newA = a;
	double newB = -b;
	double newC = -c;
	double newD = -d;
	Quaternion q(newA, newB, newC, newD);
	return q;

}
Quaternion& Quaternion::operator/=(const Quaternion &other){
	if (other.a == 0 && other.b == 0 && other.c == 0 && other.d == 0){
		throw domain_error("Denominator cannot be a zeror quaternion!");
	}
	Quaternion r = other;
	double product = r.norm() * r.norm();
	Quaternion q = *this;
	q *= r.conjugate();
	a = q.a/product;
	b = q.b/product;
	c = q.c/product;
	d = q.d/product;
	return *this;

}
Quaternion& Quaternion::operator*=(const Quaternion &other){
	double newA = (this->a * other.a) - (this->b * other.b) - (this->c * other.c) - (this->d * other.d);
	double newB = (this->a * other.b) + (this->b * other.a) + (this->c * other.d) - (this->d * other.c);
	double newC = (this->a * other.c) - (this->b * other.d) + (this->c * other.a) + (this->d * other.b);
	double newD = (this->a * other.d) + (this->b * other.c) - (this->c * other.b) + (this->d * other.a);
	a = newA;
	b = newB;
	c = newC;
	d = newD;
	return *this;
}
Quaternion& Quaternion::operator+=(const Quaternion &other){

	a += other.a;
	b += other.b;
	c += other.c;
	d += other.d;

	return *this;
}

double Quaternion::norm() const{

	return sqrt(a*a + b*b + c*c + d*d);
}
double& Quaternion::operator[](int component){
	if(component == 0){
		return this->a;
	}
	else{
		if(component == 1){
			return this->b;
		}
		else{
			if(component == 2){
				return this->c;
			}
			else{
				if(component == 3){
					return this->d;
				}
				else{
					throw out_of_range ("ERROR: Index out of range.");
				}
			}
		}
	}
}
istream& operator>> (istream& is,Quaternion& quat){
	cin >> quat.a >> quat.b >> quat.c >> quat.d;
	return is;
}
ostream& operator<<(ostream& os,Quaternion& quat){
	os << '(' << quat.a << ',' << quat.b << ',' << quat.c << ',' << quat.d << ')' ;
	return os;
}

const Quaternion operator*(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer *= q;
	return answer;
}
const Quaternion operator+(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer += q;
	return answer;
}

const Quaternion operator-(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer -= q;
	return answer;
}
const Quaternion operator/(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer /= q;
	return answer;
}
