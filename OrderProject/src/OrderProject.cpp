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

int main(int argc, const char* argv[]) {
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
	if(argc == 1){
		cout << "Order Report: " << endl;
		cout << "===========================================" << endl;
		for(unsigned int i = 0; i < theOrders.size(); i++){
			PrintOrder(theOrders[i]);
		}
		cout << "Orders printed! Program ending. Have a nice day." << endl;
	}
	else if(argc == 2){
		bool orderFound = false;
		for(unsigned int i = 0; i < theOrders.size(); i++){
			if(argv[1] == theOrders[i]->getOrderNumber()){
				orderFound = true;
				cout << "Order Report: " << endl;
				cout << "===========================================" << endl;
				PrintOrder(theOrders[i]);
			}
		}
		cout << "Order printed! Program ending. Have a nice day." << endl;
		if(orderFound == false){
			cout << "Failed to find order! Program ending. Have a nice day." << endl;
			return 0;
		}
	}
	else if(argc > 2){
		cout << "Too many parameters! Program ending. Have a nice day." << endl;
	}
	return 0;
}

void PrintOrder(Order *anOrder){
	bool foodHeader = false;
	bool mediaHeader = false;
	bool electronicHeader = false;
	cout << right << setw(12) << "Order ID" << right << setw(15) << "Customer ID" << right << setw(15) << "Order Date" << right << setw(18) << "Customer" << endl;
	cout << right << setw(12) << "--------" << right << setw(15) << "-----------" << right << setw(15) << "----------" << right << setw(18) << "--------" << endl;
	cout << right << setw(12) << anOrder->getOrderNumber() << right << setw(15) << anOrder->getOrderCustomer().getCustomerNumber() << right << setw(15) << anOrder->getOrderDate().getDateString() << right << setw(18) << anOrder->getOrderCustomer().getCustomerName() << endl;
	for(unsigned int i = 0; i < anOrder->getItemsInOrder().size(); i++){
		if(anOrder->getItemsInOrder()[i]->whoAmI() == "FoodItem"){
			if(foodHeader == false){
				foodHeader = true;
				cout << endl;
				cout << left << setw(24) << "Food Items Ordered:" << right << setw(12) << "Item Number" << right << setw(21) << "Item Description" << right << setw(12) << "Calories" << right << setw(9) << "Cost" << endl;
				cout << right << setw(36) << "------------" << right << setw(21) << "----------------"  << right << setw(12) <<  "--------" << right << setw(9) << "----" << endl;
			}
			FoodItem *tempFood = new FoodItem;
			tempFood = dynamic_cast<FoodItem*>(anOrder->getItemsInOrder()[i]);
			cout << right << setw(36) << tempFood->getItemNumber() << right << setw(21) << tempFood->getItemDescription() << right << setw(12) << tempFood->getCalories() << right << setw(9) << fixed << setprecision(2) << tempFood->getCustomerCost() << endl;
		}
		if(anOrder->getItemsInOrder()[i]->whoAmI() == "MediaItem"){
			if(mediaHeader == false){
				mediaHeader = true;
				cout << endl;
				cout << left << setw(24) << "Media Items Ordered:" << right << setw(12) << "Item Number" << right << setw(21) << "Item Description" << right << setw(12) << "ISBN" << right << setw(9) << "Cost" << endl;
				cout << right << setw(36) << "------------" << right << setw(21) << "----------------"  << right << setw(12) << "----" << right << setw(9) << "----" << endl;
			}
			MediaItem *tempMedia = new MediaItem;
			tempMedia = dynamic_cast<MediaItem*>(anOrder->getItemsInOrder()[i]);
			cout << right << setw(36) << tempMedia->getItemNumber() << right << setw(21) << tempMedia->getItemDescription() << right << setw(12) << tempMedia->getISBNNumber() << right << setw(9) << fixed << setprecision(2) << tempMedia->getCustomerCost() << endl;
		}
		if(anOrder->getItemsInOrder()[i]->whoAmI() == "ElectronicItem"){
			if(electronicHeader == false){
				electronicHeader = true;
				cout << endl;
				cout << left << setw(24) << "Electronic Items Ordered:" << right << setw(12) << "Item Number" << right << setw(21) << "Item Description" << right << setw(12) << "Warranty" << right << setw(9) << "Cost" << endl;
				cout << right << setw(36) << "------------" << right << setw(21) << "----------------"  << right << setw(12) << "--------" << right << setw(9) << "----" << endl;
			}
			ElectronicItem *tempElec = new ElectronicItem;
			tempElec = dynamic_cast<ElectronicItem*>(anOrder->getItemsInOrder()[i]);
			cout << right << setw(36) << tempElec->getItemNumber() << right << setw(21) << tempElec->getItemDescription() << right << setw(12) << tempElec->getWarrantyMonths() << right << setw(9) << fixed << setprecision(2) << tempElec->getCustomerCost() << endl;
		}
	}
	cout << "Order Total is: " << anOrder->getTotalOfOrder() << endl;
	cout << "===========================================" << endl;
}
