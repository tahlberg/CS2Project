/*
 * Date.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef DATE_HPP_
#define DATE_HPP_
#include <string>
using namespace std;


class Date {
public:
	Date();
	virtual ~Date();
	int month;
	int day;
	int year;
	string getDateString(void);
};

#endif /* DATE_HPP_ */
