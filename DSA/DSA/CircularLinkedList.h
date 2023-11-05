#pragma once
#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

class CircularLinkedList
{
private:
	Node* head;

public:
	CircularLinkedList()
	{
		head = nullptr;
	}

	CircularLinkedList(int arr[], int size)
	{
		Node* newNode, *last;

		head = new Node();
		head->data = arr[0];
		head->next = head;
		last = head;

		for (int i = 1; i < size; i++)
		{
			newNode = new Node();
			newNode->data = arr[i];
			last->next = newNode;
			newNode->next = head;
			last = newNode;
		}
	}

	void Display(Node* p);
	void insertNode(int pos, int _data);
	void deleteNode(int pos);

};
