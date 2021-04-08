// Find 2 minimums in array with one for

#include <iostream>
using namespace std;

int main() { 
	int arr[6] = {4, 9, 8, 5, 7, 1}; 
	
	int min1,min2;
	min1 = arr[0];
	min2 = arr[0];

    for(int i = 0;i < 6;i++) {
        if(min1 > arr[i]) {
            min2 = min1;
            min1 = arr[i];
		}
	}

	cout << min1 << endl << min2 << endl;
}