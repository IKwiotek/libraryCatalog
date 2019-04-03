#ifndef Magazine_H
#define Magazine_H
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"
#include "BaseText.h"

using namespace std;

class Magazine : public BaseText
{
public:
	Magazine();
	Magazine(string ID, string name, string status, string issueNumber);
	void setIssueNumber(string issueNumber);
	string getIssueNumber();

private:
	string issueNumber;
};

#endif // Journal_H
