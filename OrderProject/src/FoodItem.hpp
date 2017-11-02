/*
 * FoodItem.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef FOODITEM_HPP_
#define FOODITEM_HPP_

#include "OrderItem.hpp"
#include "Date.hpp"

class FoodItem: public OrderItem {
public:
	FoodItem();
	virtual ~FoodItem();
	void setExpirationDate(Date);
	void setCalories(int);
	void setFat(int);
	Date getExpirationDate(void);
	int getCalories(void);
	int getFat(void);
private:
	Date expirationDate;
	int calories;
	int fat;
};

#endif /* FOODITEM_HPP_ */
