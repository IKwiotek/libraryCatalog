#ifndef Journal_H
#define Journal_H
#include <iostream>
#include <iomanip>
#include <string>
#include "stdafx.h"
#include "BaseText.h"

using namespace std;

class Journal : public BaseText
{
public:
	Journal();
	Journal(string ID, string name, string status, string volume);
	void setVolume(string volume);
	string getVolume();

private:
	string volume;
};

#endif // Journal_H
