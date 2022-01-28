#include <iostream>
using namespace std;
void chop (int c[][100],int n,int k);
void read (int a[][100],int n,int m)
{
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            cin>>a[i][j];
}
void multi (int a[][100],int b[][100],int c[][100],int n,int m,int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            for (int z = 0; z < m; z++)
                c[i][j] += a[i][z] * b[z][j];
        }
    }
}
int main() {
    int n,m,k;
    int a[100][100]={0};
    int b[100][100]={0};
    int c[100][100]={0};
    cin>>n>>m>>k;
    read (a,n,m);
    read (b,m,k);
    multi(a,b,c,n,m,k);
    chop(c,n,k);
}
void chop (int c[][100],int n,int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << c[i][j] << " ";
        }
        cout<<"\n";
    }
}