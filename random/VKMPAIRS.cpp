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

ll power(ll x, ll y, ll m) {
    if(y==0) return 1;
    ll p = power(x,y/2,m)%m;
    p = (p*p)%m;
    return (y%2==0) ? p : (x*p)%m;
}

ll inverse(ll x, ll p) {
    return power(x,p-2,p);
}

void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,m,p; cin >> n >> m >> p;
        vi a(n), b(m);
        loop(i,0,n) cin >> a[i];
        loop(i,0,m) cin >> b[i];
        unordered_map<ll,ll> ct;
        for(auto x: b) ct[x]++;
        ll ans = 0;
        for(auto x: a) {
            if(x%p == 0) continue;
            ll y = inverse(x,p)^x;
            ans += ct[y];
        }
        cout << ans << "\n";
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