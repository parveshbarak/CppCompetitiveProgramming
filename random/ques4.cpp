#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
	getline(cin,s);
    vector<int> arr;
    int n = s.length();
    for(int i=0;i<=n;i++) {
        if(s[i] != ' ') {
            vector<int> num;
            while(s[i] != ' ')
            int a = (int)s[i] - 48;
            arr.push_back(a);
        }
    }

    for(int i=0;i<n/2;i++)
        cout << arr[i] << " ";

return 0;
}