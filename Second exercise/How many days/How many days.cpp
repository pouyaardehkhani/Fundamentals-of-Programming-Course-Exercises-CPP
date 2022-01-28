#include<iostream>
using namespace std;
int main()
{
	int s;
	cin>>s;
	if((s/25)%4!=0)
	cout<<"leap year";
	else if (s%100==0 & (s/100)%4==0)
	cout<<"leap year";
	else
	cout<<"normal year";
}
