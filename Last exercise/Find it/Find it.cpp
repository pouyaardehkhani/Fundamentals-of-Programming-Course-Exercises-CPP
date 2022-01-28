#include <iostream>
#include <string>
using namespace std;
struct jomle {
    string sub;
}k[10];

void change (string &s,string &s1,int m) {
    for (int i = 0; i < m; i++) {
        s1[i] = s[m - i - 1];
    }
}

void lowerorupper (string &s,int m) {
    for (int i = 0; i < m; i++) {
        if (s[i] >= 97 && s[i] <= 122) {
            s[i] = s[i] - 32;
        } else if (s[i] >= 65 && s[i] <= 90) {
            s[i] = s[i] + 32;
        } else
            continue;
    }
}

int main() {
    string s;
    getline(cin, s, '\n');
    int m = s.length();
    string s1(m, ' ');
    int n;
    cin >> n;
    for (int i = 0; i < n+1; i++) {
        getline(cin, k[i].sub, '\n');
    }
    change(s, s1, m);
    int key = 0, nf = 0;
    for (int i = 0; i < n+1; i++) {
        while (key != -1) {
            key = (k[i].sub).find(s, key);
            if (key != -1) {
                cout << i << " " << key+1 << "\n";
                nf++;
                key++;
            }
        }
        lowerorupper(s, m);
        key = 0;
        while (key != -1) {
            key = (k[i].sub).find(s, key);
            if (key != -1) {
                cout << i << " " << key+1 << "\n";
                nf++;
                key++;
            }
        }
        key = 0;
        while (key != -1) {
            key = (k[i].sub).find(s1, key);
            if (key != -1) {
                cout << i << " " << key+1 << "\n";
                nf++;
                key++;
            }
        }
        lowerorupper(s1, m);
        key = 0;
        while (key != -1) {
            key = (k[i].sub).find(s1, key);
            if (key != -1) {
                cout << i << " " << key+1 << "\n";
                nf++;
                key++;
            }
        }
        key = 0;
        lowerorupper(s, m);
        lowerorupper(s1, m);
    }
    if (nf == 0) {
        cout << "Substring not found";
    }
}
