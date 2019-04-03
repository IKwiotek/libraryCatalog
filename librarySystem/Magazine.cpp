#include "stdafx.h"
#include "Magazine.h"

Magazine::Magazine()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
	setIssueNumber("Invalid");
}

Magazine::Magazine(string ID, string name, string status, string issueNumber)
{
	BaseText(ID, name, status);
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
