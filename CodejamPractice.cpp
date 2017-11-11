#include<iostream>
#include<conio.h>
#include<time.h>
using namespace std;
int main()
{
	//getting all inputs
	clock_t startTime = clock();
	int N,C,I,P[2000],i=0;
	scanf("%d%d%d",&N,&C,&I);
	while(N)
	{
		scanf("%d",&P[i]);
		N--;
	}
	
	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
   return 0;
}
