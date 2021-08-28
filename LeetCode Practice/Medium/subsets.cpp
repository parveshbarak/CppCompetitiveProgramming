#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007

void back_track(vector<int> nums ,set<vector<int>>&ans ,  vector<int> inter , int index){

    ans.insert(inter);
    //if(index >=nums.size()) return ;
    for(int i = index ;i<nums.size();i++){
        inter.push_back(nums[i]);
        back_track(nums , ans , inter , i+1);
        inter.pop_back();
    }
    return;
} 

vector<vector<int>> subsets(vector<int>& nums) {
    set<vector<int>> ans;
    vector<int> inter;
    back_track(nums,ans,inter,0);
    return vector<vector<int>> (ans.begin(),ans.end());
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    return 0;
}