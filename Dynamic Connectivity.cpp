#include<iostream>
#include<string>
#include<time.h>
using namespace std;
int id[1000];
int N;
int assignement(int N)
{
	for(int i=0;i<N;i++)
	id[i] = i;
}
bool connected(int p,int q)
{
	return id[p] == id[q];
}
void unin(int m,int n)
{
	int pid = id[m];
	int qid = id[n];
	for(int i = 0;i<N;i++)
	if(id[i] == pid)
	id[i] = qid;
}
int main()
{
	clock_t startTime = clock();
    scanf("%d",&N);
    assignement(N);
    int p,q;
    scanf("%d%d",&p,&q);
    unin(p,q);
    scanf("%d%d",&p,&q);
    unin(p,q);
    scanf("%d%d",&p,&q);
    if (connected(p,q))
    printf("connected");
	else ("not connected\n");
	  for (int c = 0; c < N*0.5; c++)
         printf("%d\t", id[c]);
	cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
	return 0;
}
