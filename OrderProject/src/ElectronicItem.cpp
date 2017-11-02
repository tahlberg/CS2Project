/*
 * ElectronicItem.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "ElectronicItem.hpp"

ElectronicItem::ElectronicItem() {
	// TODO Auto-generated constructor stub

}

ElectronicItem::~ElectronicItem() {
	// TODO Auto-generated destructor stub
}

void ElectronicItem::setEType(Type aType){
	this->eType = aType;
}
void ElectronicItem::setWarrantyMonths(int anInt){
	this->warrantyMonths = anInt;
}
Type ElectronicItem::getEType(void){
	return this->eType;
}
int ElectronicItem::getWarrantyMonths(void){
	return this->warrantyMonths;
}
