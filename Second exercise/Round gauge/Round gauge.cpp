#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int d,s;
	float p;
	const float PI=3.14159;
	cin>>d;
	if(d>=0&d<=4)
		{
			p=d*PI;
			cout<<p<<"\n"<<setprecision(3)<<p<<"\n";
			s=d*(int)PI;
			switch(s)
				{
					case 6 : cout<<"six \n"; break;
					case 3 : cout<<"three \n"; break;
					case 9 : cout<<"nine \n"; break;
					case 12 : cout<<"twelve \n"; break;
				}
		}
	else
	cout<<"error";
}
