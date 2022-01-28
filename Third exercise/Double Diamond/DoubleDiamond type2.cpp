#include <iostream>
using namespace std;
void lozi(int n);
int main()
{
    int n;
    cin >> n;
    lozi (n);
}
void lozi(int n)
{
    int space=0,star=1,N=0;
    switch (n)
    {
        case 3  : space+=1 ; break;
        case 5  : space+=2 ; break;
        case 7  : space+=3 ; break;
        case 9  : space+=4 ; break;
        case 11 : space+=5 ; break;
        case 13 : space+=6 ; break;
        case 15 : space+=7 ; break;
        case 17 : space+=8 ; break;
        case 19 : space+=9 ; break;
    }
    switch (n)
    {
        case 3  : N+=2 ; break;
        case 5  : N+=3 ; break;
        case 7  : N+=4 ; break;
        case 9  : N+=5 ; break;
        case 11 : N+=6 ; break;
        case 13 : N+=7 ; break;
        case 15 : N+=8 ; break;
        case 17 : N+=9 ; break;
        case 19 : N+=10 ; break;
    }
    for (int i = 0 ; i < N ; i++)
    {
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < star ; ++j)
            cout << "*";
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < star ; ++j)
            cout << "*";
        space--;
        star = star + 2;
        cout << "\n";
    }
    space = 1;
    star = star - 4;
    for (int i = 0 ; i < N-1 ; i++)
    {
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < star ; ++j)
            cout << "*";
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < space ; ++j)
            cout << " " ;
        for ( int j = 0 ; j < star ; ++j)
            cout << "*";
        space++;
        star = star - 2 ;
        cout << "\n";
    }
}



