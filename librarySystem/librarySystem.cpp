#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For function getch()
#include <vector>
#include <thread> 
#include <chrono>
#include <cstdlib>
#include "BaseText.h"
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"

using namespace std;

// Input File Location
const string textFileLocation = "C:\\temp\\extLog.txt";

//Populate BaseText Vector with Texts from File
void loadTextFromLog(const string textFileLocation, vector<BaseText*> &baseText);

//Populate Texts to File from BaseText Vector
void loadTextToLog(const string textFileLocation, vector<BaseText*> &baseText);

//Main Menu
void showMenu();

//Check Out Text
void checkOut(vector<BaseText*> &baseText);

//Check In Text
void checkIn(vector<BaseText*> &baseText);

//Add New Text
void addNewText(vector<BaseText*>& baseText);
void addNewTextMenu();

//Search Text
void searchAll(vector<BaseText*> &baseText);
void listAllTexts(vector<BaseText*> &baseText);

//Delete Allocated Memory Before Closing Program
void deleteAllocatedMemory(vector<BaseText*> &baseText);



int main()
{
	cout << "Welcome to the library catalog system." << endl;
	cout << "NOTE: The TextLog file is expected to be located at " << textFileLocation << endl;

	//Base class vector
	//This will be a pointer 
	//None of the objects we will instantiate will be of type BaseText
	//Each derived class object will be of a different size
	vector<BaseText*> baseTextVector;

	loadTextFromLog(textFileLocation, baseTextVector);
	cout << endl;

	int menuChoice;

	while (true) {

		showMenu();

		cin >> menuChoice;
		if (cin.fail()) return 0;

		switch (menuChoice) 
		{
		case 1: searchAll(baseTextVector);
			break;
		case 2: checkOut(baseTextVector);
			break;
		case 3: checkIn(baseTextVector) ;
			break;
		case 4: addNewText(baseTextVector);
			break;
		case 5: listAllTexts(baseTextVector);
			break;
		case 6: 
			loadTextToLog(textFileLocation, baseTextVector);
			deleteAllocatedMemory(baseTextVector);
			return 0;
		default:  cout << endl;
		}
		cout << endl;
	}
}

// Load Base Vector with Text from Book, 
void loadTextFromLog(const string inputFile, vector<BaseText*> &baseTextVector)
{
	ifstream fin(inputFile);

	if (!fin)
	{
		cout << "While opening the text log an error is encountered!" << endl;
		cout << "Ensure text file is located at " << inputFile << endl;
		this_thread::sleep_for(std::chrono::seconds(10));
		exit(0);
	}

	else
	{
		cout << "Text log successfully opened" << endl;
	}

	while (!fin.eof())
	{
		string id;
		string name;
		string tempStatus;
		string category;
		string temp;
		bool status;

		getline(fin, id);
		getline(fin, name);
		getline(fin, tempStatus);
		getline(fin, category);
		getline(fin, temp);

		if (tempStatus == "true" || tempStatus == "True")
		{
			status = true;
		}

		else
		{
			status = false;
		}


		if (category == "Book" || category == "book")
		{
			baseTextVector.push_back(new Book(id, name, status, category, temp));
		}

		else if (category == "Journal" || category == "journal")
		{
			baseTextVector.push_back(new Journal(id, name, status, category, temp));
		}

		else if (category == "Magazine" || category == "magazine")
		{
			baseTextVector.push_back(new Magazine(id, name, status, category, temp));
		}

		else
		{
			cout << "Error determining text category type." << endl;
		}

	}
}

void loadTextToLog(const string inputFile, vector<BaseText*>& baseText)
{
	int i = 0;
	std::ofstream ofs;
	ofs.open(inputFile, std::ofstream::out | std::ofstream::trunc);

	for (auto it = baseText.begin(); it != baseText.end(); it++)
	{
		(*it)->writeToFile(inputFile, i);
		i++;
	}
}


// Main Menu
void showMenu() 
{
	cout << "Please select an option from the following catalog choices." << endl;

	cout << "1. Search Catalog" << endl;
	cout << "2. Check OUT" << endl;
	cout << "3. Check IN" << endl;
	cout << "4. Add New Item" << endl;
	cout << "5. List Entire Catalog" << endl;
	cout << "6. Exit" << endl;
	cout << "Please enter a choice: ";
}


// SEARCH functionality
void searchAll(vector<BaseText*> &baseText)
{
	string temp;
	string trash;
	bool textFound = false;

	cout << "Enter the Title Name, Book Author, ID, or Category for Search: ";
	getline(cin, trash);
	getline(cin, temp);

	vector<BaseText*> ::iterator it;

	//Search for Title Name, ID, or Category in Base Text Objects
	for (it = baseText.begin(); it != baseText.end(); it++)
	{
		if ((*it)->searchRecord(temp))
		{
			cout << "Text successfully found!" << endl;
			(*it)->printRecord();
			textFound = true;
		}
	}

	if (textFound == false)
	{
		cout << "No Matching Text Found. Returning to main menu." << endl;
	}
}


// Check out functionality
void checkOut(vector<BaseText*> &baseText)
{
	string temp;
	string trash;
	bool found = false;

	cout << "Enter the Title Name to check out: ";
	getline(cin, trash);
	getline(cin, temp);

	vector<BaseText*> ::iterator it;

	for (it = baseText.begin(); it != baseText.end(); it++)
	{
		if ((*it)->searchRecord(temp))
		{
			if ((*it)->getStatus() != false)
			{
				(*it)->setStatus(false);
				cout << "\nText " << (*it)->getName() << " is now checked out!" << endl;
				found = true;
			}

			else
			{
				cout << "\nText is already checked out. Returning to main menu." << endl;
				found = true;
			}
			return;
		}
	}

	if (found == false)
	{
		cout << "\nNo matching text found. Returning to main menu." << endl;
	}
}


// Check in Functionality
void checkIn(vector<BaseText*> &baseText)
{
	string temp;
	string trash;
	bool found = false;

	cout << "Enter the Title Name to check in: ";
	getline(cin, trash);
	getline(cin, temp);

	vector<BaseText*> ::iterator it;

	for (it = baseText.begin(); it != baseText.end(); it++)
	{
		if ((*it)->searchRecord(temp))
		{
			if ((*it)->getStatus() == false)
			{
				(*it)->setStatus(true);
				cout << "\nText " << (*it)->getName() << " is now checked in!" << endl;
				found = true;
			}

			else
			{
				cout << "\nText is already checked in. Returning to main menu." << endl;
				found = true;
			}
			return;
		}
	}

	if (found == false)
	{
		cout << "\nNo matching text found. Returning to main menu." << endl;
	}
}


//Add new Text
void addNewText(vector<BaseText*>& baseText)
{
	string title;
	string ID;
	string trash;
	bool duplicate = false;

	cout << "Enter Text Title: ";
	getline(cin, trash);
	getline(cin, title);

	for (auto it = baseText.begin(); it != baseText.end(); it++)
	{
		if ((*it)->searchRecord(title))
		{
			cout << "Duplicate Error: Text with matching Title found." << endl;
			cout << "Returning to Main Menu" << endl;
			duplicate = true;
			return;
		}
	}

	if (!duplicate)
	{
		cout << "Enter Text ID: ";
		getline(cin, ID);

		for (auto itr = baseText.begin(); itr != baseText.end(); itr++)
		{
			if ((*itr)->searchRecord(ID))
			{
				cout << "Duplicate Error: Text with matching ID found." << endl;
				cout << "Returning to Main Menu" << endl;
				duplicate = true;
				return;
			}
		}
	}

	if (!duplicate)
	{
		int menuChoice;
		bool listMenu = true;

		while (listMenu) {

			string temp;
			addNewTextMenu();
			cin >> menuChoice;
			if (cin.fail()) listMenu = false;

			switch (menuChoice)
			{
			case 1:
				cout << "Please enter Author Name: ";
				getline(cin, trash);
				getline(cin, temp);
				baseText.push_back(new Book(ID, title, true, "Book", temp));
				cout << title << " added successfully!" << endl;
				listMenu = false;
				break;
			case 2:
				cout << "Please enter Volume Number: ";
				getline(cin, trash);
				getline(cin, temp);
				baseText.push_back(new Journal(ID, title, true, "Journal", temp));
				cout << title << " added successfully!" << endl;
				listMenu = false;
				break;
			case 3:
				cout << "Please enter Issue Number: ";
				getline(cin, trash);
				getline(cin, temp);
				baseText.push_back(new Journal(ID, title, true, "Magazine", temp));
				cout << title << " added successfully!" << endl;
				listMenu = false;
				break;
			case 4:;
				listMenu = false;
				break;
			default:  cout << endl;
			}
			cout << endl;
		}
	}
}

void addNewTextMenu()
{
	cout << "Please select an option from the following add choices." << endl;
	cout << "1. Add Book" << endl;
	cout << "2. Add Journal" << endl;
	cout << "3. Add Magazine" << endl;
	cout << "4. Exit" << endl;
	cout << "Please enter a choice: ";
}


//List All Texts
void listAllTexts(vector<BaseText*>& baseText)
{
	for (auto it = baseText.begin(); it != baseText.end(); it++)
	{
		(*it)->printRecord();
	}
}


//Delete allocated memory before closing program
void deleteAllocatedMemory(vector<BaseText*> &baseText)
{
	for (auto it = baseText.begin(); it != baseText.end(); it++)
	{
		delete(*it);
	}
}




