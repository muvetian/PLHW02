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
const Quaternion operator+(const Quaternion&,const Quaternion&);
const Quaternion operator*(const Quaternion&,const Quaternion&);
const Quaternion operator-(const Quaternion&,const Quaternion&);
const Quaternion operator/(const Quaternion&,const Quaternion&);

#endif /* QUATERNION_H_ */
