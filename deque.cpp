#include<iostream>
#include<deque>
int main()
{
	deque line;
	line.push_back("customer 1");
	line.push_front("customer 2");
	for( int i=0;i<line.size();i++)
	cout<<line[i];
	return 0;
}
