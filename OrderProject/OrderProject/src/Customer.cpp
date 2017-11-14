/*
 * Customer.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "Customer.hpp"

Customer::Customer() {
	// TODO Auto-generated constructor stub

}

Customer::~Customer() {
	// TODO Auto-generated destructor stub
}

void Customer::setCustomerNumber(string str){
	this->customerNumber = str;
}
void Customer::setCustomerName(string str){
	this->customerName = str;
}
void Customer::setEmail(string str){
	this->email = str;
}
void Customer::setDateJoined(Date aDate){
	this->dateJoined = aDate;
}
string Customer::getCustomerNumber(void){
	return this->customerNumber;
}
string Customer::getCustomerName(void){
	return this->customerName;
}
string Customer::getEmail(void){
	return this->email;
}
Date Customer::getDateJoined(void){
	return this->dateJoined;
}
