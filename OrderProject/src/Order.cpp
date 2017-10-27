/*
 * Order.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "Order.hpp"

Order::Order() {
	// TODO Auto-generated constructor stub

}

Order::~Order() {
	// TODO Auto-generated destructor stub
}

void Order::setOrderNumber(string str){
	this->orderNumber = str;
}
void Order::setOrderDate(Date aDate){
	this->orderDate = aDate;
}
void Order::setItemsInOrder(vector<OrderItem*> iVector){
	this->itemsInOrder = iVector;
}
void Order::setOrderCustomer(Customer cust){
	this->orderCustomer = cust;
}
string Order::getOrderNumber(void){
	return this->orderNumber;
}
Date Order::getOrderDate(void){
	return this->orderDate;
}
vector<OrderItem*> Order::getItemsInOrder(void){
	return this->itemsInOrder;
}
Customer Order::getOrderCustomer(void){
	return this->orderCustomer;
}
