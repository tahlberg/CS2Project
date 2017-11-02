/*
 * Customer.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_
#include "Date.hpp"
#include <string>
using namespace std;

class Customer {
public:
	Customer();
	virtual ~Customer();
	void setCustomerNumber(string);
	void setCustomerName(string);
	void setEmail(string);
	void setDateJoined(Date);
	string getCustomerNumber(void);
	string getCustomerName(void);
	string getEmail(void);
	Date getDateJoined(void);
private:
	string customerNumber;
	string customerName;
	string email;
	Date dateJoined;
};

#endif /* CUSTOMER_HPP_ */
