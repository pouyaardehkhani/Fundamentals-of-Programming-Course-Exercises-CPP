#include <iostream>
#include <cmath>
using namespace std;
bool aval (int i);
void joft_jaleb (int max,int n,int m)
{
    bool f=true;
    for (int i=2;i<max;i++)
    {
        f=true;
        int v=i+2;
        for (int b=2;b<=sqrt(i);b++)
        {
            if (i%b==0)
            {
                f=false;
                break;
            }
        }
        if (f)
        {
            if (aval(i+2))
            {
                    n = i;
                    m = i + 2;
            }
        }
    }
    cout<<n<<" "<<m;
}
bool aval (int i)
{
    bool f1=true;
    for (int b=2;b<=sqrt(i);b++) {
        f1=true;
        if (i % b == 0) {
            f1 = false;
            break;
        }
    }
    return f1;
}
int main() {
    int max,m=0,n=0;
    cin>>max;
    if (max<5)
        cout<<"-1"<<" "<<"-1";
    else
        joft_jaleb(max,n,m);
}
