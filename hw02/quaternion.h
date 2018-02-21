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
	int a;
	int b;
	int c;
	int d;
	Quaternion();
	Quaternion(int num1, int num2, int num3, int num4);
	Quaternion(int r);
	ostream& operator<<(ostream& os){
		os << '(' << a << ',' << b << ',' << c << ',' << d << ')' ;
		return os;
	}
	istream& operator>> (istream& is)
	{
		is>> a >> b >> c >> d;
		return is;
	}
	bool operator==(const Quaternion &other) const;
	bool operator!=(const Quaternion &other) const;
	bool operator>(const Quaternion &other) const;
	bool operator<(const Quaternion &other) const;
	//TODO: Override the assignment operator
	//		Quaternion& operator=(const Quaternion& other) // copy assignment
	//		{
	//		    if (this != &other) { // self-assignment check expected
	//		        if (other.size != size) {         // storage cannot be reused
	//		            delete[] mArray;              // destroy storage in this
	//		            size = 0;
	//		            mArray = nullptr;             // preserve invariants in case next line throws
	//		            mArray = new int[other.size]; // create storage in this
	//		            size = other.size;
	//		        }
	//		        std::copy(other.mArray, other.mArray + other.size, mArray);
	//		    }
	//		    return *this;
	//		}

};



#endif /* QUATERNION_H_ */
