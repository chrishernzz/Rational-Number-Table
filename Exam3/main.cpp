//name: Christian Hernandez
//date: 6/6/2023
//subscription: CMPR121

#include<iostream>
#include<iomanip>
#include"input.h"
#include"Rational.h"
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<windows.h>
using namespace std;

//Prototypes
void displayMenu();
char menuOption();
void displayVectorMenu();
void challengeV();
void displayListMenu();
void challengeL();
void displayStackMenu();
void challengeS();
void displayQueueMenu();
void challengeQ();

int main()
{
	do {
		switch (menuOption()){
		case 'X': exit(0);
		case 'V': challengeV(); break;
		case 'L': challengeL(); break;
		case 'S': challengeS(); break;
		case 'Q': challengeQ(); break;
		default: cout << "\t\t\tERROR - Invalid option. Please re-enter.\n"; break;
		}
		cout << "\n";
		system("pause");
		system("cls");
	} while (true);
	return EXIT_SUCCESS;
}

//precondition: going to make a menu
//postcondition: going to then do an input char, returning a char
char menuOption()
{
	system("cls");
	cout << endl;
	displayMenu();
	cout << "\n\tCMPR121 EXAM 3- STL(Standard Template Library) Container and Container Adaptors by Christian Hernandez(6-6-2023)\n";
	cout << "\n\t" << string(95, char(205)) << "\n";
	cout << "\tV. Vector Container\n";
	cout << "\tL. List Container\n";
	cout << "\tS. Stack Container Adaptor\n";
	cout << "\tQ. Queue Container Adaptor\n";
	cout << "\tX. Exit\n";
	cout << "\t" << string(95, char(205)) << "\n";
	return inputChar("\tOption: ", static_cast<string>("VLSQX"));
}

//precondition: going to call the Rational class header
//postcondition: going to be doing 6 cases that add, insert, retrieve, erase, sort in ascending, and clear all the elemnts using a vector(using the include vector)
void challengeV()
{
	system("cls");
	Rational element;
	vector<Rational> arrayelements;
	int option;
	do {
		beginning:
		system("cls");
		//displaying the information of vector
		displayVectorMenu();

		if (arrayelements.empty()) {
			cout << "\n\tThe current vector is empty\n\n\n";
		}
		else {
			cout << endl;
			//check if the size is at element 0, if it is then theres only one element
			if (arrayelements.size() - 1 == 0) {
				cout << "\tThe current vector contains " << arrayelements.size() << " element:\n\t\t ";
				for (int i = 0; i < arrayelements.size(); i++) {
					cout << arrayelements[i] << " ";
				}
				cout << "\n\tindex: ";
				for (int j = 0; j < arrayelements.size(); j++) {
					cout << setw(4) << right << j;
				}
				//getting the address
				cout << "\n\taddress: " << arrayelements.data();
			}
			//else there are many element(s)
			else {
				cout << "\tThe current vector contains " << arrayelements.size() << " elements:\n\t\t ";
				for (int i = 0; i < arrayelements.size(); i++) {
					cout << arrayelements[i] << " ";
				}
				cout << "\n\tindex: ";
				for (int j = 0; j < arrayelements.size(); j++) {
					cout << setw(4) << right << j;
				}
				//getting the address
				cout << "\n\taddress: " << arrayelements.data();
			}
		}
		cout << "\n\n\tVector Menu Options\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t1. Add an element to the back\n";
		cout << "\t2. Insert an element at an index\n";
		cout << "\t3. Retrieve an element at an index\n";
		cout << "\t4. Erase element(s)\n";
		cout << "\t5. Sort the elements in ascending order\n";
		cout << "\t6. Clear all elements\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t0. Return to menu\n";
		cout << "\t" << string(85, char(205)) << "\n";
		option = inputInteger("\tOption: ", 0, 6);

		switch (option) {
		case 1: {

			cout << "\n\tInput a Rational number to be added...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));

				//pushing back the elements
				arrayelements.push_back(element);
				cout << "\n\t" << element << " will be added to the back of the vector.\n";

			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << element<< ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 2: {
			int index = 0;
			int size = arrayelements.size() - 1;
			cout << "\n\tInput a Rational number to be inserted...\n";
			try {
				if (arrayelements.empty()) {
					element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
					element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
					cout << "\n\t" << element << " will be inserted at index " << index << " to the vector.\n";
					arrayelements.insert(arrayelements.begin() + index, element);
					cout << endl;
					system("pause");
					system("cls");
					break;
				}
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
				cout << "\n\tInsert the element at index (0..." << size << ") of the vector: ";
				index = inputInteger("", 0, size);

				if (index == 0) {
					auto it = arrayelements.begin();
					//going to insert
					arrayelements.insert(it, element);
				}
				else {
					auto it = arrayelements.begin() + index;
					arrayelements.insert(it, element);
				}
				cout << "\n\t" << element << " will be inserted at index "<<index<<" to the vector.\n";

			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 3: {
			//check if vector is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tRetrieve operation cannot be performed from an empty vector.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			int index = arrayelements.size() - 1; 
			cout << "\n\tEnter an index (0..." << index << ") of Rational number to be retrieved: ";
			int option = inputInteger("",0,index);

			cout << "\n\t" <<arrayelements[option].toString() << " is located at index " << option << " from the vector.\n";
	
			cout << endl;
			system("pause");
			system("cls");

		}
			  break;
		case 4: {
			//check if vector is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tErase operation cannot be performed onto an empty vector.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			cout << "\n\tInput a Rational number to be removed...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));

				//going to find the position we are loooking, first getting the range from beginning to end
				//3rd argu has the numerator/denominator we are looking for
				auto it = find(arrayelements.begin(), arrayelements.end(), element);

				//going to do a if statement cheking if its not at the end of the array(elements), keep checking
				if (it != arrayelements.end()) {
					char option = inputChar("\n\tDo you want to remove (O-one or A-all) element(s): ", static_cast<string>("OA"));
					switch (option) {
					case 'O': {
						//going to erase an element
						arrayelements.erase(it);
						cout << "\n\t" << element << " will be removed from the vector.\n";
					}
							break;
					case 'A': {
						//keep track how many there is 
						int count = 0;
						//getting the begin() to the end(), do a if statement to check if the it is equal to the element equals, if equal then erase it
						for (auto it = arrayelements.begin(); it != arrayelements.end();) {
							//if the it is equal to the element, run this
							if (*it == element) {
								it = arrayelements.erase(it);
								count++;
							}
							else {
								++it;
							}
						}
						cout << "\n\t" << element << " will be removed from the vector.\n";
					}
							break;
					}
				}
				//else if the numerator/donominator not found then run this
				else {
					cout << "\n\t" << element << " cannot be found from the vector.\n";
				}
			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 5: {
			//check if vector is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tSort operation cannot be performed on an empty vector.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//sorting in ascending
			sort(arrayelements.begin(), arrayelements.end());
			cout << "\n\tThe vector will be sorted in ascending order.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 6: {
			//check if vector is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tClear operation cannot be performed on an empty vector.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//clearing the vector so it can be empty
			arrayelements.clear();
			cout << "\n\tThe vector will be cleared of all elements.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 0: {
			return;
		}
		}

	} while (true);
}

//precondition: going to call the Rational class header
//postcondition: going to be doing 5 cases that add, insert, remove, sort, and clear all the elements using a link(using the include list)
void challengeL()
{
	system("cls");
	Rational element;
	list<Rational>arrayelements;
	int option;
	do {
		beginning:
		system("cls");
		//displaying the information of list
		displayListMenu();
		if (arrayelements.empty()) {
			cout << "\n\tThe current list is empty\n\n\n";
		}
		else {
			cout << endl;
			//check if the size is at element 0, if it is then theres only one element
			if (arrayelements.size() - 1 == 0) {
				cout << "\tThe current list contains " << arrayelements.size() << " element:\n\t ";
				for (auto& value : arrayelements) {
					cout << value << " ";
				}
				//getting the address
				cout << "\n\taddress: " << &arrayelements;
			}
			//else there are element(s)
			else {
			cout << "\tThe current list contains " << arrayelements.size() << " elements:\n\t ";
			for (auto& value : arrayelements) {
				cout << value << " ";
			}
			//getting the address
			cout << "\n\taddress: " << &arrayelements;
			}
		}
		cout << "\n\n\tList Menu Options\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t1. Add an element\n";
		cout << "\t2. Insert an element after\n";
		cout << "\t3. Remove element(s)\n";
		cout << "\t4. Sort the elements in ascending order\n";
		cout << "\t5. Clear all elements\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t0. Return to menu\n";
		cout << "\t" << string(85, char(205)) << "\n";
		option = inputInteger("\tOption: ", 0, 5);

		switch (option) {
		case 1: {
			cout << "\n\tInput a Rational number to be added...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
				//if the list is empty then, add the first element to the empty list
				if (arrayelements.empty()) {
					//pushing back the elements
					arrayelements.push_back(element);
					cout << "\n\t" << element << " will be added to the empty list.\n";
				}
				else {
					char option = inputChar("\tAdd to the (F-front) or from the (B-back): ", static_cast<string>("FB"));
					switch (option) {
					case 'F': {
						//going to be putting the element in the front
						arrayelements.push_front(element);
						cout << "\n\t" << element << " will be pushed to the front of the list.\n";
					}
							break;
					case 'B': {
						//going to be putting the element in the back 
						arrayelements.push_back(element);//back();
						cout << "\n\t" << element << " will be pushed to the back of the list.\n";
					}
							break;
					}
				}

			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 2: {
			//to hold the position we are looking for
			Rational temp;
			int index = 0;
			int size = arrayelements.size() - 1;
			cout << "\n\tInput a Rational number to be inserted...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
				//if the list is empty then, add the first element to the empty list
				if (arrayelements.empty()) {
					//pushing back the elements
					arrayelements.push_back(element);
					cout << "\n\t" << element << " will be inserted to the empty list.\n";
					cout << endl;
					system("pause");
					system("cls");
					break;
				}
				cout << "\n\tInput an existing Rational number as the insert position to be added...\n";
				temp.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				temp.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
				
				//going to find the position we are loooking, first getting the range from beginning to end
				//3rd argu has the numerator/denominator we are looking for
				auto it = find(arrayelements.begin(), arrayelements.end(), temp);

				//going to do a if statement cheking if its not at the end of the array(elements), keep checking
				if (it != arrayelements.end()) {
					char choice = inputChar("\tInsert (B-before) or (A-after) the existing element: ", static_cast<string>("BA"));
					switch (choice) {
					case 'B': {
						//going to insert at that position before
						arrayelements.insert(it, element);
						cout << "\n\t" << element << " will be inserted before the existing element from the list.\n";
					}
							break;
					case 'A': {
						arrayelements.insert(++it, element);
						cout << "\n\t" << element << " will be inserted after the existing element from the list.\n";
					}
							break;
					}
				}
				//else if the numerator/donominator not found then run this
				else {
					cout << "\n\t" << temp << " cannot be found from the list.\n";
				}
			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 3: {
			//check if list is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tDelete operation cannot be performed on an empty list.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			cout << "\n\tInput a Rational number to be removed...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));

				//going to find the position we are loooking, first getting the range from beginning to end
				//3rd argu has the numerator/denominator we are looking for
				auto it = find(arrayelements.begin(), arrayelements.end(), element);

				//going to do a if statement cheking if its not at the end of the array(elements), keep checking
				if (it != arrayelements.end()) {
					char option = inputChar("\tDo you want to remove (O-one or A-all) element(s): ", static_cast<string>("OA"));
					switch (option) {
					case 'O': {
						//going to erase an element
						arrayelements.erase(it);
						cout << "\n\t" << element << " will be removed from the list.\n";
					}
							break;
					case 'A': {
						//keep track how many there is 
						int count = 0;
						//getting the begin() to the end(), do a if statement to check if the it is equal to the element equals, if equal then erase it
						for (auto it = arrayelements.begin(); it != arrayelements.end();) {
							//if the it is equal to the element, run this
							if (*it == element) {
								it = arrayelements.erase(it);
								count++;
							}
							else {
								++it;
							}
						}
						cout << "\n\t" << element << " will be removed from the list.\n";
					}
							break;
					}
				}
				//else if the numerator/donominator not found then run this
				else {
					cout << "\n\t" << element << " cannot be found from the list.\n";
				}
			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot add a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 4: {
			//check if list is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tSort operation cannot be performed on an empty list.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//going to be sorting the elements, using the sort()
			arrayelements.sort();
			cout << "\n\tThe list has been sorted\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 5: {
			//check if list is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tClear operation cannot be performed on an empty list.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//clearing the list so it can be empty
			arrayelements.clear();
			cout << "\n\tThe list has been cleared of all element(s).\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 0: {
			return;
		}
		}

	} while (true);

}

//precondition: going to call the Rational class header
//postcondition: going to be doing 3 cases that push, top, and pop using a stack(using the include stack)
void challengeS()
{
	system("cls");
	Rational element;
	stack<Rational>arrayelements;
	//going to be used so it can get the original elements
	stack<Rational>temporary;
	int option;

	do {
		beginning:
		system("cls");
		//displaying the information of list
		displayStackMenu();
		if (arrayelements.empty()) {
			cout << "\n\tThe current list is empty\n\n\n";
		}
		else {
			cout << endl;
			temporary = arrayelements;
			//check if the size is at element 0, if it is then theres only one element
			if (arrayelements.size() - 1 == 0) {
				cout << "\tThe current stack contains " << arrayelements.size() << " element:\n\t ";
				cout << "top->";
				while (!temporary.empty()) {
					cout << " " << temporary.top();
					temporary.pop();
				}
			}
			//else there are many element(s)
			else {
				cout << "\tThe current stack contains " << arrayelements.size() << " elements:\n\t ";
				cout << "top->";
				while (!temporary.empty()) {
					cout << " " << temporary.top();
					temporary.pop();
				}
			}
		}
		cout << "\n\n\tStack Menu Options\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t1. Push\n";
		cout << "\t2. Top\n";
		cout << "\t3. Pop\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t0. Return to menu\n";
		cout << "\t" << string(85, char(205)) << "\n";
		option = inputInteger("\tOption: ", 0, 3);

		switch (option) {
		case 1: {
			cout << "\n\tInput a Rational number to be pushed...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
				//pushing back, meaning goes to the front
				arrayelements.push(element);
				cout << "\n\t" << element << " will be pushed onto the stack.\n";
			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot push a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 2: {
			//check if stack is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tNo top element can be retrieved from an empty stack.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//going to retreive the top
			cout <<"\n\t"<< arrayelements.top() << " is at the top of the stack.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 3: {
			//check if stack is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tNo pop operation can be performed from an empty stack.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//pop the element
			arrayelements.pop();
			cout << "\n\t" << element << " will be popped from the stack.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 0: {
			return;
		}
		}
	} while (true);

}

//precondition: going to call the Rational class header
//postcondition: going to do 4 cases that gets the enqueue, front, back, and dequeue
void challengeQ()
{
	system("cls");
	Rational element;
	queue<Rational>arrayelements;
	//going to be used so it can get the original elements
	queue<Rational>temporary;
	int option;

	do {
		beginning:
		system("cls");
		//displaying the information of list
		displayQueueMenu();
		if (arrayelements.empty()) {
			cout << "\n\tThe current queue is empty\n\n\n";
		}
		else {
			cout << endl;
			temporary = arrayelements;
			//check if the size is at element 0, if it is then theres only one element
			if (arrayelements.size() - 1 == 0) {
				cout << "\tThe current queue contains " << arrayelements.size() << " element:\n\t ";
				cout << "front-> ";
				while (!temporary.empty()) {
					cout << temporary.front() << " ";
					temporary.pop();
				}
				cout << "<-back";
			}
			else {
				cout << "\tThe current queue contains " << arrayelements.size() << " elements:\n\t ";
				cout << "front-> ";
				while (!temporary.empty()) {
					cout << temporary.front() << " ";
					temporary.pop();
				}
				cout << "<-back";
			}
		}
		cout << "\n\n\tQueue Menu Options\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t1. Enqueue (push in from the back)\n";
		cout << "\t2. Front\n";
		cout << "\t3. Back\n";
		cout << "\t4. Dequeue (pop from the front)\n";
		cout << "\t" << string(85, char(205)) << "\n";
		cout << "\t0. Return to menu\n";
		cout << "\t" << string(85, char(205)) << "\n";
		option = inputInteger("\tOption: ", 0, 4);

		switch (option) {
		case 1: {
			cout << "\n\tInput a Rational number to be enqueued...\n";
			try {
				element.setNumerator(inputInteger("\tEnter a numerator(-9...9): ", -9, 9));
				element.setDenominator(inputInteger("\tEnter a denominator(-9...9): ", -9, 9));
				//pushing back, meaning goes to the front
				arrayelements.push(element);
				cout << "\n\t" << element << " will be enqueued (pushed) onto the queue.\n";
			}
			catch (Rational::ZeroDenominator) {
				cout << "\n\tEXCEPTIONAL ERROR: Cannot enqueue a Rational number, " << element << ", with a zero denominator value.\n";
			}
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 2: {
			//check if queue is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tNo front element can be retrieved from an empty stack.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//going to retreive the front
			cout << "\n\t" << arrayelements.front() << " is at the front of the stack.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 3: {
			//check if queue is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tNo back element can be retrieved from an empty stack.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//going to retreive the top
			cout << "\n\t" << arrayelements.back() << " is at the back of the stack.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 4: {
			//check if queue is empty, if empty, send a warning
			if (arrayelements.empty()) {
				cout << "\n\tNo dequeue (pop) operation can be performed on an empty stack.\n\n";
				system("pause");
				system("cls");
				goto beginning;
			}
			//going to show the front display
			element = arrayelements.front();
			//pop the element
			arrayelements.pop();
			cout << "\n\t" << element << " will be dequeued (popped) from the stack.\n";
			cout << endl;
			system("pause");
			system("cls");
		}
			  break;
		case 0: {
			return;
		}
		}
	} while (true);
}

//precondition: going to create a void function
//postcondition: going to create a menu display that shows me vecotr, linked list, stack, and queue
void displayMenu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 7); cout << " " << endl;
	SetConsoleTextAttribute(h, 11); cout << "\t\t\t\t\t\t\t\t    " << string(1, char(186)) << " in/out " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)) << "   in   " << string(1, char(186)) << endl;

	SetConsoleTextAttribute(h, 11); cout << "\t\t\t\t\t\t\t\t    " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186)) << endl;

	SetConsoleTextAttribute(h, 11); cout << "\t\t\t\t\t\t\t\ttop" << string(1, char(175)) << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(179)) << " 1/2" << string(1, char(179)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t      rear" << string(1, char(175)) << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(179)) << " 5/6" << string(1, char(179)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186)) << endl;

	SetConsoleTextAttribute(h, 11); cout << "\t\t\t\t\t\t\t\t    " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186)) << endl;

	SetConsoleTextAttribute(h, 7); cout << " \t" << string(1, char(218)) << string(4, char(196)) << string(1, char(194)) << string(4, char(196)) << string(1, char(194)) << string(4, char(196)) << string(1, char(191));
	SetConsoleTextAttribute(h, 7); cout << "\t" << "  " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)) << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191)) << " " << string(1, char(218)) << string(4, char(196)) << string(1, char(191));
	SetConsoleTextAttribute(h, 11); cout << "\t\t    " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(179)) << " 3/4" << string(1, char(179)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(179)) << " 3/4" << string(1, char(179)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186));

	SetConsoleTextAttribute(h, 7); cout << "\n\t" << string(1, char(179)) << " 1/2" << string(1, char(179)) << " 3/4" << string(1, char(179)) << " 5/6" << string(1, char(179));
	SetConsoleTextAttribute(h, 14); cout << "\t" << string(1, char(218)) << string(1, char(175)); SetConsoleTextAttribute(h, 7); cout << string(1, char(179)) << " 1/2" << string(1, char(179)); SetConsoleTextAttribute(h, 14); cout << string(1, char(175)); SetConsoleTextAttribute(h, 7); cout << string(1, char(179)) << " 3/4" << string(1, char(179)); SetConsoleTextAttribute(h, 14); cout << string(1, char(175)); SetConsoleTextAttribute(h, 7); cout << string(1, char(179)) << " 5/6" << string(1, char(179));
	SetConsoleTextAttribute(h, 11); cout << "\t\t    " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(195)) << string(4, char(196)) << string(1, char(180)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186));

	SetConsoleTextAttribute(h, 7); cout << "\n\t" << string(1, char(192)) << string(4, char(196)) << string(1, char(193)) << string(4, char(196)) << string(1, char(193)) << string(4, char(196)) << string(1, char(217));
	SetConsoleTextAttribute(h, 7); cout << "\t" << string(1, char(179)) << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)) << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)) << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217));
	SetConsoleTextAttribute(h, 11); cout << "\t\t    " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(179)) << " 5/6" << string(1, char(179)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t     front" << string(1, char(175)) << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(179)) << " 1/2" << string(1, char(179)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186));

	SetConsoleTextAttribute(h, 12); cout << "\n\t0    1    2"; SetConsoleTextAttribute(h, 14); cout << "\t\thead";
	SetConsoleTextAttribute(h, 11); cout << "\t\t\t\t    " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)); SetConsoleTextAttribute(h, 11); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)); SetConsoleTextAttribute(h, 7); cout << " " << string(1, char(192)) << string(4, char(196)) << string(1, char(217)); SetConsoleTextAttribute(h, 10); cout << " " << string(1, char(186));
	SetConsoleTextAttribute(h, 12); cout << "\n\t(index)"; SetConsoleTextAttribute(h, 14); cout << "\t\t\t(pointer)"; SetConsoleTextAttribute(h, 11); cout << "\t\t\t    " << string(1, char(200)) << string(8, char(205)) << string(1, char(188));	SetConsoleTextAttribute(h, 10); cout << "\t\t   " << string(1, char(186)) << "  out   " << string(1, char(186)) << endl;
	SetConsoleTextAttribute(h, 12); cout << "\n\tVector (list arrray)";  SetConsoleTextAttribute(h, 14); cout << "\t    Linked List"; SetConsoleTextAttribute(h, 11); cout << "\t\t\t       Stack"; SetConsoleTextAttribute(h, 10); cout << "\t\t     Queue" << endl;
	SetConsoleTextAttribute(h, 7);
	cout << "\n\tA container is a holder object that stores a collection of other objects (its elements). They";
	cout << "\n\tare implemented as class templates, which allows great flexibility in the types supported as";
	cout << "\n\telements. The container manages the storage space for its elementsand provides member functions";
	cout << "\n\tto access them, either directly or through iterators(reference objects with similar properties";
	cout << "\n\tto pointers).\n";

}

//precondition: going to create a void function
//postcondition: going to then create a menu display that shows the vector information, using color
void displayVectorMenu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 12); cout <<"\tVectors are same as dynamic arrays with the ability to resize itself automatically when an\n" <<
		"\t" << "element is inserted or deleted, with their storage being handled automatically by the container.\n" <<
		"\t" << "Vector elements are placed in  contiguous storage so that they can be accessed and traversed\n" <<
		"\t" << "using iterators or indexes.\n";
	SetConsoleTextAttribute(h, 15); cout;
}

//precondition: going to create a void functiton
//postcondition: going to then create a menu display that shows the list information, using the color
void displayListMenu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 13); cout << "\tLists are sequence containers that allow non-contiguous memory allocation. As compared to\n" <<
		"\t" << "vector, the list has slow traversal, but once a position has been found, insertion and\n" <<
		"\t" << "deletion are quicker.\n";
	SetConsoleTextAttribute(h, 15); cout;
}

//precondition: going to create a void functiton
//postcondition: going to then create a menu display that shows the list information, using the color
void displayStackMenu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 11); cout << "\tStacks are a type of container adaptors with LIFO(Last In First Out) type of working, where\n" <<
		"\t" << "a new element is added(push) at one end(top) and an element is removed(pop) from that end\n" <<
		"\t" << "only. Stack uses an encapsualted object of either vector or deque(by default) or list (sequential\n" <<
		"\t" << "container class) as its underlying container,providing a specific set of member functions to\n" <<
		"\t" << "access its elements.\n";
	SetConsoleTextAttribute(h, 15); cout;
}

//precondition: going to create a void function
//postcondition: going to then create a menu display that shows the list information, using the color
void displayQueueMenu()
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(h, 10); cout << "\tQueues are a type of container adaptors that operate in a first in first out (FIFO) type of\n" <<
		"\t" << "arrangement. Elements are inserted(enqueued) at the back and are deleted (dequeued) from the\n" <<
		"\t" << "front. Queues use an encapsulated object of deque or list(sequential container class) as its\n" <<
		"\t" << "underlying container, providing a specific set of member functions to access elements.\n";
	SetConsoleTextAttribute(h, 15); cout;
}
