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
        string s; cin >> s;
        vi arr(n,0);
        for(ll i=0;i<n-1;i++) {
            int x = int(s[i]-'0'), y = int(s[i+1]-'0');
            int z = (10 + y - x)%10;
            arr[i+1] = z;
        }
        loop(i,1,n) arr[i] += arr[i-1];
        // loop(i,0,n) cout << arr[i] << " ";
        // cout << "\n";
        ll ct = 0; bool f = true;
        ll prev = 0;
        for(int i=0;i<n;i++) {
            ll x = int(s[i]-'0'); 
            ll cost = 0; bool flag = true;
            if(s[i]=='0') cost = prev;
            else cost = (10 - x) + arr[i];
            // cout << cost << " ";
            prev = cost;
            if(cost > k) {cout << ct << "\n"; f = false; break; }
            else ct++;
        }
        if(f) cout << ct << "\n";
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