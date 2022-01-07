#include<bits/stdc++.h>
using namespace std;
#define MAX 1e9
#define ll long long
#define MOD 1000000007
 

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int,int>> arr;    
    vector<int> ans;
    for(int i=0;i<n;i++) {
        arr.push_back({nums[i],i});
    }    
    sort(arr.begin(),arr.end());
    // for(int i=0;i<n;i++) {
    //     cout << arr[i].first << " ";
    // } 

    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        // auto it = s.find(arr[i].first);
        s.insert(arr[i]);
    }

    auto it = s.find({6,1});
    // cout << it << " " << *it << " ";

    return ans;
}
 

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> ans;
    int t=10;
    vector<int> nums = {11,5,6,17,8,10};

    ans = twoSum(nums,t);
    
    
    return 0;
}