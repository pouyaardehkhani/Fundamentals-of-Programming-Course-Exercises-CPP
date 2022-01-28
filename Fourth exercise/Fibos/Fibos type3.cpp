#include <iostream>
using namespace std;
int fibo (int max){
    if (max==1||max==2)
        return 1;
    else
        return (fibo(max-1)+fibo(max-2));
}
void fibo ()
{
    int n=11,j=1;
    while (j<n) {
        cout << fibo(j)<<" ";
        j++;
    }
}
void fibo (int max,int min){
    int j=1;
    for (j;fibo(j)<max;j++) {
        if (fibo(j)>=min)
            cout<<fibo(j)<<" ";
    }
}
int main() {
    int n,m,max,min,i=1;
    cin>>n>>m;
    if (n>m)
    {
        max=n;
        min=m;
    }
    else
    {
        max=m;
        min=n;
    }
    fibo(max,min);
    cout<<"\n";
    while (fibo(i)<max) {
        cout << fibo(i) << " ";
        i++;
    }
    cout<<"\n";
    fibo();
}
