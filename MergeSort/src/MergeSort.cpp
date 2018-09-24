//============================================================================
// Name        : MergeSort.cpp
// Author      : Muruganand
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <array>

using namespace std;

void merge(int ar[], int start, int end)
{
	int* tmpAr = new int[end-start+1]();
	int mid = (end - start)/2;
	int i = start, j = start+mid+1, k = 0;

	while(i <= start+mid && j <= end)
	{
		if (ar[i] <= ar[j])
		{
			tmpAr[k] = ar[i];
			i++;
		}
		else
		{
			tmpAr[k] = ar[j];
			j++;
		}

		k++;
	}

	while (i <= start+mid)
	{
		tmpAr[k++] = ar[i++];
	}

	while (j <= end)
	{
		tmpAr[k++] = ar[j++];
	}

	for (i = start, j = 0; i <= end; ++i, ++j)
	{
		ar[i] = tmpAr[j];
	}

	delete[] tmpAr;
}

void mergesort(int ar[], int start, int end)
{
	int mid = 0;
	if (start < end)
	{
		mid = (end - start)/2;
		mergesort(ar, start, start+mid);
		mergesort(ar, start+mid+1, end);
		merge(ar, start, end);
	}
}

int main() {
	//int ar[] = {5, 4, 7, 2, 1, 3, 8, 9, 6};
	int ar[] = {5, 4, 7, 2, 1, 3, 8, 9, 6, 11, 14, 13, 12, 17, 16, 15};
	int size = 16;

	mergesort(ar, 0, size-1);

	for (int i = 0; i < size; ++i)
	{
		cout << ar[i] << " ";
	}

	cout << endl;
	return 0;
}
