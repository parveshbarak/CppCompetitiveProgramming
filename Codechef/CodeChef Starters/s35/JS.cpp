
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld	long double
#define mod 1000000007
#define inf 1e18
#define pb emplace_back
#define vi vector<ll>
#define vs	vector<string>
#define pii pair<ll,ll>
#define vp vector<pair<ll,ll>>
#define mp  make_pair
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vi,greater<ll> >
#define ff first
#define ss second
#define mid(l,r) (l+(r-l)/2)
#define loop(i,a,b) for(int i=(a);i<(b);i++)
#define revloop(i,a,b) for(int i=(a);i>=(b);i--)
#define printarr(arr,a,b) for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;



void io_file() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("/home/parvesh/Desktop/Codes/io_files/input.txt","r", stdin);
        freopen("/home/parvesh/Desktop/Codes/io_files/output.txt","w", stdout);
        freopen("/home/parvesh/Desktop/Codes/io_files/error.txt","w", stderr);
    #endif
}


// vector<vector<ll>> dp;

ll rec(vector<int>&arr, int idx, int flag, vector<vector<ll>>&dp) {
    int n = arr.size();
    //base case'
    if(idx==n) return INT_MAX;
    if(idx==n-1) return 0;
    if(dp[idx][flag] != -1) return dp[idx][flag];
    ll nsp=n,ndp=n, a=INT_MAX, b=INT_MAX;
    for(int i=idx+1;i<n;i++) {
        if(nsp==n && arr[idx]%2 == arr[i]%2) nsp = i;
        if(flag==1 && ndp==n && arr[idx]%2 != arr[i]%2) ndp = i;
        if(nsp != n && (ndp != n || flag==0)) break;
    }
    a = rec(arr,nsp,flag, dp);
    if(flag==1) b = rec(arr,ndp,0,dp);
    return dp[idx][flag] = 1+min(a,b);
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
    	int n; cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin >> arr[i];
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        int ans = rec(arr,0,1,dp);
        if(ans >= 0)
            cout << ans << "\n";
        else cout << "-1\n";
    }
}


int main() {
    
    clock_t start = clock();
    
    io_file();
    code_here();
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}
