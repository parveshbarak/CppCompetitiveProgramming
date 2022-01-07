#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 
int uniqueLetterString(string s) {
    if (s.empty()) return 0;
    int n = s.size();
    int res = 0;
    
    unordered_map<char, int> last;
    vector<int> prev(n, -1);
    vector<int> next(n, n);
    
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (last.count(ch) > 0) {
            prev[i] = last[ch];
            next[last[ch]] = i;
        }
        last[ch] = i;
    }
    
    for (int i = 0; i < n; i++) {
        res += (i - prev[i])*(next[i] - i);
    }
    
    return res;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}