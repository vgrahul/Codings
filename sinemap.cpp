  #include <stdio.h>
  #include <math.h>
  int next=1000;
  int sin_fun(float x,float r)
  {
  	float x1;
  	x1 = r*sin(3.14*x);
  	printf("Your Random Number is : %f\n",x1);
    if(next)
    {
    next = next - 1;
    sin_fun(x1,r);
    }
  }
  
  int main()
  {
    float x,r;
    printf("Enter values for x and r :\n");
    scanf("%f%f",&x,&r);
    sin_fun(x,r);
    return 0;
  }
