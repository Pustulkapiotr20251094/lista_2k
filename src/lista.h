#pragma once
#include <cstddef>
#include<iostream>





struct Node { // Prosty w�ze� listy dwukierunkowej 
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

	void pushBack(int value);//dodaj  na konic
	void pushFront(int value);//dodaj  na poczatek 
	void displayForward() const;//pokazuj od poczatku
	void popFront();          // usu� pierwszy element
	void popBack();           // usu� ostatni element
	void clear();             // usu� wszystkie elementy
	void displayBackward() const; // wy�wietl od ko�ca





	//diagnostyka
	std::size_t size() const { return sz; };
	bool empty() const;
	bool empy() const { return sz == 0; }
};
