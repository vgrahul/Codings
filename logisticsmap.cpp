  #include <stdio.h>
  #include <math.h>
  #include <fstream>
  #include <bitset>
  #include <stdint.h>
  #include <limits.h>
#include <iostream>
using namespace std;
  int next=80000;
  int i=0;
  /*std::string GetBinary32( float value )
{
    union
    {
         float input;   // assumes sizeof(float) == sizeof(int)
         int   output;
    }    data;
 
    data.input = value;
 
    std::bitset<sizeof(float) * CHAR_BIT>   bits(data.output);
 
    std::string mystring = bits.to_string<char, 
                                          std::char_traits<char>,
                                          std::allocator<char> >();
 
    return mystring;
}
  std::string float_binary(float a1)
{
       std::string str = GetBinary32( a1 );
       std::cout<<str<<"\n";
}*/
void float_binary( float f)
{
    cout<<bitset<sizeof f*8>(*(long unsigned int*)(&f))<<endl;
  
}
  /*void save_text(float a)
  {
  	   
   
   float_binary(a);
   
   
  }*/
  int logistic_fun(float x,float r)
  {
  	float x1;
  	x1 = r*x*(1-x);
    if(next)
    {
    next = next - 1;
    i+=1;
    float_binary(x1);
  	logistic_fun(x1,r);
	}
	
  }
  
  int main()
  {
    float x,r;
    scanf("%f%f",&x,&r);
    logistic_fun(x,r);
    
    return 0;
  }
