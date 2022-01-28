#include<iostream>
using namespace std;
int main()
{
	char a;
	cin>>a;
	if (a>=48&a<=57)
	{
		if(a%2==0)
		cout<<"even";
		else
		cout<<"odd";
	}
	else if ((a>=65&a<=90) | (a>=97&a<=122))
	{
		if(a==65 | a==69 | a==73 | a==79 | a==85 | a==97 | a==101 | a==105 | a==111 | a==117)
		cout<<"vowel";
		else
		cout<<"consonants";
	}
	else
	cout<<"error";
}
