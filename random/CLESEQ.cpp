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
        ll n,k; cin >> n >> k;
        vi v;
        loop(i,0,n) {
            ll x; cin >> x;
            if(i==0) v.pb(x);
            else if(v.back() != x) v.pb(x);
        }
        n = v.size();
        ll total_ugliness = 0;
        loop(i,0,n-1)
            if(v[i]!=v[i+1]) total_ugliness++;
        vi ans(k+1,total_ugliness);
        loop(i,0,n) {
            if(i-1>=0) ans[v[i]]--;
            if(i+1<n) ans[v[i]]++;
            if(i-1>=0 && i+1<n && v[i+1]!=v[i-1]) ans[v[i]]++;
        }
        loop(i,1,k+1) cout << ans[i] << " ";
        cout << "\n";
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