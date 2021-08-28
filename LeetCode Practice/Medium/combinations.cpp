#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

void back_track(int n, int k, vector<vector<int>>& ans, vector<int> inter, int idx) {

    if(inter.size() == 2)
        ans.push_back(inter);

    for(int i=idx;i<n;i++) {
        if(inter.size() > 2)
            continue;
        inter.push_back(i);
        back_track(n,k,ans,inter,i+1);
        inter.pop_back();
    }
} 

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> inter;
    back_track(n, k , ans, inter , 0);     
    return ans;   
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}