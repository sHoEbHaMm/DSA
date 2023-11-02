#pragma once

int linearSearch(int arr[], int key, int size);
int binarySearch(int arr[], int low, int high, int key, int size);
int* reverseArray(int arr[], int size);
bool isArraySorted(int arr[], int size);
int* arrangeArray(int arr[], int size);
int* mergeArrays(int arr[], int size1, int arr2[], int size2);
void findSingleMissingElement(int arr[], int size);
void findMultipleMissingElements(int arr[], int size);
void pairOfElementsWithSumUnsortedArray(int arr[], int size, int sum);
void pairOfElementsWithSumSortedArray(int arr[], int size, int sum);

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

int* mergeArrays(int arr[], int size1, int arr2[], int size2)
{
	int* mergedArray = new int[20];

	int i = 0, j = 0, k = 0;

	while (i < size1 && j < size2)
	{
		if (arr[i] > arr2[j])
		{
			mergedArray[k++] = arr2[j++];
		}
		else if (arr[i] < arr2[j])
		{
			mergedArray[k++] = arr[i++];			//i++ will assign then increment
		}
	}

	for (; i < size1; i++)
	{
		mergedArray[k++] = arr[i];
	}

	for (; j < size2; j++)
	{
		mergedArray[k++] = arr2[j];
	}

	return mergedArray;
}

void findSingleMissingElement(int arr[], int size)
{
	int difference = arr[0] - 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] - i != difference)
		{
			std::cout << "Missing element: " << i + difference << std::endl;
			return;
		}
	}
}

void findMultipleMissingElements(int arr[], int size)
{
	int difference = arr[0] - 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] - i != difference)
		{
			while (difference < arr[i] - i)
			{
				std::cout << i + difference << std::endl;
				difference++;
			}
		}
	}
}

void findDuplicatesSortedArray(int arr[], int size)
{
	int lastDuplicate = 0;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
		{
			lastDuplicate = arr[i];
			std::cout << arr[i] << " ";
		}
	}
}

void findDuplicatesUnsortedArray(int arr[], int size)
{
	int count;

	for (int i = 0; i < size; i++)
	{
		count = 1;
		if (arr[i] != -1)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] == arr[j] && arr[i] != -1)
				{
					count++;
					arr[j] = -1;
				}
			}
			if (count > 1)
				printf("%d occurs %d times\n", arr[i], count);
		}

	}
}

void pairOfElementsWithSumUnsortedArray(int arr[], int size, int sum)
{
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				printf("%d %d are a pair\n", arr[i], arr[j]);
			}
		}
	}
}

void pairOfElementsWithSumSortedArray(int arr[], int size, int sum)
{
	int i = 0, j = size - 1;
	while (i < j)
	{
		if (arr[i] + arr[j] == sum)
		{
			printf("%d %d is a pair\n", arr[i], arr[j]);
			i++;
			j--;
		}
		else if (arr[i] + arr[j] > sum)
		{
			j--;
		}
		else
		{
			i++;
		}
	}
}