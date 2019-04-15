#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "BaseText.h"

BaseText::BaseText()
{
	setID("Invalid");
	setName("Invalid");
	setStatus(false);
	setCategory("Invalid");
}

BaseText::BaseText(string ID, string name, bool status, string category)
{
	setID(ID);
	setName(name);
	setStatus(status);
	setCategory(category);
}

string BaseText::getID() const
{
	return ID;
}

string BaseText::getName() const
{
	return name;
}

bool BaseText::getStatus() const
{
	return status;
}

string BaseText::getCategory() const
{
	return category;
}

void BaseText::setID(string ID)
{
	this->ID = ID;
}

void BaseText::setName(string name)
{
	this->name = name;
}

void BaseText::setStatus(bool status)
{
	this->status = status;
}

void BaseText::setCategory(string category)
{
	this->category = category;
}

bool BaseText::searchRecord(string param) const
{
	return (param == getName() || param == getCategory() || param == getID());
}

void BaseText::printRecord() const
{
	cout << "ID: " << ID << endl;
	cout << "Name: " << name << endl;
	cout << "Category: " << category << endl;

	if (status == 1)
	{
		cout << "Status: Available" << endl;
	}
	
	else
	{
		cout << "Status: Unavailable" << endl;
	}
}

void BaseText::writeToFile(string file, int i) const
{
	string tempStatus;

	ofstream out;
	out.open(file, ios::app);

	if (status == 1)
	{
		tempStatus = "True";
	}

	else
	{
		tempStatus = "False";
	}

	if (i == 0)
	{
		out << ID << "\n" << name << "\n" << tempStatus << "\n" << category << "\n";
	}

	else
	{

		out << "\n" << ID << "\n" << name << "\n" << tempStatus << "\n" << category << "\n";
	}

	out.close();
}



//void BaseText::setCategory(categoryEnum category)
//{
//	this->category = category;
//}

//categoryEnum BaseText::getCategory() const
//{
//	return category;
//}
