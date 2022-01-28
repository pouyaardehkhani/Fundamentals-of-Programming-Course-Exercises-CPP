#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float c,f;
	cin>>f;
	if (f>=-1000 & f<=1000)
	{
		c=(f-32)*(float)5/9;
		cout<<fixed<<setprecision(2)<<c;
	}
}
