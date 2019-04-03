#include "stdafx.h"
#include "Journal.h"

Journal::Journal()
{
	setID("Invalid");
	setName("Invalid");
	setStatus("Invalid");
	setVolume("Invalid");
}

Journal::Journal(string ID, string name, string status, string volume)
{
	BaseText(ID, name, status);
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
