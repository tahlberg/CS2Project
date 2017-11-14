/*
 * ElectronicItem.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef ELECTRONICITEM_HPP_
#define ELECTRONICITEM_HPP_

#include "OrderItem.hpp"

class ElectronicItem: public OrderItem {
public:
	ElectronicItem();
	virtual ~ElectronicItem();
	void setEType(Type);
	void setWarrantyMonths(int);
	Type getEType(void);
	int getWarrantyMonths(void);
	string whoAmI();
private:
	Type eType;
	int warrantyMonths;
};

#endif /* ELECTRONICITEM_HPP_ */
