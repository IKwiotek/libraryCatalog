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
	Magazine(string ID, string name, bool status, string category, string issueNumber);

	void setIssueNumber(string issueNumber);

	string getIssueNumber();

	virtual void printRecord() const;
	virtual void writeToFile(string file, int i) const;

private:
	string issueNumber;
};

#endif Magazine_H
