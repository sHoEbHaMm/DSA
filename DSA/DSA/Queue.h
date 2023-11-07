#pragma once

class Queue
{
private:
	int size;
	int front, rear;
	int* Q;

public:

	Queue()
	{
		size = 10;
		front = rear = -1;
		Q = new int[size];
	}

	Queue(int size)
	{
		this->size = size;
		front = rear = -1;
		Q = new int[this->size];
	}

	void enqueue(int _data);
	int  dequeue();
	void Display();
};

class CircularQueue
{
private:
	int size;
	int front, rear;
	int* Q;

public:

	CircularQueue()
	{
		size = 10;
		front = rear = -1;
		Q = new int[size];
	}

	CircularQueue(int size)
	{
		this->size = size;
		front = rear = -1;
		Q = new int[this->size];
	}

	void Cenqueue(int _data);
	int  Cdequeue();
	void CDisplay();
};