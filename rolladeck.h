//
// Name: Christopher Clinard
// Date: 2/09/2016
// Description: This program reads contact information
//				in from a file, alphabetizes it,
//				allows the user to list all, see first 
//				contact, see last contact, and navigate 
//				through the list. Passes all 11 
//				requirements.
//
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <cstdio>
using namespace std;

struct Person{
	string firstName;
	string lastName;
	string number;
	Person *next;
	Person *prev;
};

void getInfo(Person **first);
void traverse(Person **first, Person *p);
void insertFront(Person *traverse, Person *p, Person **first);
void insertMiddle(Person *traverse, Person *p);
void insertBack(Person *traverse, Person *p);
int menu();
void listAll(Person **first, Person *print);
Person *lastContact(Person **first, Person *print);
Person *firstContact(Person **first, Person *print);
void menuSelect(Person **first, Person *print, Person *p);
void search(Person **first);
void ifMenu(Person **first, Person *print, int count);

