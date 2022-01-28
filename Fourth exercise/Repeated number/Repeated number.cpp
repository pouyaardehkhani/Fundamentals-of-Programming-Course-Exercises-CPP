#include <iostream>
using namespace std;
void read (int a[],int n) {
    for (int i=0;i<n;i++)
        cin>>a[i];
}
int main() {
    int n ;
    int *a ;
    cin >> n ;
    a = new int [n] ;
    bool f=true;
    read(a,n);
    for (int i=0;i<n;i++){
        int s=0;
        for (int j=i;j<n;j++){
            if (a[i]==a[j]){
                s=s+1;
            }
        }
        if (s>(int)(n/2)) {
            cout << a[i] << "\n";
            f=false;
            break;
        }
    }
    delete[] a;
    if (f)
        cout<<"None";
}



