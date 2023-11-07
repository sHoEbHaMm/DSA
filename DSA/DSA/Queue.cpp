#include "Queue.h"
#include<iostream>

void Queue::enqueue(int _data)
{
	if (this->rear == this->size - 1)
	{
		std::cout << "Queue full\n";
		return;
	}

	this->rear++;
	this->Q[this->rear] = _data;
}

int Queue::dequeue()
{
	int x = -1;

	if (this->rear == this->front)
	{
		std::cout << "Queue empty\n";
		return x;
	}
	this->front++;
	x = this->Q[this->front];

	return x;
}

void Queue::Display()
{
	if (this->rear == this->front)
	{
		std::cout << "Queue empty\n";
		return;
	}

	for (int i = this->front + 1; i < this->size; i++)
	{
		std::cout << this->Q[i] << " ";
	}
}


void CircularQueue::Cenqueue(int _data)
{
	if ((this->rear + 1)%this->size == this->front)
	{
		std::cout << "Queue full\n";
		return;
	}

	this->rear = (this->rear + 1) % this->size;
	this->Q[this->rear] = _data;
}

int CircularQueue::Cdequeue()
{
	int x = -1;

	if (this->rear == this->front)
	{
		std::cout << "Queue empty\n";
		return x;
	}
	this->front = (this->front+1) % this->size;
	x = this->Q[this->front];

	return x;
}

void CircularQueue::CDisplay()
{

}


int main()
{
	Queue q(5);

	q.Display();
}