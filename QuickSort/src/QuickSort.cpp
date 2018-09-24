//============================================================================
// Name        : QuickSort.cpp
// Author      : Muruganand
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int partition(unsigned int ar[], int start, int end)
{
	int pIndex = start, i = 0;
	unsigned int pivot = ar[end];

	for (i=start; i<=end-1; ++i)
	{
		if (ar[i] <= pivot)
		{
			swap(ar[i], ar[pIndex]);
			pIndex++;
		}
	}
	swap(ar[pIndex], ar[end]);

	return pIndex;
}

void quicksort(unsigned int ar[], int start, int end)
{
	int pIndex = 0;

	if (start < end) {
		pIndex = partition(ar, start, end);
		quicksort(ar, start, pIndex-1);
		quicksort(ar, pIndex+1, end);
	}
}

int main()
{
	int index = 0;
	unsigned int ar[9] = {2,6,4,7,3,1,5,9,8};

	for (index=0; index<9; index++)
	{
		cout << ar[index] << " ";
	}
	cout << endl;

	quicksort(ar, 0, 8);

	for (index=0; index<9; index++)
	{
		cout << ar[index] << " ";
	}
	cout << endl;

	return 0;
}
