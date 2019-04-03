#include "stdafx.h"
#include "Book.h"

Book::Book()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
	setAuthorName("Invalid");
}

Book::Book(string ID, string name, string status, string authorName)
{
	setID(ID);
	setName(name);
	setStatus(status);
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
