/* C++ Program to Implement Circular Doubly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

/*
 * Class Declaration
 */
class DoubleCircularList
{
public:
	int counter = 0;

	/*
	 * Node Declaration
	 */
	struct node {
		int info;
		struct node* next;
		struct node* prev;
	}*start, * last;

	DoubleCircularList() {
		start = NULL;
		last = NULL;
	}

	/*
	 *CREATE NODE AND ALLOCATE MEMORY DYNAMICALLY
	 */
	node* createNode(int value) {
		struct node* temp = new node();
		temp->info = value;
		return temp;
	}
	/*
	 *INSERTS ELEMENT AT BEGINNING
	 */
	void insertAtStart() {
		int value;
		cout << endl << "Enter the element to be inserted: ";
		cin >> value;
		node* temp = createNode(value);
		if (start == last && start == NULL) {
			temp->next = temp;
			temp->prev = temp;
			start = temp;
			last = temp;
		}
		else {
			start->prev = temp;
			last->next = temp;
			temp->next = start;
			temp->prev = last;
			start = temp;
		}
		counter++;
	}

	/*
	 *INSERTS ELEMNET AT LAST
	 */
	void insertLast() {
		int value;
		cout << endl << "Enter the element to be inserted: ";
		cin >> value;
		node* temp = createNode(value);
		if (start == last && start == NULL) {
			temp->next = temp;
			temp->prev = temp;
			start = temp;
			last = temp;
		}
		else {
			start->prev = temp;
			last->next = temp;
			temp->next = start;
			temp->prev = last;
			last = temp;
		}
		counter++;
	}
	/*
	 *INSERTS ELEMENT AT POSITION
	 */
	void insertAtPos() {
		int value, pos, i;
		cout << endl << "Enter the element to be inserted: ";
		cin >> value;
		cout << endl << "Enter the postion of element inserted: ";
		cin >> pos;

		node* temp = createNode(value);
		node* ptr = start;



		if (start == last && start == NULL) {
			temp->next = temp;
			temp->prev = temp;
			start = temp;
			last = temp;
		}
		else {
			for (i = 1; i < pos; i++) {
				ptr = ptr->next;
			}
			temp->prev = ptr->prev;
			temp->next = ptr;
			ptr->prev->next = temp;
			ptr->prev = temp;
		}
		if (pos == 1) {
			start = temp;
		}
		else if (temp->prev == last) {
			last = temp;
		}
		counter++;
	}
	/*
	 * Delete Node at Particular Position
	 */
	void deleteAtPos()
	{
		int pos, i;
		node* ptr;
		if (start == last && start == NULL)
		{
			cout << "List is empty, nothing to delete" << endl;
			return;
		}
		cout << endl << "Enter the postion of element to be deleted: ";
		cin >> pos;

		ptr = start;

		if (start == last) {
			start = last = NULL;
			free(ptr);
			counter--;
			return;
		}

		for (i = 1; i < pos; i++) {
			ptr = ptr->next;
		}
		if (ptr == start) {
			start = ptr->next;
		}
		else if (ptr == last) {
			last = ptr->prev;
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
		counter--;

	}
	/*
	 * Display Elements of the List
	 */
	void display() {
		if (start == last && start == NULL) {
			cout << "The List is empty, nothing to display" << endl;
			return;
		}
		node* temp = start;
		for (int i = 1; i < counter; i++) {
			cout << temp->info << "<->";
			temp = temp->next;
		}
		cout << temp->info << endl;
	}

};

/*
 * Main: Contains Menu
 */
int main() {
	int userChoice;
	DoubleCircularList cdl;
	while (1) {
		cout << "\n-------------------------------" << endl;
		cout << "Operations on Doubly Circular linked list" << endl;
		cout << "\n-------------------------------" << endl;
		cout << "1.Insert at Beginning" << endl;
		cout << "2.Insert at Last" << endl;
		cout << "3.Insert at Specific Position" << endl;
		cout << "4.Delete at Specific Position" << endl;
		cout << "5.Display List" << endl;
		cout << "6.Exit" << endl;
		cout << "Enter your choice : ";
		cin >> userChoice;
		switch (userChoice) {
		case 1:
			cdl.insertAtStart();
			break;
		case 2:
			cdl.insertLast();
			break;
		case 3:
			cdl.insertAtPos();
			break;
		case 4:
			cdl.deleteAtPos();
			break;
		case 5:
			cdl.display();
			break;
		case 6:
			exit(1);
		default:
			cout << "Wrong choice" << endl;
		}
	}
	return 0;
}

