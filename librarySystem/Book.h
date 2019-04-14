#ifndef Book_H
#define Book_H
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"
#include "BaseText.h"

using namespace std;

class Book : public BaseText
{
public:
	Book();
	Book(string ID, string name, string status, string authorName);
	void setAuthorName(string authorName);
	string getAuthorName();
	virtual void printRecord() const;

private:
	string authorName;
};


#endif // Book_H
