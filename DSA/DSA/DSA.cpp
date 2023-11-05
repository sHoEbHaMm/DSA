// DSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "CircularLinkedList.h"
#include <vector>

struct Node
{
    int data;
    struct Node* next;
}*head = NULL, *last = NULL;

Node* createLinkedList(int arr[], int size)
{
    Node *temp;
    head = new Node();

    head->data = arr[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < size; i++)
    {
        temp = new Node();
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }

    return head;
}

void DisplayLL(Node* head)
{
    Node* p = head;

    while (p != 0)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void LengthLL(Node* head)
{
    Node* p = head;
    int count = 0;

    while (p != 0)
    {
        count++;
        p = p->next;
    }

    printf("\nLength of linkedlist: %d", count);
}

Node* search(Node* p, int key) //Linear search with move to head modifier to make it less expensive
{
    Node* trailingPtr = NULL;

    while (p != 0)
    {
        if (p->data == key)
        {
            trailingPtr->next = p->next; //move to head modifier block, pehle jodo fir todo
            p->next = head;
            head = p;
            return p;
        }
        trailingPtr = p;
        p = p->next;
        
    }
    return nullptr;
}

void insertNode(int pos, int _data)
{
    if (pos == 0) //if node is to be inserted at first position of the linkedlist
    {
        Node *newNode = new Node();
        newNode->data = _data;
        newNode->next = head;
        head = newNode;
    }
    else if (pos > 0) //if node is to be inserted after the given pos
    {
        Node* newNode = new Node();
        newNode->data = _data;
        Node* temp = head;

        /*
        * The temp check in for loop is to make sure the pos user has given is within the length of LL
        * if user asks to enter node after 10 pos, temp will end up as NULL which we do not want
        * 
        * For loop - brings the temp pointer at a postion after which new node is to be inserted
        */

        for (int i = 0; i < pos - 1 && temp; i++)
        {
            temp = temp->next;
        }

        if (temp)
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

void insertNodeAtLast(int _data)
{
    Node* newNode = new Node();
    newNode->data = _data;

    if (head == 0) //this means LL is empty
    {
        head = last = newNode;
    }
    else
    {
        newNode->next = NULL;
        last->next = newNode;
        last = newNode;
    }
}

void insertNodeInSortedLL(int _data)
{
    Node* trailingPtr = NULL;
    Node* p = head;

    /*
    * while loop - finds a node p whose data is greater than newNode's desired data (_data)
    */
    while (p && p->data < _data)
    {
        trailingPtr = p;
        p = p->next;
    }

    if (trailingPtr)
    {
        Node* newNode = new Node();
        newNode->data = _data;
        newNode->next = trailingPtr->next;
        trailingPtr->next = newNode;
    }
}

void deleteNode(int pos)
{
    if (head == 0)
    {
        printf("Linked list empty!");
    }

    //first node
    if (pos == 1)
    {
        Node* p = head;
        head = p->next;
        delete p;
    }

    //any node at pos
    if (pos > 1)
    {
        Node* p = head;
        Node* trailingPtr = NULL;

        for (int i = 0; i < pos - 1 && p; i++)
        {
            trailingPtr = p;
            p = p->next;
        }

        if (trailingPtr && p)
        {
            trailingPtr->next = p->next;
            delete p;
        }
    }

}

bool isLLSorted(Node* p)
{
    while (p->next != 0)
    {
        if (p->data > p->next->data)
            return false;
        p = p->next;
    }
    return true;
}

void deleteDuplicates()
{
    Node* p = head;
    Node* q = p->next;

    while (q != 0)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}

void reverseLL()
{
    int op[5] = {0};
    Node* p = head;
    int i = 0;

    if (head == 0)
    {
        printf("Linked list is empty");
    }

    //copy elements from list to array
    while (p != 0)
    {
        op[i] = p->data;
        p = p->next;
        i++;
    }

    p = head;
    i--;

    //copy elements from array to list in reverse order
    while (p != NULL)
    {
        p->data = op[i];
        p = p->next;
        i--;
    }
}

void reverseLLUsingSlidingPtr()
{
    Node* p = head;
    Node* q = NULL;
    Node* r = NULL;

    while (p != 0)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void mergingTwoLL(Node* headOfFirst, Node* headofSecond)
{
/*
* We need two more pointers, Node* headofMerged, *lastOfMerged
* Compare data of both nodes, the one smaller add to the mergedLL and make tht nodes next null
* Keep doing until one of the list gets exhausted, copy remaining elements
*/

    Node* headofMerged = NULL;
    Node* lastofMerged = NULL;

    if (headOfFirst->data < headofSecond->data)
    {
        headofMerged = lastofMerged = headOfFirst;
        headOfFirst = headOfFirst->next;
        lastofMerged->next = NULL;
    }
    else
    {
        headofMerged = lastofMerged = headofSecond;
        headofSecond = headofSecond->next;
        lastofMerged->next = NULL;
    }

    while (headOfFirst != 0 && headofSecond != 0)
    {
        if (headOfFirst->data < headofSecond->data)
        {
            lastofMerged->next = headOfFirst;
            lastofMerged = headOfFirst;
            headOfFirst = headOfFirst->next;
            lastofMerged->next = NULL;
        }
        else
        {
            lastofMerged->next = headofSecond;
            lastofMerged = headofSecond;
            headofSecond = headofSecond->next;
            lastofMerged->next = NULL;
        }
    }

    if(headOfFirst != 0)
    {
        lastofMerged->next = headOfFirst;
    }

    if(headofSecond != 0)
    {
        lastofMerged->next = headofSecond;
    }

    DisplayLL(headofMerged);
}

//int main()
//{
//
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
