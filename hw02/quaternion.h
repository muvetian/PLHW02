/*
 * quaternion.h
 *
 *  Created on: Feb 21, 2018
 *      Author: mu
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_
#include <iostream>
#include <math.h>
using namespace std;
class Quaternion{
public:
	Quaternion();
	Quaternion(double num1, double num2, double num3, double num4);
	Quaternion(double r);
	Quaternion(const Quaternion&);



	bool operator==(const Quaternion &other) const;
	bool operator!=(const Quaternion &other) const;
	bool operator>(const Quaternion &other) const;
	bool operator<(const Quaternion &other) const;
	bool operator>=(const Quaternion &other) const;
	bool operator<=(const Quaternion &other) const;
	Quaternion& operator=(const Quaternion&);
	Quaternion& operator*=(const Quaternion &);
	Quaternion conjugate()const;
	Quaternion& operator/=(const Quaternion &);
	Quaternion& operator+=(const Quaternion &other);
	Quaternion& operator-=(const Quaternion &other);

	double norm()const;
	double& operator[](int component);

	friend ostream& operator<<(ostream& os,Quaternion& quat);
	friend istream& operator>> (istream& is,Quaternion& quat);

private:
	double a;
	double b;
	double c;
	double d;
};
const Quaternion operator+(const Quaternion&,const Quaternion&);
const Quaternion operator*(const Quaternion&,const Quaternion&);
const Quaternion operator-(const Quaternion&,const Quaternion&);
const Quaternion operator/(const Quaternion&,const Quaternion&);

#endif /* QUATERNION_H_ */
