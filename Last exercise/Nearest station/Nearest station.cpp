#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
struct isgah {
    string name_isgah;
    int tool;
    int arz;
}k[1000];
int main()
{
    int tool2;
    int arz2;
    int n;
    char comma1;
    char comma2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k[i].name_isgah;
        cin>>k[i].tool>>comma1>>k[i].arz;
    }
    string temp;
    int temp1,temp2;
    for (int i = 0 ; i<n ; i++){
        for(int j=0;j<n-i-1;j++){
            if ((k[j].name_isgah) > (k[j+1].name_isgah)){
                temp=k[j].name_isgah;
                temp1=k[j].tool;
                temp2=k[j].arz;
                k[j].name_isgah=k[j+1].name_isgah;
                k[j].tool=k[j+1].tool;
                k[j].arz=k[j+1].arz;
                k[j+1].name_isgah=temp;
                k[j+1].tool=temp1;
                k[j+1].arz=temp2;
            }
        }
    }
    cin>>tool2>>comma2>>arz2;
    int *fasele;
    fasele=new int[n];
    for (int i=0;i<n;i++) {
        fasele[i] = (int)sqrt(pow((k[i].tool - tool2), 2) + pow((k[i].arz - arz2), 2));
    }
    vector <int> index;
    int min;
    for (int i=0;i<n;i++){
        if (i==0){
            min=fasele[0];
        }
        else{
            if(min>fasele[i]){
                min=fasele[i];
            }
        }
    }
    int b=0;
    for (int i=0;i<n;i++){
        if (min==fasele[i]){
            b++;
            index.push_back(i);
        }
    }
    cout<<"The nearest station(s) to you:"<<"\n";
    for(int i=0;i<b;i++){
        cout<<k[index[i]].name_isgah<<" at ("<<k[index[i]].tool<<", "<<k[index[i]].arz<<")"<<"\n";
    }
    cout<<"about "<<min<<" meters away from you";
    delete[] fasele;
}

