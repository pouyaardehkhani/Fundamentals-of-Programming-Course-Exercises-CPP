#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
typedef string str;
struct Class {
    int code_class;
    str name_of_class;
    int tedad_vahed;
    str mahal_tashkil;
    int term_erae_shode;
    str rooz;
    str saat;
    str modat;
};
int count1=0;
struct daneshjo {
    str name;
    str family_name;
    long long shomare_daneshjoee;
    vector <int> tedad_term_akhz_shode;
    int number=0;
};
int count2=0;
struct term {
    int sal;
    int nimsal;
    int &term_as=...;
};
int count3=0;


void read_class(Class c[])
{
    int n;
    cout<<"tedad class ha (<10,000): ";
    cin>>n;
    for (int i=0;count1<n;i++) {
        cout << "enter code of class:";
        cin >> c[count1].code_class;
        cout << "enter name of class:";
        cin >> c[count1].name_of_class;
        cout << "enter tedad vahed class:";
        cin >> c[count1].tedad_vahed;
        cout << "enter mahal tashkil:";
        cin >> c[count1].mahal_tashkil;
        cout << "enter term erae shode (mesle 991 ya 992 do ragam aval shg va ragam baadi nimsal hast):";
        cin >> c[count1].term_erae_shode ;
        cout << "enter rooz (mesle sunday):";
        cin >> c[count1].rooz;
        cout << "enter saat (mesle 20:30):";
        cin >> c[count1].saat;
        cout << "enter modat class (mesle 2_saat):";
        cin >> c[count1].modat;
        count1++;
    }
}


void read_daneshjo(daneshjo d[])
{
    int n;
    cout<<"tedad daneshjo ha (<5,000,000): ";
    cin>>n;
    for (int i=0;count2<n;i++) {
        cout << "enter name of daneshjo:";
        cin >> d[count2].name;
        cout << "enter family name of daneshjo:";
        cin >> d[count2].family_name;
        cout << "enter shomare daneshjoee:";
        cin >> d[count2].shomare_daneshjoee;
        cout << "enter term haye akhz shode:";
        int t=0;
        cin>>t;
        (d[count2].tedad_term_akhz_shode).push_back(t);
        (d[count2].number)++;
        count2++;
    }
}


void read_term(term t[])
{
    int n;
    cout<<"tedad term ha (<30): ";
    cin>>n;
    for (int i=0;count3<n;i++) {
        cout << "enter sal (mesle 99 ya 00):";
        cin >> t[count3].sal;
        cout << "enter nimsal (mesle 1 ya 2):";
        cin >> t[count3].nimsal;
        cout<<....;
        &term_as=...;
        count3++;
    }
}


void show_classes(Class c[])
{
    cout<<setw(20)<<"code of class"<<setw(30)<<"name of class"<<setw(15)<<"tedad vahed"<<setw(20)<<"mahal tashkil"<<setw(20)<<"term erae shode"<<setw(10)<<"rooz"<<setw(10)<<"saat"<<setw(10)<<"modat"<<"\n";
    string s(80,'-');
    cout<<s<<"\n";
    for (int i=0; i<=count1; i++)
        cout<<setw(20)<<c[i].code_class<<setw(30)<<c[i].name_of_class<<setw(15)<<c[i].tedad_vahed<<setw(20)<<c[i].mahal_tashkil<<setw(20)<<c[i].term_erae_shode<<setw(10)<<c[i].rooz<<setw(10)<<c[i].saat<<setw(10)<<c[i].modat<<"\n";
}


void show_daneshjo(daneshjo d[])
{
    cout<<setw(20)<<"name"<<setw(20)<<"family name"<<setw(20)<<"shomare daneshjoee"<<setw(30)<<"tedad term akhz shode"<<"\n";
    string s(40,'-');
    cout<<s<<"\n";
    for (int i=0; i<=count2; i++)
        cout<<setw(20)<<d[i].name<<setw(20)<<d[i].family_name<<setw(20)<<d[i].shomare_daneshjoee<<setw(20)<<d[i].tedad_term_akhz_shode<<"\n";
}


void linear_search_daneshjo(daneshjo d[], string n)
{
    for (int i=0; i<=count2;i++) {
        if (d[i].name == n)
            cout << d[i].name << " " << d[i].family_name << "\t" << d[i].shomare_daneshjoee << "\n";
        if (d[i].family_name == n)
            cout << d[i].name << " " << d[i].family_name << "\t" << d[i].shomare_daneshjoee << "\n";
    }
    cout<< "not found \n";
}


void tedad_vahed_yek_term (daneshjo d[],int shomare_daneshjo,int term){
    int index;
    for (int i=0; i<=count2;i++) {
        if (d[i].shomare_daneshjoee == shomare_daneshjo){
            index=i;
        }
    }
    for (int i=0;i<=d[index].number;i++) {
        if (term == d[index].tedad_term_akhz_shode[i]){
            be ye tabe bfres ke code darsaye gably ro bgore
        }
    }
    bayad darsaye akz shodara vahedashono az tabe 4rom bgir
}


void  3 tabe dig bayad ba sharayet bashe


int main() {
    Class c[10000];
    daneshjo d[50000000];
    term t[30];
    while (true) {
        system("cls");
        int num;
        cout<<"be jaye space az _ estefade konid \n";
        cout << "1:read list class 2: read list daneshjo  3:read list term \n 4: show classes 5: show daneshjo ha \n 6:search by name of daneshjo \n 7: 8: 9: 10: \n 11:exit. \n enter a num: ";
        cin >> num;
        switch (num) {
            case 1:
                read_class(c);
                break;
            case 2:
                read_daneshjo(d);
                break;
            case 3:
                read_term(t);
                break;
            case 4:
                show_classes(c);
                system("pause");
                break;
            case 5:
                show_daneshjo(d);
                system("pause");
                break;
            case 6: {
                string name;
                cout << "enter name for search:";
                cin >> name;
                linear_search_daneshjo(d, name);
                system("pause");
                break;
            }
            case 7:

            case 8:

            case 9:

            case 10:

            case 11:
                goto lbl_exit;
        }
    }
    lbl_exit: system("pause");
}
