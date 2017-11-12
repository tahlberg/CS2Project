//============================================================================
// Name        : OrderProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Order.hpp"
using namespace std;

int main() {
	vector<Customer*> theCustomers;
	fstream custStream("CustomerFile.txt");
	if(custStream.fail()){
		cout << "Failed to open CustomerFile.txt" << endl;
	}
	else{
		while(!custStream.eof()){
			Customer *tempCustomer = new Customer;
			string cNum;
			string cName;
			string cMail;
			int y;
			int m;
			int d;
			custStream >> cNum;
			custStream >> cName;
			custStream >> cMail;
			custStream >> y;
			custStream >> m;
			custStream >> d;
			tempCustomer->setCustomerNumber(cNum);
			tempCustomer->setCustomerName(cName);
			tempCustomer->setEmail(cMail);
			Date cDate(m, d, y);
			tempCustomer->setDateJoined(cDate);
			theCustomers.push_back(tempCustomer);
		}
	}
	vector<Order*> theOrders;
	fstream orderStream("OrderItems.txt");
	if(orderStream.fail()){
		cout << "Failed to open OrderItem.txt" << endl;
	}
	while(!orderStream.eof()){
		Order *tempOrder = new Order;
		string oID;
		int y;
		int m;
		int d;
		string cID;
		orderStream >> oID;
		orderStream >> y;
		orderStream >> m;
		orderStream >> d;
		orderStream >> cID;
		tempOrder->setOrderNumber(oID);
		Date oDate(m, d, y);
		tempOrder->setOrderDate(oDate);
		for(unsigned int i = 0; i < theCustomers.size(); i++){
			if(theCustomers[i]->getCustomerNumber() == cID){
				tempOrder->setOrderCustomer(*theCustomers[i]);
				break;
			}
			cout << "Customer not found" << endl;
		}
		theOrders.push_back(tempOrder);
	}

	return 0;
}
