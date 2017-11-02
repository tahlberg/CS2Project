/*
 * OrderItem.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef ORDERITEM_HPP_
#define ORDERITEM_HPP_
#include <string>
using namespace std;

class OrderItem {
public:
	OrderItem();
	virtual ~OrderItem();
	void setItemNumber(string);
	void setItemDescription(string);
	void setQuantity(int);
	void setCustomerCost(double);
	void setVendorCost(double);
	void setTaxExempt(bool);
	string getItemNumber(void);
	string getItemDescription(void);
	int getQuantity(void);
	double getCustomerCost(void);
	double getVendorCost(void);
	bool getTaxExempt(void);
private:
	string itemNumber;
	string itemDescription;
	int quantity;
	double customerCost;
	double vendorCost;
	bool taxExempt;
};

#endif /* ORDERITEM_HPP_ */
