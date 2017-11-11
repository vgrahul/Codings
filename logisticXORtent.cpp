#include <iostream>
#include <time.h>
  #include <stdio.h>
  #include <math.h>
  #include <fstream>
  #include <bitset>
  #include <stdint.h>
  #include <limits.h>
using namespace std;
int next = 80000;
float logistic_fun(float x,float r)
  {
  	float x1;
  	x1 = r*x*(1-x);
  //	printf("Your Random Number using logistic : %f\n",x1);
    return (x1);
  }
float tent_fun(float x,float u)
  {
  	float x1;
  	if(x>=0.5)
  	x1 = u*(1-x)*0.5;
  	if(x<0.5)
  	x1 = u*x*0.5;
  //	printf("Your Random Number using tent : %f\n",x1);
    return (x1);
  }
  void float_binary( float f)
{
    cout<<bitset<sizeof f*8>(*(long unsigned int*)(&f))<<endl;
  
}
int main()
{
    clock_t startTime = clock();
    float x,r,n,m,t,l;
    int ixor,temp1,temp2;
    //printf("Enter values for x and r :\n");
    scanf("%f%f",&x,&r);
    l=logistic_fun(x,r);
    t=tent_fun(x,r);
    while(next)
    {
    next = next - 1;
  	l=logistic_fun(l,r);
    t=tent_fun(t,r);
    temp1 = l*1000000;
    temp2 = t*1000000;
	ixor = temp1 ^ temp2;
	float_binary(ixor*0.0000001);
    next = next - 1;
	}
    //cout << l << " XOR " << t << " is " << ixor << endl;
   cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
  return 0;
}
