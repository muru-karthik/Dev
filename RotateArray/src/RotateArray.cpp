//============================================================================
// Name        : RotateArray.cpp
// Author      : Muruganand K
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int find_min(int ar[], int lo, int hi)
{
	int _lo = lo, _hi = hi;
	int mid = 0;

	if (ar[lo] <= ar[hi]) {
		return ar[lo];
	}

	while (_lo < _hi) {
		mid = _lo + ((_hi - _lo)/2);

		if (ar[_lo] >= ar[mid]) {
			_hi = mid;
		} else if (ar[mid] >= ar[_hi]) {
			_lo = mid;
		}
	}

	cout << "Inflection point: " << mid << endl;
	return ar[mid+1];
}

int main() {

	int ar[] = {2,3,4,5,6,7,8,1};

	cout << find_min(ar, 0, 7);
	return 0;
}
