#include <iostream>
using namespace std;
void baraks (int n);
void aine (int n);
int main()
{
    int n;
    while (cin>>n)
    {
        if (n >= 1000 && n < 1000000)
        {
            baraks(n);
            aine(n);
        }
        else if (n==0)
            break;
        else
        	cout << "error";
    }
}
void baraks (int n)
{
    int s=0;
    while (n!=0)
    {
        s=s*10+n%10;
        n/=10;
    }
    cout<<s<<"\n";
}
void aine (int n)
{
  int m;
  while (n!=0)
  {
      m=n%10;
      for (int i=1;i<=m;i++)
          cout<<m;
      cout<<"\n";
      n/=10;
  }
}
