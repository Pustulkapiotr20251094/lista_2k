#pragma once
#include <cstddef>
#include<iostream>





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

	void pushBack(int value);//dodaj  na konic
	void pushFront(int value);//dodaj  na poczatek 
	void displayForward() const;//pokazuj od poczatku





	//diagnostyka
	std::size_t size() const { return sz; };

	bool empy() const { return sz == 0; }
};
