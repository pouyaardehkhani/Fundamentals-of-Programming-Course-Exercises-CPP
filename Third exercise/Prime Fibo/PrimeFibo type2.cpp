#include<iostream>
#include<math.h>
using namespace std;
void adad_aval (int max , int min);
void fibo(int max,int min);
int main()
{
	int n,m;
	int min,max;
	cin>>n>>m;
		if(n>m)
	{
		max=n;
		min=m;
	}
	else
	{
		max=m;
		min=n;
	}
	adad_aval (max,min);
	cout<<"\n";
	fibo(max,min);
}
void adad_aval (int max , int min)
{
	bool f=true;
	for (int i=min+1;i<max;i++)
	{
		f=true;
		for (int b=2;b<=sqrt(i);b++)
		{
			if (i%b==0)
			{
				f=false;
				break;
			}
			
		}
		if (f)
			cout<<i<<" ";
	}
}
void fibo(int max,int min)
{
	int a=1,b=1,c;
	for(int i=1;i<max;i++)
	{
		c=a+b;
		b=a;
		a=c;
		if (c>=min && c<=max)
			cout<<c<<" ";
	}
}


