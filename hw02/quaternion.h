/*
 * quaternion.h
 *
 *  Created on: Feb 21, 2018
 *      Author: Mutian Chen & Huseyin Altinisik
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_
#include <iostream>
#include <math.h>
using namespace std;

/*
 * The public and private declarations for the constructor and methods of the Quaternion class, including the
 * operator overloading for several comparison and arithmetic operators.
 */
class Quaternion{
public:
	Quaternion();
	Quaternion(double, double, double, double);
	Quaternion(double);
	Quaternion(const Quaternion&);

	bool operator==(const Quaternion&) const;
	bool operator!=(const Quaternion&) const;
	bool operator>(const Quaternion&) const;
	bool operator<(const Quaternion&) const;
	bool operator>=(const Quaternion&) const;
	bool operator<=(const Quaternion&) const;
	Quaternion& operator=(const Quaternion&);
	Quaternion& operator*=(const Quaternion &);
	Quaternion conjugate()const;
	Quaternion& operator/=(const Quaternion &);
	Quaternion& operator+=(const Quaternion &);
	Quaternion& operator-=(const Quaternion &);

	double norm()const;
	double& operator[](int);

	friend ostream& operator<<(ostream&,Quaternion&);
	friend istream& operator>> (istream&,Quaternion&);

private:
	double a;
	double b;
	double c;
	double d;
};

/*
 * Overloading the arithmetic operators: +,-,*,/
 * Parameters: Quaternion& - the reference to the quaternion objects to apply the arithmetic operations on
 * Return: Quaternion object
 */
const Quaternion operator+(const Quaternion&,const Quaternion&);
const Quaternion operator*(const Quaternion&,const Quaternion&);
const Quaternion operator-(const Quaternion&,const Quaternion&);
const Quaternion operator/(const Quaternion&,const Quaternion&);

#endif /* QUATERNION_H_ */
