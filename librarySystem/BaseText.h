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
	string getID() const;
	string getName() const;
	string getStatus() const;

private:
	string ID;
	string name;
	string status;
};

#endif // BaseText_H