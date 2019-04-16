#ifndef Base_Text_H
#define Base_Text_H
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"

using namespace std;

//enum categoryEnum
//{
//	Unknown = 0,
//	Book = 1,
//	Journal = 2,
//	Magazine = 3
//};

class BaseText
{
public:
	BaseText();
	BaseText(string ID, string name, bool status, string category);

	void setID(string ID);
	void setName(string name);
	void setStatus(bool status);
	void setCategory(string category);

	string getID() const;
	string getName() const;
	bool getStatus() const;
	string getCategory() const;

	virtual bool searchRecord(string param) const;
	virtual void printRecord() const;
	virtual void writeToFile(string file, int i) const;
	virtual ~BaseText() {};

private:
	string ID;
	string name;
	bool status;
	string category;
};

#endif BaseText_H