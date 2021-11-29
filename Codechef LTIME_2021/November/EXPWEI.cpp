class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(long long i=1;i<n;i++) prefix[i]=prefix[i-1]+nums[i];
        vector<long long> ans(n,-1);
        for(long long i=k;i<n-k;i++) {
            long long x = (i-k == 0) ? prefix[i] : prefix[i]-prefix[i-k-1];
            long long y = prefix[i+k]-prefix[i];
            ans[i] = (x+y)/(k+k+1);
        }
        return ans;
    }
};