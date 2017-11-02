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
