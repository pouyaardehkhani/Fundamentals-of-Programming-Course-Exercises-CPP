#include<iostream>
#include<iomanip>
using namespace std;
void morab (int n);
int main()
{
	int n;
	cin>>n;
	morab(n);
}
void morab (int n)
{
	for(int i=1;i<=n;i++)
		cout<<"*";
	for(int i=1;i<=n-2;i++)
		cout<<"\n"<<"*"<<setfill(' ')<<setw(n-1)<<"*"<<endl;
	for(int i=1;i<=n;i++)
		cout<<"*";
}
