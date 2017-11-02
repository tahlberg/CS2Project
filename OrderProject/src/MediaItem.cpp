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
