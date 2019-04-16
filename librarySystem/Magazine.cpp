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

string Magazine::getIssueNumber() const
{
	return issueNumber;
}

void Magazine::printRecord() const
{
	cout << "Issue Number: " << setw(14) << left << issueNumber;
	BaseText::printRecord();
}

void Magazine::writeToFile(string file, int i) const
{
	BaseText::writeToFile(file, i);
	ofstream out;
	out.open(file, ios::app);

	out << issueNumber;

	out.close();
}