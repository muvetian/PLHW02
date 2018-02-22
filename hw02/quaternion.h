/*
 * quaternion.h
 *
 *  Created on: Feb 21, 2018
 *      Author: mu
 */

#ifndef QUATERNION_H_
#define QUATERNION_H_
#include <iostream>
using namespace std;
class Quaternion{
public:
	Quaternion();
	Quaternion(double num1, double num2, double num3, double num4);
	Quaternion(double r);
	double getA() const;
	double getB() const;
	double getC() const;
	double getD() const;

	bool operator==(const Quaternion &other) const;
	bool operator!=(const Quaternion &other) const;
	bool operator>(const Quaternion &other) const;
	bool operator<(const Quaternion &other) const;
	bool operator>=(const Quaternion &other) const;
	bool operator<=(const Quaternion &other) const;
//	Quaternion& operator+=(const Quaternion &other);
//	Quaternion& operator-=(const Quaternion &other);
//	Quaternion& operator=(const Quaternion &other);
	Quaternion& operator*(const Quaternion &other);
	//TODO: Override the assignment operator
	//		Quaternion& operator=(const Quaternion& other) // copy assignment
	//		{
	//		    if (this != &other) { // self-assignment check expected
	//		        if (other.size != size) {         // storage cannot be reused
	//		            delete[] mArray;              // destroy storage in this
	//		            size = 0;
	//		            mArray = nullptr;             // preserve invariants in case next line throws
	//		            mArray = new double[other.size]; // create storage in this
	//		            size = other.size;
	//		        }
	//		        std::copy(other.mArray, other.mArray + other.size, mArray);
	//		    }
	//		    return *this;
	//		}
private:
	double a;
	double b;
	double c;
	double d;
};
ostream& operator<<(ostream& os,Quaternion& quat);
//istream& operator>> (istream& is,Quaternion& quat);
#endif /* QUATERNION_H_ */
