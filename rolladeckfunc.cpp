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

/* getInfo: Opens file, extracts data, creates new nodes, lowers all applicable characters,
*  	    and fills new nodes with data.
*  Parameters:
*	Person **first: pointer used to indicate the first node.
*  Preconditions: None
*  Postcondition: New node is created, applicable data is lower cased, 
*  		  and new node is filled with data.
*  Returns: Nothing
*/
void getInfo(Person **first){
	Person *p; // Person pointer used to assign new nodes.
	string tempName; // string used to temporarily hold data.
	ifstream input;
	input.open("contacts.dat"); 
	while(input >> tempName){
		p = new Person(); // creates New node
		p->next = NULL; // next = Null pointer for new node
                p->prev = NULL; // prev = Null pointer for new node
		for(int j = 0; j < 20 ; j++){ // To lower loop for tempName
				tempName[j] = tolower(tempName[j]);
		}
		p->firstName = tempName; // tranfers temp data to structure element
		input >> p->lastName;
		for(int k = 0; k < 20; k++){ // To lower loop for lastName
			p->lastName[k] = tolower(p->lastName[k]);
		}
		input >> p->number;
		traverse(first, p);
		
	}
	input.close();
}
/* traverse: traverses the list to assign a new node it's place within the list 
*            alphabetically.
*  Parameters: 
*  	Person **first: pointer used to indicate the first node.
*       Person *p: person pointer which is a new node.
*  Precondition: p has been filled with data
*  Postcondition: the new node has been assigned a place within the list
*  Returns: Nothing
*/
void traverse(Person **first, Person *p){
	Person *traverse;
	// If p is the first node that has made it into the list it is now first.
	if(*first == NULL){ 
		*first = p;
		return;
	}
	traverse = *first; // sets traverse to point at the first node
	while(true){
		if(p->lastName < traverse->lastName){
			if(traverse->prev == NULL){
				insertFront(traverse, p, first);
				break;
			}
			else{
				insertMiddle(traverse, p);
				break;
			}
		}
		else if(p->lastName == traverse->lastName){
			if(traverse->prev == NULL){
				insertFront(traverse, p, first);
				break;
			}
			else{
				insertMiddle(traverse,p);
				break;
			}
		}
		if(traverse->next == NULL){
                	insertBack(traverse, p);
			break;
		}
		traverse = traverse->next;		
	}
}
/* insertFront: inserts the new node into the front of the list.
*  Parameters:
*	Person *traverse: Person pointer used to walk the list.
*	Person *p: Person pointer used as the new node.
*       Person **first: Pointer allocated to point to the first node.
*  Precondition: p has been assigned to the front of the list from the traverse function.
*  Postcondition: p has been placed in the front of the list.
*  Returns: Nothing
*/
void insertFront(Person *traverse, Person *p, Person **first){
	p->next = traverse;
	traverse->prev = p;
	*first = p;
	
}
/* insertMiddle: inserts the new node in between two nodes.
*  Parameters:
*	Person *traverse: Person pointer used to walk the list.
*       Person *p: Person pointer used as the new node.
*  Precondition: p has been assigned into a space between two nodes.
*  Postcondition: p has been placed in between two nodes.
*  Returns: Nothing
*/
void insertMiddle(Person *traverse, Person *p){
	p->next = traverse;
	p->prev = traverse->prev;
	traverse->prev->next = p;
	traverse->prev = p;

}
/* insertBack: inserts the new node at the back of the list.
*  Parameters:
*	Person *traverse: Person pointer used to walk the list.
*       Person *p: Person pointer used as the new node.
*  Precondition: p has been assigned to the back of the list.
*  Postcondition: p has been placed at the back of the list.
*  Returns: Nothing
*/
void insertBack(Person *traverse, Person *p){
	p->prev = traverse;
	traverse->next = p;
	
}
/* menu: displays the menu to the user and returns the user input.
*  Parameters: None
*  Precondition: None
*  Postcondition: None
*  Returns: int choice - the users choice.
*/
int menu(){
	int choice;
	cout << "What would you like to do?" << endl;
	cout << "1) Search" << endl;
	cout << "2) List all" << endl;
	cout << "3) Show the first contact in the list" << endl;
	cout << "4) Show the last contact in the list" << endl;
	cout << "5) Exit" << endl;
	cin >> choice;
	return choice;
}

/* listAll: lists every person and their respective data recieved from the input file.
*  Parameters: 
*	Person **first: Person pointer used to point at the first node of data.
*       Person *print: Person pointer used to walk the list
*  Precondition: Data nodes have been assigned a place in the list and filled with data
*  Postcondition: Every node within the list has been printed
*  Returns: Nothing.
*/
void listAll(Person **first, Person *print){
	 for(print = *first; print != NULL; print = print->next){
                cout << print->lastName << endl;
		cout << print->firstName << endl;
		cout << print->number << endl;
        }
}

/* lastContact: displays the last contact to the user
*  Parameters:
*	Person **first: Person pointer used to point at the first node of data.
*       Person *print: Person pointer used to walk the list.
*  Precondition: Data nodes have been assigned a place in the list and filled with data
*  Postcondition: Last node in the list is printed.
*  Returns: Nothing.
*/
Person *lastContact(Person **first, Person *print){
	int choice;
	if (*first == NULL)
		return(NULL);
	Person *p = *first;
	while(p->next != NULL){
		p = p->next;	
	}
	cout << p->lastName << endl;
	cout << p->firstName << endl;
	cout << p->number << endl;
	cout << "Please select the following:" << endl;
	menuSelect(first, print, p);
}

/* firstContact: displays the first contact to the user
*  Parameters:
*	Person **first: Person pointer used to point at the first node of data.
*       Person *print: Person pointer used to walk the list in certain functions.
*  Precondition: Data nodes have been assigned a place in the list and filled with data.
*  Postcondition: First node in the list is printed.
*  Returns: Nothing.
*/ 
Person *firstContact(Person **first, Person *print){
	Person *p = *first;
	cout << p->lastName << endl;
	cout << p->firstName << endl;
	cout << p->number << endl;
	cout << "Please select the following:" << endl;
	menuSelect(first, print, p);
}

/* menuSelect: Allows the user to manually walk the list after selecting to see
*              the first contact or last contact in the list.
*  Parameters: 
*       Person **first: Person pointer used to point at the first node of data.
*       Person *print: Person pointer used to walk the list in certain functions.
*       Person *p: Person pointer used in this case to walk the list
*  Precondition: User has selected to see the first or last contact in the list
*  Postcondition: Returns user to the main menu once they have completed their 
*                 walk through the list.
*  Returns: Nothing
*/ 
void menuSelect(Person **first, Person *print, Person *p){
	int choice;
	int count;
        cout << "1) Previous Entry(if applicable)" << endl;
        cout << "2) Next Entry(if applicable)" << endl;
        cout << "3) Return to the Main Menu" << endl;
	cin >> choice;
        if(choice == 1){
                if(p->prev == NULL){
                        cout << "There is no previous entry." << endl;
			menuSelect(first, print, p);
                }
                else{
                	p = p->prev;
                	cout << p->lastName << endl;
                	cout << p->firstName << endl;
                	cout << p->number << endl;
			menuSelect(first, print, p);
		}
        }
        else if(choice == 2){
		if(p->next == NULL){
			cout << "There is no next entry." << endl;
			menuSelect(first, print, p);
		}
		else{
			p = p->next;
			cout << p->lastName << endl;
                        cout << p->firstName << endl;
                        cout << p->number << endl;
			menuSelect(first, print, p);
		}
        }
        else{
               	count = menu();
		ifMenu(first, print, count);
        }

}
/* search: Asks the user for the search term and walks the list attempting to find matching criteria
*	   and displays matching criteria to the user.
*  Parameters:
*     Person **first: Person pointer that points to the first node in the list.
*  Precondition: None
*  Postcondition: Displays information if search term is found within nodes or an error if no
*                 information is a match.
*  Returns: Nothing.
*/
void search(Person **first){
	Person *p = *first;
	string searchName;
	cout << "Please enter a part of a name or number you want to search for. " << endl;
	cin >> searchName;
	for(int i = 0; i < 20; i++){
		searchName[i] = tolower(searchName[i]);
	}
	// Loop to walk through, search, and display information relevant to searched string. 
	while(p->next != NULL){		
                if((p->lastName.find(searchName) != string::npos) || (p->firstName.find(searchName) != string::npos) || (p->number.find(searchName) != string::npos)){  
                        cout << p->lastName << endl;
                        cout << p->firstName << endl;
                        cout << p->number << endl;
			p = p->next;
                }
                else{
                        p = p->next;
                }
        }
	// Error if no entry match
	if((p->lastName.find(searchName) == string::npos) || (p->firstName.find(searchName) == string::npos) || (p->number.find(searchName) == string::npos))
		cout << "There are no results for that entry." << endl;

}
/* ifMenu: Menu displayed to the user 
*  Parameters: 
*	Person **first: Person pointer used to point to the first node.
*	Person *print: Person pointer used to walk the list in certain functions.
*       int count: integer used to make a menu selection
*  Precondition: User has made a menu selection.
*  Postcondition: Sent to corresponding function.
*  Returns: Nothing
*/
void ifMenu(Person **first, Person *print, int count){
	if(count == 1){
                search(first);
        }
        else if(count == 4){
                lastContact(first, print);
        }
        else if(count == 3){
                firstContact(first, print);
        }
        else if(count == 2){
                listAll(first, print);
        }
        else{
                cout << "Thanks for using this program!" << endl;
                exit(1);
        }

}
