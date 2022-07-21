
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld	long double
#define mod 1000000007
#define inf 1e18
#define pb emplace_back
#define vi vector<ll>
#define vii vector<vector<ll>>
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

vi get_max_prime_factors(ll n) {
	set<ll> p;
    while (n % 2 == 0) {
        p.insert(2);
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            p.insert(i);
            n = n/i;
        }
    }
    if (n > 2) p.insert(n);
    vi ret(p.begin(), p.end());
    return ret;
}

void code_here() {
    ll t; cin >> t;
    while(t--) {
    	ll n,q; cin >> n >> q;
    	while(q--) {
    		ll u,v; cin >> u >> v;
    		ll g = __gcd(u,v);
    		ll ans = 0;
    		if(g>1) ans = (u/g) + (v/g);
    		else {
    			vi up = get_max_prime_factors(u);
    			vi pv = get_max_prime_factors(v);
    			ll umx, vmx, mx = 0;
    			for(auto a: up) {
    				for(auto b: pv) {
    					ll prod = a*b;
    					if(prod > mx) umx = a, vmx = b;
    				}
    			}
                cout
    			ans = umx + vmx + (u/umx) + (v/vmx);
    		}
    		cout << ans << "\n";
    	}

    }
}


int main() {
    
    clock_t start = clock();
    
    // io_file();
    code_here();
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}
