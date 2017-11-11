#include <stdio.h>
#include <limits.h>

#if UINT_MAX >= 0xFFFFFFFF
typedef unsigned uint32;
#else
typedef unsigned long uint32;
#endif

#define C_ASSERT(expr) extern char CAssertExtern[(expr)?1:-1]


C_ASSERT(sizeof(uint32) * CHAR_BIT == 32);

C_ASSERT(sizeof(uint32) == sizeof(float));

double Ieee754SingleDigits2DoubleCheat(const char s[32])
{
  uint32 v;
  float f;
  unsigned i;
  char *p1 = (char*)&v, *p2 = (char*)&f;

  v = 0;
  for (i = 0; i < 32; i++)
    v = (v << 1) + (s[i] - '0');

 
  for (i = 0; i < sizeof(f); i++)
    *p2++ = *p1++;

  return f;
}

double Ieee754SingleDigits2DoubleNoCheat(const char s[32])
{
  double f;
  int sign, exp;
  uint32 mant;
  int i;

 
  sign = s[0] - '0';

  
  exp = 0;
  for (i = 1; i <= 8; i++)
    exp = exp * 2 + (s[i] - '0');

  
  exp -= 127;

 

  if (exp > -127)
  {
    
    mant = 1; 
    exp -= 23;
  }
  else
  {
    
    mant = 0; 
    exp = -126; 
    exp -= 23;
  }

  
  for (i = 9; i <= 31; i++)
    mant = mant * 2 + (s[i] - '0');

  f = mant;

  
  while (exp > 0)
    f *= 2, exp--;


  while (exp < 0)
    f /= 2, exp++;

  if (sign)
    f = -f;

  return f;
}

int main(void)
{
    char hex[17], bin[65] = "";  
    int  i = 0;    

    /* 
     * Reads hexadecimal number from user 
     */  
    printf("Enter any hexadecimal number: ");  
    gets(hex);  
  
    /* 
     * Finds binary of each hexadecimal digit 
     */  
    for(i=0; hex[i]!='\0'; i++)  
    {  
        switch(hex[i])  
        {  
            case '0':  
                strcat(bin, "0000");  
                break;  
            case '1':  
                strcat(bin, "0001");  
                break;  
            case '2':  
                strcat(bin, "0010");  
                break;  
            case '3':  
                strcat(bin, "0011");  
                break;  
            case '4':  
                strcat(bin, "0100");  
                break;  
            case '5':  
                strcat(bin, "0101");  
                break;  
            case '6':  
                strcat(bin, "0110");  
                break;  
            case '7':  
                strcat(bin, "0111");  
                break;  
            case '8':  
                strcat(bin, "1000");  
                break;  
            case '9':  
                strcat(bin, "1001");  
                break;  
            case 'a':  
            case 'A':  
                strcat(bin, "1010");  
                break;  
            case 'b':  
            case 'B':  
                strcat(bin, "1011");  
                break;  
            case 'c':  
            case 'C':  
                strcat(bin, "1100");  
                break;  
            case 'd':  
            case 'D':  
                strcat(bin, "1101");  
                break;  
            case 'e':  
            case 'E':  
                strcat(bin, "1110");  
                break;  
            case 'f':  
            case 'F':  
                strcat(bin, "1111");  
                break;  
            default:  
                printf("Invalid hexadecimal input.");  
        }  
    }  
  
    printf("\nHexademial number = %s\n", hex);  
    printf("Binary number = %s", bin); 
  printf("%+g\n", Ieee754SingleDigits2DoubleCheat(bin));
  return 0;
}
