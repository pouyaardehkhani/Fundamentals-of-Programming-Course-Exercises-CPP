#include<iostream>
using namespace std;
int main()
{
	int p , a , b , $ , z ,s=0;
	cin>>p>>a>>b>>$;
	s=p/$;
	if (s/a>0)
		{
			z=s/a;
			s+=z*b;
		}
	cout<<s;
}
