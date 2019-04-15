#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Book.h"

Book::Book()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
	setCategory("Invalid");
	setAuthorName("Invalid");
}

Book::Book(string ID, string name, bool status, string category, string authorName)
{
	setID(ID);
	setName(name);
	setStatus(status);
	setCategory(category);
	setAuthorName(authorName);
}

void Book::setAuthorName(string authorName)
{
	this->authorName = authorName;
}

string Book::getAuthorName()
{
	return authorName;
}

bool Book::searchRecord(string param) const
{
	if (BaseText::searchRecord(param) == true)
	{
		return true;
	}
	
	else if (param == authorName)
	{
		return true;
	}

	else
	{
		return false;
	}

}

void Book::printRecord() const
{
	BaseText::printRecord();
	cout << "Author Name: " << authorName << endl;
}

void Book::writeToFile(string file, int i) const
{
	BaseText::writeToFile(file, i);

	string tempStatus;

	/*filebuf fb;
	fb.open(file, std::ios::app);
	std::ostream os(&fb);*/

	ofstream out;
	out.open(file, ios::app);

	out << authorName;

	out.close();
}