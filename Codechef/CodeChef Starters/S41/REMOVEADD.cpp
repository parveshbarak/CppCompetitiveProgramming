
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


void code_here() {
    ll t; cin >> t;
    while(t--) {
    	ll n; cin >> n;
    	vi arr(n,0);
    	set<ll> front, back;
    	loop(i,0,n) cin >> arr[i];
    	unordered_map<ll,set<ll>> ump;
    	loop(i,0,n) ump[arr[i]].insert(i);
        ll cmn = 0;
    	for(auto [x,y] : ump) {
    		if(y.size() == 1) continue;
    		ll mx = 0;
    		for(auto z: y) {
    			ll loc_min = min(z+1, (n-z));
    			if(loc_min > mx) mx = loc_min;
    		}
            // To handle special case:-
            set<int> commons;
            for(auto z: y) {
                ll loc_min = min(z+1, (n-z));
                if(loc_min == mx) commons.insert(z);
            }
            cmn += commons.size()-1;
    		for(auto z: y) {
    			if(commons.find(z) == commons.end()) {
    				if(z < n-z-1) cout << z+1 << " ", front.insert(z+1);
    				else back.insert(n-z);
    			}
                // else cout << z << " ";
    		}
    	}
    	ll ans = 0;
    	auto it1 = front.end(), it2 = back.end();
    	ll a = *it1, b = *it2;
    	if(front.size() == 0) a = 0;
    	if(back.size() == 0) b = 0;

        if(a<b) b += cmn;
        else a += cmn;

    	cout << a << " " << b << " ";
    	if(a < b) ans = 2*a+b;
    	else ans = 2*b+a;
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
