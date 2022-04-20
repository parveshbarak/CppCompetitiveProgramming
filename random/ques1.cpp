#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
	getline(cin,s);
    char c; cin >> c;
    int n; cin >> n;
    int i=0,ct=0;
    for(i;i<s.length();i++) {
        if(s[i]==c)
            ct++;
        if(n==ct)
            break;
    }
    for(int j=i+1;j<s.length();j++)
        cout << s[j];
    cout << "\n";
    
    return 0;
}