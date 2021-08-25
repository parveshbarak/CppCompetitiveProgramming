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
		ll n,p,k;
		cin >> n >> p >> k;
		ll q = p/k;
		ll r = p%k;
		ll ans = 0;
		loop(i,0,r) {
			ans = ans + (n-1-i)/k + 1;
		}
		ll x = (n-1)%k;
		ll sub = x*(x+1)/2;
		ll y;
		if(x>=r) {
			y = x-r;
		}
		else {
			ll z = (n-2-x)%k;
			sub += z*(z+1)/2;
			y = x+z+1-r;
		} ll ad = y*(y+1)/2;
		ll result = (n*r - sub + ad - (r*(r+1)/2))/k + r; 
		ans = ans + 1 + q;
		result += 1 + q;
		cout << ans  << " " << result << "\n";
		// cout << result << "\n";
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