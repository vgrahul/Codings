#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
int next = 0;
float logistic_fun(float x,float r)
  {
  	float x1;
  	x1 = r*x*(1-x);
  	printf("Your Random Number using logistic : %f\n",x1);
    if(next)
    {
    next = next - 1;
  	logistic_fun(x1,r);
    }
    return (x1*1000000);
  }
float sin_fun(float x,float r)
  {
  	float x1;
  	x1 = r*sin(3.14*x);
  	printf("Your Random Number is : %f\n",x1);
    if(next)
    {
    next = next - 1;
    sin_fun(x1,r);
    }
    return (x1*1000000);
  }
int main()
{
    clock_t startTime = clock();
    float x,r,n,m;
    int ixor,t,l;
    printf("Enter values for x and r :\n");
    scanf("%f%f",&x,&r);
    l=logistic_fun(x,r);
    t=sin_fun(x,r);
    ixor = l ^ t;
  
    cout << l << " XOR " << t << " is " << ixor << endl;
    cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

  return 0;
}
