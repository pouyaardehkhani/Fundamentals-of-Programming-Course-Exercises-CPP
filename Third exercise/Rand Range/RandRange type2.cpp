#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void adad(int max,int min,int n);
int main()
{
	int a,b,n=5;
	int max,min;
	cin>>a>>b;
	if(a>b)
	{
		max=a;
		min=b;
	}
	else
	{
		max=b;
		min=a;
	}
	adad(max,min,n);
}
void adad(int max,int min,int n)
{
	srand(time(NULL));
	for(int i=1;i<=n;i++)
	{
		float r=min + (float)( rand()/((float)RAND_MAX/(max-min)));
		cout<<r<<"\t";
	}
}
