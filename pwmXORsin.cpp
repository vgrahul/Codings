#include <iostream>
#include<math.h>
#include <time.h>
using namespace std;
int next = 0;
float pwm_fun(float x,float p)
  {
  	float x1;
  	if((0<=x)&(x<p))
  	x1 = x/p;
  	if((p<=x)&(x<0.5))
  	x1 = (x-p)/(0.5-p);
  	if((0.5<=x)&(x<1))
  	x1 = p*(1-x);
  	printf("Your Random Number using pwm : %f\n",x1);
    if(next)
    {
    next = next - 1;
  	pwm_fun(x1,p);
    }
    return (x1*10000000);
  }
  float sin_fun(float x,float r)
  {
  	float x1;
  	x1 = r*sin(3.14*x);
  	printf("Your Random Number using sin : %f\n",x1);
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
    l=pwm_fun(x,r);
    t=sin_fun(x,r);
    ixor = l ^ t;
  
    cout << l << " XOR " << t << " is " << ixor << endl;
      cout << double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
  return 0;
}
