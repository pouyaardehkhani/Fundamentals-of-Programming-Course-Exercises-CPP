#include <iostream>
using namespace std;
void p1 (int n1,int m)
{
    int space=n1-1,star=1;
    for (int i=1;i<=n1-m;i++)
    {
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < star ; ++j)
            cout << "*";
        space--;
        star = star + 2;
        cout<<"\n";
    }
}
void p4 (int n1,int m)
{
    int space=n1-(n1-m),star=2*(n1-m)-1;
    for (int i=1;i<=n1-m;i++)
    {
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < star ; ++j)
            cout << "*";
        space++;
        star = star - 2;
        cout<<"\n";
    }
}
void p2 (int n1,int m)
{
    int z=2*(n1-1)+1,b,space2=1,star=2*(n1-m),space1=(n1-1)-(n1-m);
    if (z%2==1)
        b=((z-1)/2)-(n1-m);
    else
        b=((z-1)/2)-(n1-m);
    for (int i=1;i<=(b+1);i++)
    {
        for ( int j = 0 ; j < space1 ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < (star/2) ; ++j)
            cout << "*";
        for (int j=0;j < space2;j++)
            cout<< " ";
        for ( int j = 0 ; j < (star/2) ; ++j)
            cout << "*";
        space1--;
        space2+=2;
        cout<<"\n";
    }
}
void p3 (int n1,int m)
{
    int z=2*(n1-1)+1,b,space1=1,space2= (2*(m-1)+1)-2 ,star=2*(n1-m);
    if (z%2==1)
        b=((z-1)/2)-(n1-m);
    else
        b=((z-1)/2)-(n1-m);
    for (int i=1;i<=b;i++)
    {
        for ( int j = 0 ; j < space1 ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < (star/2) ; ++j)
            cout << "*";
        for (int j=0;j<space2;j++)
            cout<< " ";
        for ( int j = 0 ; j < (star/2) ; ++j)
            cout << "*";
        space1++;
        space2-=2;
        cout<<"\n";
    }
}
int main() {
    int k,n;
    cin>>k>>n;
    int n1=n+1;
    int m=n1-k;
    p1(n1,m);
    p2(n1,m);
    p3(n1,m);
    p4(n1,m);
}
