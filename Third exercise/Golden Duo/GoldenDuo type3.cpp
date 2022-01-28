#include <iostream>
#include <math.h>

bool isPrime(int n);
void primeTwin(int n);

using namespace std;
int main()
{

    int n;
    cin >> n;

    primeTwin(n);

}

bool isPrime(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)
            return false ;
    return true;
}

void primeTwin(int n){
    int primes[2000];
    int counter=0;

    for (int i = 2; i <= n; ++i) {
        if (isPrime(i)){
            primes[counter]=i;
            counter++;
        }
    } //  [2,3,5,7,9,11,13,17] counter=4
    string result="";
    bool x=true;
    for (int i=counter-1;i>=1;i--){
        if (primes[i]-primes[i-1]==2){
            x= false;
            cout<<primes[i-1]<<" "<<primes[i];
            break;
        }
    }

    if (x) {
        cout << "-1 -1";
    }
}