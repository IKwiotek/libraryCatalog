#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Journal.h"

Journal::Journal()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
	setCategory("Invaid");
	setVolume("Invalid");
}

Journal::Journal(string ID, string name, bool status, string category, string volume)
{
	setID(ID);
	setName(name);
	setStatus(status);
	setCategory(category);
	setVolume(volume);
}

void Journal::setVolume(string volume)
{
	this->volume = volume;
}

string Journal::getVolume()
{
	return volume;
}

void Journal::printRecord() const
{
	cout << "Volume: " << setw(20) << left << volume;
	BaseText::printRecord();
}

void Journal::writeToFile(string file, int i) const
{
	BaseText::writeToFile(file, i);
	ofstream out;
	out.open(file, ios::app);

	out << volume;

	out.close();
}
