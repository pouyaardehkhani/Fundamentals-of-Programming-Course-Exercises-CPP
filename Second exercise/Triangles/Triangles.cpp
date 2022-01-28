#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,b,c;
	bool f1 , f2 , f3;
	cin>>a>>b>>c;
	f1= c<(a+b);
	f2= b<(a+c);
	f3= a<(b+c);
	if (f1 & f2 & f3)
	{
		if(a==b&a==c&b==c)
		cout<<"equilateral triangle";
		else if (a==b|a==c|c==b)
		cout<<"isosceles triangle";
		else if(a==sqrt(pow(b,2)+pow(c,2)) | b==sqrt(pow(a,2)+pow(c,2)) | c==sqrt(pow(b,2)+pow(a,2)))
		cout<<"right triangle";
		else
		cout<<"scalene triangle";
	}
	else
	cout<<"invalid";
}
