#ifndef Base_Text_H
#define Base_Text_H
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"

using namespace std;

class BaseText
{
public:
	BaseText();
	BaseText(string ID, string name, string status);
	void setID(string ID);
	void setName(string name);
	void setStatus(string status);
	void setCategory(string category);
	string getID() const;
	string getName() const;
	string getStatus() const;
	string getCategory() const;

	bool searchRecord(string param) const;
	virtual void printRecord() const;

private:
	string ID;
	string name;

	//consider using an enum for this rather than bool or string
	string status;

	// also consider using an enum for this
	string category;
};

#endif // BaseText_H