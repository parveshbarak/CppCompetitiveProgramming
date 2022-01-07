#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int minSteps(string s, string t) {
    int n = s.size(),ans=0;
    vector<int> a(26,0);
    vector<int> b(26,0);
    for(int i=0;i<n;i++) {
        a[s[i]-'a']++;
        b[t[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if(a[i]>b[i])
            ans += a[i]-b[i];
    }
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}