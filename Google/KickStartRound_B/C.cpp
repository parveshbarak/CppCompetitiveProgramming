
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


void first_time() {
    ll t; cin >> t;
    ll c = 1;
    while(t--) {
        ll n,d; cin >> n >> d;
        vector<ll> arr(n);
        bool flag = true;
        for(ll i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i]>1) flag = false;
        }
        if( flag) {
            ll trans = 0;
            ll i = 0;
            while(i<n) {
                ll x = arr[i];
                while(i<n && x==arr[i]) i++;
                trans++;
            }
            if(arr[0]==0) trans--;
            if(arr[n-1]==0) trans--;
            cout << "Case #" << c++ << ": " << (trans+1)/2 << "\n";
        }
    }
}



ll dp[405][405][2];
ll rec(vector<ll>&arr, ll l, ll r, ll x, ll d) {
    if(l>=r) return 0;
    if(dp[l][r][x] != -1) return dp[l][r][x];
    ll ans = 1e9+10;
    if(!x) {
        ll a1 = rec(arr,l+1,r,0,d);
        ll a2 = rec(arr,l+1,r,1,d);
        ans = min(ans, a1+min(abs(arr[l]-arr[l+1]), d-abs(arr[l]-arr[l+1])));
        ans = min(ans, a2+min(abs(arr[l]-arr[r]), d-abs(arr[l]-arr[r])));
    } else {
        ll a1 = rec(arr,l,r-1,0,d);
        ll a2 = rec(arr,l,r-1,1,d);
        ans = min(ans, a1+min(abs(arr[r]-arr[l]), d-abs(arr[r]-arr[l])));
        ans = min(ans, a2+min(abs(arr[r]-arr[r-1]), d-abs(arr[r]-arr[r-1])));
    }
    return dp[l][r][x] = ans;
}

void second_time() {
    ll t; cin >> t;
    ll c = 1;
    while(t--) {
        ll n,d; cin >> n >> d;
        vector<ll> arr(n);
        for(ll i=0;i<n;i++) cin >> arr[i];
        memset(dp, -1, sizeof(dp));
        ll ans = INT_MAX;
        ans = min(ans, rec(arr,0,n-1,0,d) + min(arr[0],d-arr[0]));
        ans = min(ans, rec(arr,0,n-1,1,d) + min(arr[n-1], d-arr[n-1]));
        cout << "Case #" << c++ << ": " << ans << "\n";
    }
}


void code_here() {
    // first_time()
    second_time();
}


int main() {
    
    clock_t start = clock();
    
    io_file();
    code_here();
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}
