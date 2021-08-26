#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

bool closeStrings(string word1, string word2) {
    if(word1.length() != word2.length())
            return false;
    vector<int> a(26,0), b(26,0);
    for(int i=0;i<word1.length();i++) {
        a[word1[i]-'a']++;
        b[word2[i]-'a']++;
    }
    for(int i=0;i<26;i++) {
        if((a[i]>0 && b[i]==0) ||(b[i]>0 && a[i]==0))
            return false;
    }
    sort(a.begin(),a.end()); sort(b.begin(),b.end());
    for(int i=0;i<26;i++) {
        if(a[i] != b[i])
            return false;
    }
    return true;
} 


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}