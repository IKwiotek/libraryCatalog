#include "stdafx.h"
#include "BaseText.h"

BaseText::BaseText()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
}

BaseText::BaseText(string ID, string name, string status)
{
	setID(ID);
	setName(name);
	setStatus(status);
}

string BaseText::getID() const
{
	return ID;
}

string BaseText::getName() const
{
	return name;
}

string BaseText::getStatus() const
{
	return status;
}

void BaseText::setID(string ID)
{
	this->ID = ID;
}

void BaseText::setName(string name)
{
	this->name = name;
}

void BaseText::setStatus(string status)
{
	this->status = status;
}
