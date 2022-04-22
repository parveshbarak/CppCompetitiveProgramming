
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


void code_here() {
    ll t; cin >> t;
    while(t--) {
    	ll n; cin >> n;
    	vector<string>arr;
    	unordered_map<string, vector<ll>> mp;
    	vector<vector<ll>> v1(11), v2(11);
    	for(int i=0;i<n;i++) {
    		string x; cin >> x;
    		arr.push_back(x);
    		mp[x].push_back(i);
    		v1[x[0]-'a'].push_back(i);
    		v2[x[1]-'a'].push_back(i);
    	}
    	ll ans = 0;
    	for(int i=0;i<n;i++) {
    		string x = arr[i];
    		ll a = v1[x[0]-'a'].size();
    		ll b = v2[x[1]-'a'].size();
    		ll c = mp[x].size();
    		a -= (upper_bound(v1[x[0]-'a'].begin(), v1[x[0]-'a'].end(), i) - v1[x[0]-'a'].begin());
    		b -= (upper_bound(v2[x[1]-'a'].begin(), v2[x[1]-'a'].end(), i) - v2[x[1]-'a'].begin());
    		c -= (upper_bound(mp[x].begin(), mp[x].end(), i) - mp[x].begin());
    		// if(x==y) d = 0;
    		// cout << a << " " << b  << " " << c << "\n";
    		ans += a+b-c-c;
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
