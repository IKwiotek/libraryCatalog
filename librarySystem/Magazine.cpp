#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Magazine.h"

Magazine::Magazine()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
	setCategory("Invalid");
	setIssueNumber("Invalid");
}

Magazine::Magazine(string ID, string name, bool status, string category, string issueNumber)
{
	setID(ID);
	setName(name);
	setStatus(status);
	setCategory(category);
	setIssueNumber(issueNumber);
}

void Magazine::setIssueNumber(string issueNumber)
{
	this->issueNumber = issueNumber;
}

string Magazine::getIssueNumber()
{
	return issueNumber;
}

void Magazine::printRecord() const
{
	BaseText::printRecord();
	cout << "Issue Number: " << issueNumber << endl;
}

void Magazine::writeToFile(string file, int i) const
{
	BaseText::writeToFile(file, i);

	string tempStatus;

	/*filebuf fb;
	fb.open(file, std::ios::app);
	std::ostream os(&fb);*/

	ofstream out;
	out.open(file, ios::app);

	out << issueNumber;

	out.close();
}