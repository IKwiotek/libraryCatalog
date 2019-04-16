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
	Book(string ID, string name, bool status, string category, string authorName);

	void setAuthorName(string authorName);

	string getAuthorName() const;

	virtual bool searchRecord(string param) const;
	virtual void printRecord() const;
	virtual void writeToFile(string file, int i) const;
	virtual ~Book() {};

private:
	string authorName;
};


#endif Book_H
