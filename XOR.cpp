#include <iostream>

//1.06 seconds
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
float tent_fun(float x,float u)
  {
  	float x1;
  	if(x>=0.5)
  	x1 = u*(1-x)*0.5;
  	if(x<0.5)
  	x1 = u*x*0.5;
  	printf("Your Random Number using tent : %f\n",x);
    if(next)
    {
    next = next - 1;
  	tent_fun(x1,u);
    }
    return (x1*10000000);
  }
int main()
{

    float x,r,n,m;
    int ixor,t,l;
    printf("Enter values for x and r :\n");
    scanf("%f%f",&x,&r);
    l=logistic_fun(x,r);
    t=tent_fun(x,r);
    ixor = l ^ t;
  
    cout << l << " XOR " << t << " is " << ixor << endl;

  return 0;
}
