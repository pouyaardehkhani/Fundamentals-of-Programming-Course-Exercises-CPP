#include <iostream>
using namespace std;
void read (int a[],int n){
    for (int i=0;i<n;i++)
        cin>>a[i];
}
void eao (int a[],int n,bool &f1){
    int m=0,b=0;
    if (n%2==0) {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0)
                m++;
        }
        if (m > (n / 2)) {
            cout << "-1";
            f1 = false;
        }
        for (int j = 0; j < n; j++) {
            if (a[j] % 2 == 1)
                b++;
        }
        if (b > (n / 2)) {
            cout << "-1";
            f1 = false;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0)
                m++;
        }
        for (int j = 0; j < n; j++) {
            if (a[j] % 2 == 1)
                b++;
        }
        if (m < b || m == n || b == n) {
            cout << "-1";
            f1 = false;
        }
    }
}
void swap (int a[],int n,int i,int j){
    if (i+1<n) {
        int b = a[i];
        a[i] = a[j];
        a[j] = b;
    }
}
void barrasi1 (int a[],int n,int i,bool &f){
    if ((i%2)==(a[i]%2))
        f=true;
    else
        f=false;
}
void even (int a[], int j,bool &f2){
    if (a[j]%2==1)
        f2=true;
}
void odd (int a[], int j,bool &f2) {
    if (a[j]%2==0)
        f2=true;
}
void barrasi (int a[],int n,int &s){
    for (int i=0; i < n; i++)
    {
        bool f=true,f2=false;
        barrasi1(a,n,i,f);
        if (f==0) {
            for (int j=0;j<n;j=j+2){
                if (i%2==1){
                    even(a,j,f2);
                    if (f2) {
                        swap(a, n, i, j);
                        s++;
                        break;
                    }
                }
            }
            for (int j=1;j<n;j=j+2){
                if (i%2==0 || i==0){
                    odd(a,j,f2);
                    if (f2) {
                        swap(a, n, i, j);
                        s++;
                        break;
                    }
                }
            }
        }
    }
}
int main() {
    int n,s=0 ;
    int *a ;
    cin >> n ;
    a = new int [n] ;
    read(a,n);
    bool f1=true;
    eao(a,n,f1);
    if (f1) {
        barrasi(a, n, s);
        if (s >= 0)
            cout << s;
    }
    delete[] a;
}
