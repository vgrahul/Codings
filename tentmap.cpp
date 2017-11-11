  #include <stdio.h>
  #include <math.h>
  int next=1000;
  int tent_fun(float x,float u)
  {
  	float x1;
  	if(x>=0.5)
  	x1 = u*(1-x)*0.5;
  	if(x<0.5)
  	x1 = u*x*0.5;
  	printf("Your Random Number is : %f\n",x1);
    if(next)
    {
    next = next - 1;
  	tent_fun(x1,u);
    }
  }
  
  int main()
  {
    float x,r;
    printf("Enter values for x and r :\n");
    scanf("%f%f",&x,&r);
    tent_fun(x,r);
    return 0;
  }
