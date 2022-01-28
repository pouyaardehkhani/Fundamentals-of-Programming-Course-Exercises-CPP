#include <iostream>
using namespace std;
void read (int a[],int n) {
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void gardesh (int a[],int n,int d){
    for (int i=d;i<n;i++)
        cout<<a[i]<<",";
}
void bagie (int a[],int n,int d){
    for (int i=0;i<d-1;i++)
        cout<<a[i]<<",";
    cout<<a[d-1];
}
void write (int a[],int n)
{
    for (int i=0;i<n-1;i++)
        cout<<a[i]<<",";
    cout<<a[n-1];
}
int main() {
    int n,d;
    int *a;
    cin >> n >> d;
    a = new int[n];
    read(a, n);
    if (d==0 || d%n==0 ) {
        write(a, n);
        delete[] a;
    }
    else if (d>n)
    {
        gardesh(a, n, d%n);
        bagie(a, n, d%n);
        delete[] a;
    }
    else {
        gardesh(a, n, d);
        bagie(a, n, d);
        delete[] a;
    }
}
