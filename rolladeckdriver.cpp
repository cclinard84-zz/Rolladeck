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
#include <cstddef>
#include "rolladeck.h"
using namespace std;

int main(){
	Person *first = NULL;
	Person *print;
	int count;
   
	getInfo(&first);
	count = menu();
	ifMenu(&first, print, count);
}
