#include <iostream>
using namespace std;
void barrasi2 (int &x,int &Ties,int &o,bool f){
    if (f){
        Ties++;
    }
}
void barrasi (char a[3][3],int &x,int &Ties,int &o){
    bool f=true;
    for (int i=0;i<3;i++) {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && f) {
            if (a[i][0] == 'X') {
                x++;
                f = false;
                break;
            }
            if (a[i][0] == 'O') {
                o++;
                f = false;
                break;
            }
        }
    }
    if (f) {
        for (int j = 0; j < 3; j++) {
            if (a[0][j] == a[1][j] && a[1][j] == a[2][j] && f) {
                if (a[0][j] == 'X') {
                    x++;
                    f = false;
                    break;
                }
                if (a[0][j] == 'O') {
                    o++;
                    f = false;
                    break;
                }
            }
        }
    }
    if (f) {
        if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && f) {
            if (a[0][0] == 'X') {
                x++;
                f = false;
            }
            if (a[0][0] == 'O') {
                o++;
                f = false;
            }
        }
        if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && f) {
            if (a[0][2] == 'X') {
                x++;
                f = false;
            }
            if (a[0][2] == 'O') {
                o++;
                f = false;
            }
        }
    }
    barrasi2 (x,Ties,o,f);
}

int main() {
    int n ;
    cin>>n;
    cin.get();
    int x=0,Ties=0,o=0;
    for (int i=1;i<=n;i++)
    {
        char a[3][3]={{'a','a','a'},{'a','a','a'},{'a','a','a'}};
        for(int i=0;i<3;i++)
        {
            cin.getline(a[i],4);
        }
        barrasi (a,x,Ties,o);
    }
    cout<<"X: "<<x<<" - Ties: "<<Ties<<" - O: "<<o<<"\n";
    if (x>o)
        cout<<"Champ: X";
    else if (o>x)
        cout<<"Champ: O";
    else
        cout<<"Champ: N";
}
