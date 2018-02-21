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


