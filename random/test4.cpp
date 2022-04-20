#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

int z_fun(string s) {
    int n = s.length();
    vector<int> z(n,0);
    int l=0,r=0;
    for (int i=1;i<n;i++) {
        if (i <= r)
            z[i] = min (r-i+1,z[i-l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
 
int strStr(string haystack, string needle) {
    string s = needle + "$" + haystack;

}


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}