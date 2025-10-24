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
		tail = newNode;

	
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



void lista::popFront() {
	if (!head) return; // lista pusta
	Node* temp = head;
	head = head->next;
	if (head) head->prev = nullptr;
	else tail = nullptr;
	delete temp;
	sz--;
}

void lista::popBack() {
	if (!tail) return; // lista pusta
	Node* temp = tail;
	tail = tail->prev;
	if (tail) tail->next = nullptr;
	else head = nullptr;
	delete temp;
	sz--;
}

void lista::clear() {
	while (!empty()) {
		popFront();
	}
}

void lista::displayBackward() const {
	Node* current = tail;
	std::cout << "Zawartoœæ listy (od koñca): ";
	while (current) {
		std::cout << current->data << " ";
		current = current->prev;
	}
	std::cout << "\n";
}

bool lista::empty() const {
	return sz == 0;
}




