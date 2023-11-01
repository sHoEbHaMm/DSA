#pragma once

int linearSearch(int arr[], int key, int size);
int binarySearch(int arr[], int low, int high, int key, int size);
int* reverseArray(int arr[], int size);
bool isArraySorted(int arr[], int size);
int* arrangeArray(int arr[], int size);

int linearSearch(int arr[], int key, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == key)
			return 1;
	}
	return -1;
}

int binarySearch(int arr[], int low, int high, int key, int size)
{
	int mid = floor((low + high) / 2);

	if (arr[mid] == key)
		return mid;

	if (arr[mid] > key)
	{
		high = mid - 1;
		return binarySearch(arr, low, high, key, size);
	}
	else if (arr[mid] < key)
	{
		low = mid + 1;
		return binarySearch(arr, low, high, key, size);
	}
	else
	{
		return -1;
	}
}

int* reverseArray(int arr[], int size)
{
	int* op = new int[size];
	int i, j;

	for (i = size - 1, j = 0; i >= 0; i--, j++)
	{
		op[j] = arr[i];
	}
	return op;
}

bool isArraySorted(int arr[], int size) //checks if array is sorted in ascending order
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return true;
	}
	return false;
}

int* arrangeArray(int arr[], int size) //shifts all the negative elements to the left and positve elements to the right
{
	int i = 0;
	int j = size - 1;
	int temp;

	while (i < j)
	{
		while (arr[j] < 0) { j--; }
		while (arr[i] >= 0) { i++; }

		if (i < j)
		{
			//swap
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	return arr;
}