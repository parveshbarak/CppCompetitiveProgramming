class ATM {
public:
    vector<long long> arr;
    unordered_map<long long,long long>mp;
    ATM() {
        arr.resize(5,0);
        mp[0] = 20; mp[1] = 50; mp[2] = 100; mp[3] = 200; mp[4] = 500;
    }
    
    void deposit(vector<long long> b) {
        for(long long i=0;i<b.size();i++) arr[i] += b[i];
    }
    
    vector<long long> withdraw(long long amt) {
        vector<long long> ans, ar = arr;
        for(long long i=4;i>=0;i--) {
            long long ct = amt/mp[i];
            if(ar[i] >= ct) ar[i] -= ct;
            else ct = ar[i], ar[i] = 0;
            ans.push_back(ct);
            amt -= mp[i]*ct;
        }
        if(amt!=0) return {-1};
        arr = ar;
        reverse(ans.begin(),ans.end());
        return ans;
    }
};