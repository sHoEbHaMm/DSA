#include "CircularLinkedList.h"

void CircularLinkedList::Display(Node* p)
{
	static int flag = 0;
	p = head;

	while (p != head || flag == 0)
	{
		flag = 1;
		printf("%d ", p->data);
		p = p->next;
	}
	flag = 1;
}

void CircularLinkedList::insertNode(int pos, int _data)
{
	Node* p = head;
	Node* newNode = new Node();
	newNode->data = _data;

	if (pos == 0)
	{
		while (p->next != head)
		{
			p = p->next;
		}

		newNode->next = p->next;
		p->next = newNode;
		head = newNode;
	}

	if (pos > 0)
	{
		for (int i = 0; i < pos - 1 && p; i++)
		{
			p = p->next;
		}
		{
			newNode->next = p->next;
			p->next = newNode;
		}
	}
}

void CircularLinkedList::deleteNode(int pos)
{
	Node* p = head;
	Node* q;

	if (pos == 1)
	{
		while (p->next != head)
		{
			p = p->next;
		}
		p->next = head->next;
		delete head;
		head = p->next;
	}
	else
	{
		for (int i = 0; i < pos - 2 && p; i++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

int main()
{
	int arr[5] = { 23, 27, 28, 31, 34 };
	CircularLinkedList cLinkedList(arr, 5);
	Node* p = NULL;
	cLinkedList.insertNode(5, 10);
	cLinkedList.Display(p);
}