#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float w,h,f,t;
	bool flag;
	cin>>w>>h;
	cin>>f>>t;
	if(f<=w & t<=h )
		cout<<"yes";
	else
		cout<<"no";
}
