class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& f, int start, int k) {
        long long m = f.size(), n = 400004;
        vector<long long> fruits(n,0);
        for(long long i=0;i<m;i++) {
            fruits[f[i][0]] = f[i][1];
        }
        vector<long long> dp(n,0);
        for(long long i=start+1;i<n;i++) dp[i] = dp[i-1] + fruits[i];
        for(long long i=start-1;i>=0;i--) dp[i] = dp[i+1] + fruits[i];
        // dp[start] = fruits[start];
        // for(long long i=0;i<10;i++) cout << dp[i] << " ";
        // cout << "\n";
        long long ans = max(dp[start+k],dp[start-k]);
        long long i=start,j=start+k;
        while(i>=0 && j >= start) {
            ans = max(ans,dp[i]+dp[j]);
            j -= 2; i--;
        }
        i=start,j=start-k;
        while(j<n && i <= start) {
            ans = max(ans,dp[i]+dp[j]);
            j += 2; i++;
        }
        return ans+fruits[start];
    }
};



// Job ID: 1227693
// Good Evening Sir, I am Parvesh Barak. I am persuing B.tech CSE(3rd Y) from FET,GKV and I am looking for an Internship opportunity at amazon.
// I applied on amazon's Job portal for Job ID: 1227693 , I didnt get any reply. Though I think I have relevent skills, I am attactching my resume.
// It will be really helpfull and gentle of you ,if you could refer me for the JOB ID: 1227693 !
// Thankyou