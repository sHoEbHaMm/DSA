#pragma once

int linearSearch(int arr[], int key, int size);
int binarySearch(int arr[], int low, int high, int key, int size);
void reverseArray(int arr[]);
bool isArraySorted(int arr[], int size);
void arrangeArray(int arr[]);

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

void reverseArray(int arr[])
{

}

bool isArraySorted(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return true;
	}
	return false;
}

void arrangeArray(int arr[])
{

}