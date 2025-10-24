#include "lista.h" 




lista::lista() : head(nullptr), tail(nullptr), sz(0) {}


lista::~lista() {
	Node* current = head;
	while (current) {
		Node* next = current->next;
		delete current;
		current = next;

	
	}

	head = tail = nullptr;
	sz = 0;


}



void lista::pushBack(int value)//dodawanie elementu na konic listy
{
	Node* newNode = new Node(value);
	if (!head)
	{
		head = tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;

	
	}

	sz++;


}


void lista::pushFront(int value)//dodawanie lelmentu na pocz¹tek listy
{
	Node* newNode = new Node(value);
	if (!head)
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;

	}

	sz++;

}



void lista::displayForward() const
{
	Node* current = head;

	std::cout << "Zawartoœæ listy : ";

	while(current)
	{ 
		std::cout << current->data << " ";
		current = current->next;
	
	
	}

	std::cout << "\n";


}



