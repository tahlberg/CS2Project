/*
 * Order.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "Order.hpp"
#include <iostream>
#include <fstream>
#include "FoodItem.hpp"
#include "MediaItem.hpp"
#include "ElectronicItem.hpp"

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
void Order::readFoodItems(){
	fstream foodStream("FoodItems.txt");
	if(foodStream.fail()){
		return;
	}
	else{
		while(!foodStream.eof()){
			FoodItem *fItem = new FoodItem;
			string oNum;
			string iNum;
			string iName;
			int qItem;
			double cCost;
			double vCost;
			char tExempt;
			int y;
			int m;
			int d;
			int cal;
			int iFat;

			foodStream >> oNum;
			foodStream >> iNum;
			foodStream >> iName;
			foodStream >> qItem;
			foodStream >> cCost;
			foodStream >>vCost;
			foodStream >> tExempt;
			foodStream >> y;
			foodStream >> m;
			foodStream >> d;
			foodStream >> cal;
			foodStream >> iFat;

			fItem->setItemNumber(iNum);
			fItem->setItemDescription(iName);
			fItem->setQuantity(qItem);
			fItem->setCustomerCost(cCost);
			fItem->setVendorCost(vCost);
			if(tExempt == 'T'){
				fItem->setTaxExempt(true);
			}else{
				fItem->setTaxExempt(false);
			}
			Date expDate(m, d, y);
			fItem->setExpirationDate(expDate);
			fItem->setCalories(cal);
			fItem->setFat(iFat);
			this->itemsInOrder.push_back(fItem);
			delete fItem;
		}
		foodStream.close();
	}
}
void Order::readMediaItems(){
	fstream mediaStream("MediaItems.txt");
	if(mediaStream.fail()){
		return;
	}
	else{
		while(!mediaStream.eof()){
			MediaItem *mItem = new MediaItem;
			string oNum;
			string iNum;
			string iName;
			int qItem;
			double cCost;
			double vCost;
			char tExempt;
			int y;
			int m;
			int d;
			string aName;
			string ISBN;

			mediaStream >> oNum;
			mediaStream >> iNum;
			mediaStream >> iName;
			mediaStream >> qItem;
			mediaStream >> cCost;
			mediaStream >> vCost;
			mediaStream >> tExempt;
			mediaStream >> y;
			mediaStream >> m;
			mediaStream >> d;
			mediaStream >> aName;
			mediaStream >> ISBN;

			mItem->setItemNumber(iNum);
			mItem->setItemDescription(iName);
			mItem->setQuantity(qItem);
			mItem->setCustomerCost(cCost);
			mItem->setVendorCost(vCost);
			if(tExempt == 'T'){
				mItem->setTaxExempt(true);
			}else{
				mItem->setTaxExempt(false);
			}
			Date pubDate(m, d, y);
			mItem->setPublicationDate(pubDate);
			mItem->setAuthorName(aName);
			mItem->setISBNNumber(ISBN);
			this->itemsInOrder.push_back(mItem);
			delete mItem;
		}
		mediaStream.close();
	}
}
void Order::readElectronicItems(){
	fstream electronicStream("ElectronicItems.txt");
	if(electronicStream.fail()){
		return;
	}
	else{
		while(!electronicStream.eof()){
			ElectronicItem *eItem = new ElectronicItem;
			string oNum;
			string iNum;
			string iName;
			int qItem;
			double cCost;
			double vCost;
			char tExempt;
			Type elecType;
			string wMonth;

			electronicStream >> oNum;
			electronicStream >> iNum;
			electronicStream >> iName;
			electronicStream >> qItem;
			electronicStream >> cCost;
			electronicStream >> vCost;
			electronicStream >> tExempt;
			electronicStream >> elecType;
			electronicStream >> wMonth;

			eItem->setItemNumber(iNum);
			eItem->setItemDescription(iName);
			eItem->setQuantity(qItem);
			eItem->setCustomerCost(cCost);
			eItem->setVendorCost(vCost);
			if(tExempt == 'T'){
				eItem->setTaxExempt(true);
			}else{
				eItem->setTaxExempt(false);
			}
			eItem->setEType(elecType);
			eItem->setWarrantyMonths(wMonth);
			this->itemsInOrder.push_back(eItem);
			delete eItem;

			this->itemsInOrder.push_back(eItem);
		}
		electronicStream.close();
	}
}
double Order::getTotalOfOrder(){
	return 0.0;
}
