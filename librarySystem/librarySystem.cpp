#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h> // For function getch()
#include <vector>
#include "BaseText.h"
#include "Book.h"
#include "Journal.h"
#include "Magazine.h"

using namespace std;

void showMenu();
void listAllTexts(vector<Book> &bookList, vector<Journal> &journalList, vector<Magazine> &magazineList);
vector<Book> loadBookTextFromLog();
vector<Magazine> loadMagazineTextFromLog();
vector<Journal> loadJournalTextFromLog();




int main()
{
	cout << "Welcome to the library catalog system.\n" << endl;

	vector<Book> bookList = loadBookTextFromLog();
	vector<Journal> journalList = loadJournalTextFromLog();
	vector<Magazine> magazineList = loadMagazineTextFromLog();



	int menuChoice;

	while (true) {

		showMenu();
		cin >> menuChoice;

		switch (menuChoice) 
		{
		case 1: ;
			break;
		case 2: ;
			break;
		case 3:;
			break;
		case 4:;
			break;
		case 5:;
			break;
		case 6: listAllTexts(bookList, journalList, magazineList);
			break;
		case 7:;
			break;
		default:  cout << endl;
		}
		cout << endl;
	}
	_getch();
}

void showMenu() 
{
	cout << "Please select an option from the following catalog choices." << endl;

	cout << "1. Search Catalog" << endl;
	cout << "2. Check OUT" << endl;
	cout << "3. Check IN" << endl;
	cout << "5. Add new item" << endl;
	cout << "6. List entire catalog." << endl;
	cout << "7. Exit" << endl;
	cout << "Please enter a choice: " << endl;
}

void listAllTexts(vector<Book> &book, vector<Journal> &journalList, vector<Magazine> &magazineList)
{



	cout << "Printing Values from Book List" << endl;
	for (auto i = book.begin(); i != book.end(); i++)
	{
		cout << "ID: " << i->getID() << " Name: " << i->getName() << " Status: " << i->getStatus() << " Author: " << i->getAuthorName() << endl;
	}


	cout << endl;

}

vector<Book> loadBookTextFromLog()
{
	ifstream fin("C:\\BookLog.txt");
	int i = 0;
	vector<Book> bookVector;

	/*int lineCount = std::count(std::istreambuf_iterator<char>(fin),
		std::istreambuf_iterator<char>(), '\n');
	lineCount++;
*/


	if (!fin)
	{
		cout << "While opening the book log an error is encountered!" << endl;
	}

	else
	{
		cout << "Book log successfully opened" << endl;
	}

	while (!fin.eof())
	{
		string ID[1];
		string Name[1];
		string Status[1];
		string Author[1];

		fin >> ID[i] >> Name[i] >> Status[i] >> Author[i];

		Book book(ID[i], Name[i], Status[i], Author[i]);
		bookVector.push_back(book);
	}

	return bookVector;
}

vector<Magazine> loadMagazineTextFromLog()
{
	ifstream fin("C:\\MagazineLog.txt");
	int i = 0;
	vector<Magazine> magazineVector;

	if (!fin)
	{
		cout << "While opening the magazine log an error is encountered!" << endl;
	}

	else
	{
		cout << "Magazine log successfully opened" << endl;
	}

	while (!fin.eof())
	{
		string ID[1];
		string Name[1];
		string Status[1];
		string IssueNumber[1];

		fin >> ID[i] >> Name[i] >> Status[i] >> IssueNumber[i];

		Magazine magazine(ID[i], Name[i], Status[i], IssueNumber[i]);
		magazineVector.push_back(magazine);
	}

	return magazineVector;
}

vector<Journal> loadJournalTextFromLog()
{
	ifstream fin("C:\\JournalLog.txt");
	int i = 0;
	vector<Journal> journalVector;

	if (!fin)
	{
		cout << "While opening the journal log an error is encountered!" << endl;
	}

	else
	{
		cout << "Journal log successfully opened" << endl;
	}

	while (!fin.eof())
	{
		string ID[1];
		string Name[1];
		string Status[1];
		string Volume[1];

		fin >> ID[i] >> Name[i] >> Status[i] >> Volume[i];

		Journal journal(ID[i], Name[i], Status[i], Volume[i]);
		journalVector.push_back(journal);
	}

	return journalVector;
}


