#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

vector<int> grayCode(int n) {
    vector<int> ans = {0};
    for (int i=0; i<n;i++) {
        for (int j=ans.size()-1;j>=0;j--)
            ans.push_back(ans[j] | (1 << i));
    }
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}