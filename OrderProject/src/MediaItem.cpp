/*
 * MediaItem.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#include "MediaItem.hpp"

MediaItem::MediaItem() {
	// TODO Auto-generated constructor stub

}

MediaItem::~MediaItem() {
	// TODO Auto-generated destructor stub
}

void MediaItem::setAuthorName(string str){
	this->authorName = str;
}
void MediaItem::setPublicationDate(Date aDate){
	this->publicationDate = aDate;
}
void MediaItem::setISBNNumber(string str){
	this->ISBNNumber = str;
}
string MediaItem::getAuthorName(void){
	return this->authorName;
}
Date MediaItem::getPublicationDate(void){
	return this->publicationDate;
}
string MediaItem::getISBNNumber(void){
	return this->ISBNNumber;
}
string MediaItem::whoAmI(){
	return "MediaItem";
}

MediaItem::MediaItem(fstream& fin){
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

	fin >> oNum;
	fin >> iNum;
	fin >> iName;
	fin >> qItem;
	fin >> cCost;
	fin >> vCost;
	fin >> tExempt;
	fin >> y;
	fin >> m;
	fin >> d;
	fin >> aName;
	fin >> ISBN;

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
	Date pubDate(m, d, y);
	this->setPublicationDate(pubDate);
	this->setAuthorName(aName);
	this->setISBNNumber(ISBN);

}
