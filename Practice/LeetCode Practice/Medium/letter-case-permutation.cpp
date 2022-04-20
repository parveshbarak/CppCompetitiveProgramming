#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

void back_track(string s, vector<string>&ans, string inter, int index) {
    ans.push_back(inter);

    if(index > s.length()-1) return;
    for(int i=index;i<s.length();i++) {
        if((s[i] - '0' < 10) && (s[i] - '0' > -1))
            continue;
        if((inter[i] - 'A' < 27) && (inter[i] - 'A' > -1))
            inter[i] += 32;
        else
            inter[i] -= 32;
        back_track(s,ans,inter,i+1);
        if((inter[i] - 'A' < 27) && (inter[i] - 'A' > -1))
            inter[i] += 32;
        else
            inter[i] -= 32;
    }
} 

vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    string inter = s;
    back_track(s,ans,inter,0);
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}