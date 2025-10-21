#pragma once
#include <cstddef>



// Szkielet pliku nag³ówkowego listy dwukierunkowej.


struct Node { // Prosty wêze³ listy dwukierunkowej 
	int data;
	Node* prev;
	Node* next;
	explicit Node(int value) : data(value), prev(nullptr), next(nullptr) {}


};


class lista // klasa listy
{
private:
	Node* head;
	Node* tail;
	std::size_t sz;



public:
	lista();
	~lista();


	//diagnostyka
	std::size_t size() const { return sz; };

	bool empy() const { return sz == 0; }
};
