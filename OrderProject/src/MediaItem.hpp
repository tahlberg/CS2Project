/*
 * MediaItem.hpp
 *
 *  Created on: Oct 26, 2017
 *      Author: CounterbalanceLT
 */

#ifndef MEDIAITEM_HPP_
#define MEDIAITEM_HPP_

#include "OrderItem.hpp"
#include "Date.hpp"

class MediaItem: public OrderItem {
public:
	MediaItem();
	virtual ~MediaItem();
	void setAuthorName(string);
	void setPublicationDate(Date);
	void setISBNNumber(string);
	string getAuthorName(void);
	Date getPublicationDate(void);
	string getISBNNumber(void);
	string whoAmI();
	MediaItem(fstream&);
private:
	string authorName;
	Date publicationDate;
	string ISBNNumber;
};

#endif /* MEDIAITEM_HPP_ */
