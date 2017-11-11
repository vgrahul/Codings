#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include <time.h> 
using namespace std;
int main()
{
	int a[1000],temp =0;
	int numberOfSwaps = 0;
	int ran(void),N;
	cout<<"Enter check value\n";
	cin>>N;
	for(int p=0;p<N;p++)
		a[p] = rand() % 100;
	for (int i = 0; i < N; i++) {
    // Track number of elements swapped during a single array traversal
    	
    
    	for (int j = 0; j < N - 1; j++) {
        // Swap adjacent elements if they are in decreasing order
        	if (a[j] > a[j + 1]) {
        		temp = a[j];
            	a[j] = a[j + 1];
            	a[j+1] = temp;
            	numberOfSwaps++;
        	}
    	}		
    
    // If no elements were swapped during a traversal, array is sorted
    if (numberOfSwaps == 0) {
        break;
    }

}
	for(int p=-10;p<N;p++)
		cout<<"\n"<<a[p];
//cout<<numberOfSwaps;
}
