/*
 * Order.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef ORDER_HPP_
#define ORDER_HPP_
#include "OrderItem.hpp"
#include "Customer.hpp"
#include "FoodItem.hpp"
#include "MediaItem.hpp"
#include "ElectronicItem.hpp"
#include <vector>

class Order {
public:
	Order();
	virtual ~Order();
	void setOrderNumber(string);
	void setOrderDate(Date);
	void setItemsInOrder(const vector<OrderItem*>);
	void setOrderCustomer(Customer*);
	string getOrderNumber(void);
	Date getOrderDate(void);
	vector<OrderItem*> getItemsInOrder(void);
	Customer* getOrderCustomer(void);
	void readFoodItems();
	void readMediaItems();
	void readElectronicItems();
	double getTotalOfOrder();
	Order(Customer*, string);
private:
	string orderNumber;
	Date orderDate;
	vector<OrderItem*> itemsInOrder;
	Customer *orderCustomer;
};

#endif /* ORDER_HPP_ */
