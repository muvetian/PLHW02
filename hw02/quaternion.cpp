/*
 * quaternion.cpp
 *
 *  Created on: Feb 21, 2018
 *      Author: Mutian Chen & Huseyin Altinisik
 */
#include <iostream>
#include "quaternion.h"

/*
 * Constructor for a quaternion object, with four components: a,b,c,d.
 */
Quaternion::Quaternion(){
	a = 0.0;
	b = 0.0;
	c = 0.0;
	d = 0.0;
}

/*
 * The constructor method to create a quaternion object with the user-given component parameters.
 * Parameters: num1, num2, num3, num4 - the components of the quaternion to be created
 */
Quaternion::Quaternion(double num1, double num2, double num3, double num4){
	a = num1;
	b = num2;
	c = num3;
	d = num4;
}

/*
 *The constructor method to create a quaternion object with just the real part
 *Parameters: r - the double for the real component of quaternion
 */
Quaternion::Quaternion(double r){
	a = r;
	b = 0.0;
	c = 0.0;
	d = 0.0;
}

/*
 *The constructor method for creating a quaternion object with another quaternion object.
 *Parameters: copy - the quaternion that is being copied from
 */
Quaternion::Quaternion(const Quaternion& copy){
	a = copy.a;
	b = copy.b;
	c = copy.c;
	d = copy.d;

}

/*
 * Overloading the comparison operator =.
 * Parameter: other - the other quaternion for comparison
 * Return: the reference to the (this) quaternion object
 */
Quaternion& Quaternion::operator=(const Quaternion& other){
	if (this != &other){
		a = other.a;
		b = other.b;
		c = other.c;
		d = other.d;
	}

	return *this;

}

/*
 * Overloading the comparison operator ==.
 *Parameter: &other - the reference of the other quaternion object
 *Return: boolean - true if the same components of the quaternions are equal and false if not
 */
bool Quaternion::operator==(const Quaternion &other) const {
	if(this->a == other.a && this->b == other.b && this->c == other.c && this->d == other.d){
		return true;
	}
	return false;
}

/*
 * Overloading the != operator by the use of the == operator.
 * Parameter: &other - the reference of the other quaternion object
 * Return: true if the quaternions are equivalent and false if not
 */
bool Quaternion::operator!=(const Quaternion &other) const {
	return !(*this == other);
}

/*
 * Overloading the > operator by comparing the components of this and other quaternions
 * using the correct hierarchy of components
 * Parameter: &other - the reference to the other quaternion
 * Return: boolean - true if this quaternion is greater than other quaternion and false if not
 */
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
}

/*
 * Overloading the < operator by comparing the components of this and other
 * quaternions using the correct hierarchy of components
 * Parameter: &other - the reference to the other quaternion
 * Return: boolean - true if this quaternion is smaller than other quaternion and false if not
 */
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
}
/*
 * Overloading the <= operator by using the == and < operators.
 * Parameter: &other - the reference to the other quaternion
 * Return: boolean - true if this quaternion is smaller than or equal to other quaternion and false otherwise
 */
bool Quaternion::operator<=(const Quaternion &other) const {
	if(*this == other || *this < other){
		return true;
	}
	else{
		return false;
	}
}
/*
 * Overloading the >= operator by using the == and > operators.
 * Parameter: &other - the reference to the other quaternion
 * Return: boolean - true if this quaternion is greater than or equal to other quaternion and false if otherwise
 */
bool Quaternion::operator>=(const Quaternion &other) const {
	if(*this == other || *this > other){
		return true;
	}
	else{
		return false;
	}
}

/*
 * Overloading the -= operator by subtracting components of other quaternion from the same components of this quaternion
 * Parameter: &other - the reference to the other quaternion
 * Return: Quaternion& - the reference to this quaternion
 */
Quaternion& Quaternion::operator-=(const Quaternion &other){
	a -= other.a;
	b -= other.b;
	c -= other.c;
	d -= other.d;

	return *this;
}

/*
 * Calculating the conjugate of a quaternion
 * Return: Quaternion - the conjugate of the given quaternion
 */
Quaternion Quaternion::conjugate()const{
	double newA = a;
	double newB = -b;
	double newC = -c;
	double newD = -d;
	Quaternion q(newA, newB, newC, newD);
	return q;

}

/*
 * Overloading the /= comparison operator
 * Parameter: &other - the reference to the other quaternion
 * Return: Quaternion& - the reference to this quaternion
 */
Quaternion& Quaternion::operator/=(const Quaternion &other){
	if (other.a == 0 && other.b == 0 && other.c == 0 && other.d == 0){
		throw domain_error("Denominator cannot be a zero quaternion!");
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

/*
 * Overloading the *= comparison operator
 * Parameter: &other - the reference to the other quaternion
 * Return: Quaternion& - the reference to this quaternion
 */
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

/*
 * Overloading the += comparison operator
 * Parameter: &other - the reference to the other quaternion
 * Return: Quaternion& - the reference to this quaternion
 */
Quaternion& Quaternion::operator+=(const Quaternion &other){

	a += other.a;
	b += other.b;
	c += other.c;
	d += other.d;

	return *this;
}

/*
 * Calculating the norm of this quaternion
 * Return: double - the norm value of the quaternion
 */
double Quaternion::norm() const{

	return sqrt(a*a + b*b + c*c + d*d);
}

/*
 * Overloading the bracket, []
 * Parameter: component - the index of the quaternion component to be accessed
 * Return double& - the reference to the double, the queried component of the quaternion object
 */
double& Quaternion::operator[](int component){
	switch (component) {
	case 0: return this->a;
	case 1: return this->b;
	case 2: return this->c;
	case 3: return this->d;
	default: throw out_of_range ("ERROR: Index out of range.");
	}
}

/*
 * Overloading the >> operator to change the four components of the quaternion based on the input
 * Parameter: is, quat - the quatnion that being altered
 * Return: istream& - the input stream that we are getting the information about the components from
 */
istream& operator>> (istream& is,Quaternion& quat){
	cin >> quat.a >> quat.b >> quat.c >> quat.d;
	return is;
}

/*
 * Overloading the << operator to output the four compoents of the quaternion
 * Parameter: os, quat - the quaternion of which the content we want to output
 * Return: ostream& - the output stream that we are outputing the information to
 */
ostream& operator<<(ostream& os,Quaternion& quat){
	os << '(' << quat.a << ',' << quat.b << ',' << quat.c << ',' << quat.d << ')' ;
	return os;
}

/*
 * Overloading the * arithmetic operator
 * Parameter: p, q - the references to the quaternion objects to be multiplied, p and q
 * Return: Quaternion - quaternion object
 */
const Quaternion operator*(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer *= q;
	return answer;
}

/*
 * Overloading the + arithmetic operator
 * Parameter: p, q - the references to the quaternion objects to be added, p and q
 * Return: Quaternion - quaternion object
 */
const Quaternion operator+(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer += q;
	return answer;
}

/*
 * Overloading the - arithmetic operator
 * Parameter: p, q - the references to the quaternion objects, p and q
 * Return: Quaternion - quaternion object
 */
const Quaternion operator-(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer -= q;
	return answer;
}

/*
 * Overloading the / arithmetic operator
 * Parameter: p, q - the references to the numerator and denominator quaternion objects, p and q
 * Return: Quaternion - quaternion object
 */
const Quaternion operator/(const Quaternion& p,const Quaternion& q){
	Quaternion answer = p;
	answer /= q;
	return answer;
}
