#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

void back_track(vector<int> cand,vector<vector<int>>& ans,vector<int>inter , int target , int sum,int index){
    if(target == 0){
        ans.push_back(inter);
        return;
    }
    if(target<0) return;
    for(int i = index;i<cand.size();i++){
        if(target- cand[i] >=0) {
            sum+=cand[i];
            inter.push_back(cand[i]);
            back_track(cand,ans,inter,target-cand[i],sum,i);
            inter.pop_back();
            sum-=cand[i];
        }

    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> inter;
    back_track(candidates,ans,inter , target,0,0);
    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}