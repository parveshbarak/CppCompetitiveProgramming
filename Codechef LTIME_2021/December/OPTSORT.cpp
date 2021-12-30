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
        freopen("/home/parvesh/Documents/Practice/io_files/input.txt","r", stdin);
        freopen("/home/parvesh/Documents/Practice/io_files/output.txt","w", stdout);
        freopen("/home/parvesh/Documents/Practice/io_files/error.txt","w", stderr);
    #endif
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vi arr(n); loop(i,0,n) cin >> arr[i];
        vector<pair<ll,ll>> chuncks;
        ll i = 0;
        while(i<n) {
            ll mn = INT_MAX, mx = INT_MIN;
            ll j = i, x = arr[i];
            while(j<n && arr[j] >= x) x = arr[j], mn = min(mn,arr[j]), mx = max(mx,arr[j]), j++;
            chuncks.push_back({mn,mx});
        }
        ll m = chuncks.size();
        vector<ll> dp(m,INT_MAX);
        dp[0] = chuncks[0].second - chuncks[0].first;
        for(ll i=1;i<m;i++) {
            ll x = dp[i];
            for(ll j = 0;j<=i;j++) {
                dp[i] = min(dp[i],dp[i-j]+(chuncks[]))
            }
        }
        
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