//============================================================================
// Name        : OrderProject.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include "Order.hpp"
using namespace std;

void PrintOrder(Order *anOrder);

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
	fstream orderStream("OrderFile.txt");
	if(orderStream.fail()){
		cout << "Failed to open OrderFile.txt" << endl;
	}
	while(!orderStream.eof()){
		bool cFound = false;
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
		Customer *tempCust = new Customer;
		for(unsigned int i = 0; i < theCustomers.size(); i++){
			if(theCustomers[i]->getCustomerNumber() == cID){
				cFound = true;
				tempCust = theCustomers[i];
				break;
			}
		}
		if(cFound == false){
			tempCust = nullptr;
		}
		Order *tempOrder = new Order(tempCust, oID);
		Date oDate(m, d, y);
		tempOrder->setOrderDate(oDate);
		theOrders.push_back(tempOrder);
	}
	PrintOrder(theOrders[0]);
	return 0;
}

void PrintOrder(Order *anOrder){
	bool foodHeader = false;
	//bool mediaHeader = false;
	//bool electronicHeader = false;
	cout << "Order Report: " << endl;
	cout << "===========================================" << endl;
	cout << right << setw(12) << "Order ID" << right << setw(15) << "Customer ID" << right << setw(12) << "Order Date" << right << setw(18) << "Customer" << right << setw(24) << "Customer Email" << right << setw(21) << "Customer Join Date" << endl;
	cout << right << setw(12) << "--------" << right << setw(15) << "-----------" << right << setw(12) << "----------" << right << setw(18) << "--------" << right << setw(24) << "--------------" << right << setw(21) << "------------------" << endl;
	cout << right << setw(12) << anOrder->getOrderNumber() << right << setw(15) << anOrder->getOrderCustomer().getCustomerNumber() << right << setw(12) << anOrder->getOrderDate().getDateString() << right << setw(18) << anOrder->getOrderCustomer().getCustomerName() << right << setw(24) << anOrder->getOrderCustomer().getEmail() << right << setw(21) << anOrder->getOrderCustomer().getDateJoined().getDateString() << endl;
	for(unsigned int i = 0; i < anOrder->getItemsInOrder().size(); i++){
		if(anOrder->getItemsInOrder()[i]->whoAmI() == "FoodItem"){
			if(foodHeader == false){
				foodHeader = true;
				cout << endl;
				cout << left << setw(24) << "Food Items Ordered:" << right << setw(12) << "Item Number" << right << setw(21) << "Item Description" << right << setw(12) << "Quantity" << right << setw(18) << "Expiration Date" << right << setw(12) << "Calories" << right << setw(9) << "Fat" << right << setw(9) << "Cost" << endl;
				cout << right << setw(36) << "------------" << right << setw(21) << "----------------" << right << setw(12) << "--------" << right << setw(18) << "---------------" << right << setw(12) << "--------" << right << setw(9) << "---" << right << setw(9) << "----" << endl;
			}
			FoodItem *tempFood = new FoodItem;
			tempFood = dynamic_cast<FoodItem*>(anOrder->getItemsInOrder()[i]);
			cout << right << setw(36) << tempFood->getItemNumber() << right << setw(21) << tempFood->getItemDescription() << right << setw(12) << tempFood->getQuantity() << right << setw(18) << tempFood->getExpirationDate().getDateString() << right << setw(12) << tempFood->getCalories() << right << setw(9) << tempFood->getFat() << right << setw(9) << fixed << setprecision(2) << tempFood->getCustomerCost() << endl;
		}
	}
}
