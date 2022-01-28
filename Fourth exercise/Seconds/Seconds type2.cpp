#include <iostream>
using namespace std;
void sort (int a[] , int n) {
    int i,j,min,index;
    for(i=0;i<n;i++)
    {
        min=a[i];
        index=i;
        for (j=i;j<n;j++)
            if (a[j]<min)
            {
                min=a[j];
                index=j;
            }
        a[index]=a[i];
        a[i]=min;
    }
}
int main() {
    int a[100];
    for (int i = 0; i < 100; i++)
        cin >> a[i];
    sort(a,100);
    for (int i=99;i>=0;i--)
    {
        if (a[i-1]<a[i]) {
            cout << a[i - 1];
            break;
        }
    }
    cout<<"\n";
    for (int i ; i<100;i++)
    {
        if (a[i]<a[i+1]) {
            cout << a[i + 1];
            break;
        }
    }
}
