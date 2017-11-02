/*
 * Date.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "Date.hpp"


Date::Date() {
	// TODO Auto-generated constructor stub
	this->day = 01;
	this->month = 01;
	this->year = 1970;
}

Date::~Date() {
	// TODO Auto-generated destructor stub
}
string Date::getDateString(void){
	string str;
	str += to_string(month);
//	str += "/";
//	str += to_string(day);
//	str += "/";
//	str += to_string(year);
	return str;
}

