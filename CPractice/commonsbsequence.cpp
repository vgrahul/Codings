#include<bits/stdc++.h>
using namespace std;
 
// Function to calculate longest string
// str1     --> first string
// str2     --> second string
// count1[]  --> hash array to calculate frequency
//              of characters in str1
// count[2]  --> hash array to calculate frequency
//              of characters in str2
// result   --> resultant longest string whose
// permutations are sub-sequence of given two strings
void longestString(string str1, string str2)
{
    int count1[26] = {0}, count2[26]= {0};
 
    // calculate frequency  of characters
    for (int i=0; i<str1.length(); i++)
        count1[str1[i]-'a']++;
    for (int i=0; i<str2.length(); i++)
        count2[str2[i]-'a']++;
 
    // Now traverse hash array
    string result;
    for (int i=0; i<26; i++)
 
        // append character ('a'+i) in resultant
        // string 'result' by min(count1[i],count2i])
        // times
        for (int j=1; j<=min(count1[i],count2[i]); j++)
            result.push_back('a' + i);
 
    cout << result;
}
 
// Driver program to run the case
int main()
{
    string str1 = "abcuvwxyz", str2 = "qwertyuiopsdfghjklzxcvbnm";
    longestString(str1, str2);
    return 0;
}
