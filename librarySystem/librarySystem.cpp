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

const string bookFileLocation = "C:\\BookLog.txt";
const string journalFileLocation = "C:\\JournalLog.txt";
const string magazineFileLocation = "C:\\MagazineLog.txt";


void showMenu();
void listAllTexts();
void listBooks();
void listJournals();
void listMagazines();
vector<Book> loadBookTextFromLog(const string bookFileLocation);
vector<Journal> loadJournalTextFromLog(const string journalFileLocation);
vector<Magazine> loadMagazineTextFromLog(const string magazineFileLocation);


void showSearchMenu();
void searchAllTexts();
void searchTextByName();
void searchTextByCategory();
void searchBookByAuthor();



void checkOutText();


void updateBookTextToLog(vector<Book> books, const string bookFileLocation);



int main()
{
	cout << "Welcome to the library catalog system.\n" << endl;

	int menuChoice;

	while (true) {

		showMenu();
		cin >> menuChoice;

		switch (menuChoice) 
		{
		case 1: searchAllTexts();
			break;
		case 2: checkOutText();
			break;
		case 3:;
			break;
		case 4:;
			break;
		case 5:;
			break;
		case 6: listAllTexts();
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
	cout << "Please enter a choice: ";
}




// Search functionality

void showSearchMenu()
{
	cout << "Please select an option from the following search choices." << endl;

	cout << "1. Search by text Name" << endl;
	cout << "2. Search by text Category" << endl;
	cout << "3. Search Books by Author" << endl;
	cout << "4. Exit" << endl;
	cout << "Please enter a choice: ";
}

void showSearchCategoryMenu()
{
	cout << "Please select an option from the following category choices." << endl;

	cout << "1. Display all texts of type BOOK" << endl;
	cout << "2. Display all texts of type Journal" << endl;
	cout << "3. Display all texts of type MAGAZINE" << endl;
	cout << "4. Exit" << endl;
	cout << "Please enter a choice: ";
}

void searchTextByCategory()
{
	int menuChoice;
	bool listMenu = true;

	while (listMenu) {

		showSearchCategoryMenu();
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:listBooks();
			listMenu = false;
			break;
		case 2:listJournals();
			listMenu = false;
			break;
		case 3:listMagazines();
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

void searchAllTexts()
{
	int menuChoice;
	bool listMenu = true;

	while (listMenu) {

		showSearchMenu();
		cin >> menuChoice;

		switch (menuChoice)
		{
		case 1:searchTextByName();
			listMenu = false;
			break;
		case 2:searchTextByCategory();
			listMenu = false;
			break;
		case 3:searchBookByAuthor();
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

void searchTextByName()
{
	string textName;
	bool textFound = false;

	cout << "Enter text name: ";
	cin >> textName;

	vector<Book> bookList = loadBookTextFromLog(bookFileLocation);
	vector<Journal> journalList = loadJournalTextFromLog(journalFileLocation);
	vector<Magazine> magazineList = loadMagazineTextFromLog(magazineFileLocation);

	for (int i = 0; i < bookList.size(); i++)
	{
		if (textName == bookList[i].getName())
		{
			cout << "Text Located in Book Category: " << endl;
			cout << "ID: " << bookList[i].getID() << " Name: " << bookList[i].getName() << " Status: " << bookList[i].getStatus() << " Author: " << bookList[i].getAuthorName() << endl;
			textFound = true;
		}
	}

	for (int i = 0; i < journalList.size(); i++)
	{
		if (textName == journalList[i].getName())
		{
			cout << "Text Located in Journal Category: " << endl;
			cout << "ID: " << journalList[i].getID() << " Name: " << journalList[i].getName() << " Status: " << journalList[i].getStatus() << " Volume: " << journalList[i].getVolume() << endl;
			textFound = true;
		}
	}

	for (int i = 0; i < magazineList.size(); i++)
	{
		if (textName == magazineList[i].getName())
		{
			cout << "Text Located in Magazine Category: " << endl;
			cout << "ID: " << magazineList[i].getID() << " Name: " << magazineList[i].getName() << " Status: " << magazineList[i].getStatus() << " Issue Number: " << magazineList[i].getIssueNumber() << endl;
			textFound = true;
		}
	}

	if (textFound = false)
	{
		cout << "No text matching specified name found." << endl;
	}

}

void searchBookByAuthor()
{
	string authorName;
	bool textFound = false;

	cout << "Enter author name: ";
	cin >> authorName;

	vector<Book> bookList = loadBookTextFromLog(bookFileLocation);

	for (int i = 0; i < bookList.size(); i++)
	{
		if (authorName == bookList[i].getAuthorName())
		{
			cout << "Text Located in Book Category: " << endl;
			cout << "ID: " << bookList[i].getID() << " Name: " << bookList[i].getName() << " Status: " << bookList[i].getStatus() << " Author: " << bookList[i].getAuthorName() << endl;
			textFound = true;
		}
	}

	if (textFound = false)
	{
		cout << "No text matching specified author name found." << endl;
	}
}




// Check out functionality
void checkOutText()
{
	string textName;
	bool textFound = false;

	cout << "Enter text name: ";
	cin >> textName;

	vector<Book> bookList = loadBookTextFromLog(bookFileLocation);
	vector<Journal> journalList = loadJournalTextFromLog(journalFileLocation);
	vector<Magazine> magazineList = loadMagazineTextFromLog(magazineFileLocation);

	for (int i = 0; i < bookList.size(); i++)
	{
		if (textName == bookList[i].getName())
		{
			cout << "Text Located in Book Category: " << endl;
			cout << "ID: " << bookList[i].getID() << " Name: " << bookList[i].getName() << " Status: " << bookList[i].getStatus() << " Author: " << bookList[i].getAuthorName() << endl;
			textFound = true;

			if (bookList[i].getStatus() != "Available")
			{
				cout << "Error: " << bookList[i].getName() << " is already checked-out" << endl;
			}

			else
			{
				bookList[i].setStatus("Unavailable");
				updateBookTextToLog(bookList, bookFileLocation);
				cout << bookList[i].getName() << " is checked out" << endl;
			}
		}
	}

	for (int i = 0; i < journalList.size(); i++)
	{
		if (textName == journalList[i].getName())
		{
			cout << "Text Located in Journal Category: " << endl;
			cout << "ID: " << journalList[i].getID() << " Name: " << journalList[i].getName() << " Status: " << journalList[i].getStatus() << " Volume: " << journalList[i].getVolume() << endl;
			textFound = true;
		}
	}

	for (int i = 0; i < magazineList.size(); i++)
	{
		if (textName == magazineList[i].getName())
		{
			cout << "Text Located in Magazine Category: " << endl;
			cout << "ID: " << magazineList[i].getID() << " Name: " << magazineList[i].getName() << " Status: " << magazineList[i].getStatus() << " Issue Number: " << magazineList[i].getIssueNumber() << endl;
			textFound = true;
		}
	}

	if (textFound = false)
	{
		cout << "No text matching specified name found." << endl;
	}
}



// List Text Functionality

void listAllTexts()
{
	listBooks();
	listJournals();
	listMagazines();
}

void listBooks()
{
	vector<Book> bookList = loadBookTextFromLog(bookFileLocation);

	cout << "Printing Values from Book List" << endl;
	for (auto i = bookList.begin(); i != bookList.end(); i++)
	{
		cout << "ID: " << i->getID() << " Name: " << i->getName() << " Status: " << i->getStatus() << " Author: " << i->getAuthorName() << endl;
	}
	cout << endl;
}

void listJournals()
{
	vector<Journal> journalList = loadJournalTextFromLog(journalFileLocation);

	cout << "Printing Values from Journal List" << endl;
	for (auto i = journalList.begin(); i != journalList.end(); i++)
	{
		cout << "ID: " << i->getID() << " Name: " << i->getName() << " Status: " << i->getStatus() << " Volume: " << i->getVolume() << endl;
	}
	cout << endl;
}

void listMagazines()
{
	vector<Magazine> magazineList = loadMagazineTextFromLog(magazineFileLocation);

	cout << "Printing Values from Magazine List" << endl;
	for (auto i = magazineList.begin(); i != magazineList.end(); i++)
	{
		cout << "ID: " << i->getID() << " Name: " << i->getName() << " Status: " << i->getStatus() << " Issue Number: " << i->getIssueNumber() << endl;
	}
	cout << endl;
}



// Read Text from Input File

vector<Book> loadBookTextFromLog(const string inputFile)
{
	ifstream fin(inputFile);
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

		// Book book(ID[i], Name[i], Status[i], Author[i]);

		Book book;
		book.setID(ID[i]);
		book.setName(Name[i]);
		book.setStatus(Status[i]);
		book.setAuthorName(Author[i]);

		bookVector.push_back(book);
	}

	return bookVector;
}

vector<Journal> loadJournalTextFromLog(const string inputFile)
{
	ifstream fin(inputFile);
	int i = 0;
	vector<Journal> journalVector;

	/*if (!fin)
	{
		cout << "While opening the journal log an error is encountered!" << endl;
	}

	else
	{
		cout << "Journal log successfully opened" << endl;
	}*/

	while (!fin.eof())
	{
		string ID[1];
		string Name[1];
		string Status[1];
		string Volume[1];

		fin >> ID[i] >> Name[i] >> Status[i] >> Volume[i];

		// Journal journal(ID[i], Name[i], Status[i], Volume[i]);

		Journal journal;
		journal.setID(ID[i]);
		journal.setName(Name[i]);
		journal.setStatus(Status[i]);
		journal.setVolume(Volume[i]);

		journalVector.push_back(journal);
	}

	return journalVector;
}

vector<Magazine> loadMagazineTextFromLog(const string inputFile)
{
	ifstream fin(inputFile);
	int i = 0;
	vector<Magazine> magazineVector;

	/*if (!fin)
	{
		cout << "While opening the magazine log an error is encountered!" << endl;
	}

	else
	{
		cout << "Magazine log successfully opened" << endl;
	}*/

	while (!fin.eof())
	{
		string ID[1];
		string Name[1];
		string Status[1];
		string IssueNumber[1];

		fin >> ID[i] >> Name[i] >> Status[i] >> IssueNumber[i];

		// Magazine magazine(ID[i], Name[i], Status[i], IssueNumber[i]);

		Magazine magazine;
		magazine.setID(ID[i]);
		magazine.setName(Name[i]);
		magazine.setStatus(Status[i]);
		magazine.setIssueNumber(IssueNumber[i]);

		magazineVector.push_back(magazine);
	}

	return magazineVector;
}



// Update Text from Input File

void updateBookTextToLog(vector<Book> bak, const string inputFile)
{
	filebuf fb;
	fb.open(inputFile, ios::out);
	std::ostream os(&fb);
	for (int i = 0; i < bak.size(); i++)
	{
		Book book = bak[i];

		os << book.getID() << " " << book.getName() << " " << book.getStatus() << " " << book.getAuthorName() << "\n";
	}
	fb.close();
}
