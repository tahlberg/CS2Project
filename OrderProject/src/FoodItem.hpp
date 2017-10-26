/*
 * FoodItem.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef FOODITEM_HPP_
#define FOODITEM_HPP_

#include "OrderItem.hpp"

class FoodItem: public OrderItem {
public:
	FoodItem();
	virtual ~FoodItem();
};

#endif /* FOODITEM_HPP_ */
