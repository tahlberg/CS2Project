/*
 * OrderItem.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "OrderItem.hpp"

OrderItem::OrderItem() {
	// TODO Auto-generated constructor stub

}

OrderItem::~OrderItem() {
	// TODO Auto-generated destructor stub
}

void OrderItem::setItemNumber(string str){
	this->itemNumber = str;
}
void OrderItem::setItemDescription(string str){
	this->itemDescription = str;
}
void OrderItem::setQuantity(int anInt){
	this->quantity = anInt;
}
void OrderItem::setCustomerCost(double dbl){
	this->customerCost = dbl;
}
void OrderItem::setVendorCost(double dbl){
	this->vendorCost = dbl;
}
void OrderItem::setTaxExempt(bool aBool){
	this->taxExempt = aBool;
}
string OrderItem::getItemNumber(void){
	return this->itemNumber;
}
string OrderItem::getItemDescription(void){
	return this->itemDescription;
}
int OrderItem::getQuantity(void){
	return this->quantity;
}
double OrderItem::getCustomerCost(void){
	return this->customerCost;
}
double OrderItem::getVendorCost(void){
	return this->vendorCost;
}
bool OrderItem::getTaxExempt(void){
	return this->taxExempt;
}
