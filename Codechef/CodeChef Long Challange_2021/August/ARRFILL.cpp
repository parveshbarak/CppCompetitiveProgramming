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

ll get_lcm(ll a, ll b) {
    return (a*b)/__gcd(a,b);
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n, m;
        cin>>n>>m;
        vp queries;
        for (int i=0; i < m; i++) {
            ll x, y;
            cin>>x>>y;
            queries.pb(mp(x,y));
        }
        sort(queries.begin(), queries.end(), greater<pair<int,int>>());

        ll ans = 0, old_n = n, lcm = 1;
		
		for(int i =0;i<queries.size();i++){
			ll y2 = queries[i].second;
            lcm = (lcm*y2)/__gcd(lcm,y2);
            ans += (n - (old_n/lcm))*queries[i].first;
            n = old_n/lcm;
            // cerr << lcm << "  ";
            if (n == 0) break;
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