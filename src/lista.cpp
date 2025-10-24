#include "lista.h" 
#include <stdexcept> 



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


void lista::pushFront(int value)//dodawanie lelmentu na początek listy
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

	std::cout << "Zawartość listy : ";

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
	std::cout << "Zawartość listy (od końca): ";
	while (current) {
		std::cout << current->data << " ";
		current = current->prev;
	}
	std::cout << "\n";
}



void lista::insertAt(int index, int value) {
	if (index < 0 || index > static_cast<int>(sz)) {
		throw std::out_of_range("Niepoprawny indeks");
	}

	if (index == 0) {
		pushFront(value);
		return;
	}
	else if (index == static_cast<int>(sz)) {
		pushBack(value);
		return;
	}

	Node* newNode = new Node(value);
	Node* current = head;

	for (int i = 0; i < index - 1; ++i) {
		current = current->next;
	}

	newNode->next = current->next;
	newNode->prev = current;
	current->next->prev = newNode;
	current->next = newNode;

	sz++;
}

// ✅ Usuń element spod wskazanego indeksu
void lista::removeAt(int index) {
	if (index < 0 || index >= static_cast<int>(sz)) {
		throw std::out_of_range("Niepoprawny indeks");
	}

	if (index == 0) {
		popFront();
		return;
	}
	else if (index == static_cast<int>(sz) - 1) {
		popBack();
		return;
	}

	Node* current = head;
	for (int i = 0; i < index; ++i) {
		current = current->next;
	}

	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;

	sz--;
}




