/*
 * FoodItem.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "FoodItem.hpp"

FoodItem::FoodItem() {
	// TODO Auto-generated constructor stub

}

FoodItem::~FoodItem() {
	// TODO Auto-generated destructor stub
}

void FoodItem::setExpirationDate(Date aDate){
	this->expirationDate = aDate;
}
void FoodItem::setCalories(int anInt){
	this->calories = anInt;
}
void FoodItem::setFat(int anInt){
	this->fat = anInt;
}
Date FoodItem::getExpirationDate(void){
	return this->expirationDate;
}
int FoodItem::getCalories(void){
	return this->calories;
}
int FoodItem::getFat(void){
	return this->fat;
}
string FoodItem::whoAmI(){
	return "FoodItem";
}

FoodItem::FoodItem(fstream& fin){
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

	fin >> oNum;
	fin >> iNum;
	fin >> iName;
	fin >> qItem;
	fin >> cCost;
	fin >>vCost;
	fin >> tExempt;
	fin >> y;
	fin >> m;
	fin >> d;
	fin >> cal;
	fin >> iFat;

	this->setItemNumber(iNum);
	this->setItemDescription(iName);
	this->setQuantity(qItem);
	this->setCustomerCost(cCost);
	this->setVendorCost(vCost);
	if(tExempt == 'T'){
		this->setTaxExempt(true);
	}else{
		this->setTaxExempt(false);
	}
	Date expDate(m, d, y);
	this->setExpirationDate(expDate);
	this->setCalories(cal);
	this->setFat(iFat);
}
