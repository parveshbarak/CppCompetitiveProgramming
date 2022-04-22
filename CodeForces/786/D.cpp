
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

bool check(string s) {
	ll r=0, w=0, b=0;
	for(auto c: s) {
		if(c=='W') w++;
		if(c=='R') r++;
		if(c=='B') b++;
	}
	if((b>0 && r==0) || (r>0 && b==0)) return true;
	return false;
}

void code_here() {
    ll t; cin >> t;
    while(t--) {
    	ll n; cin >> n;
    	string s; cin >> s;
		if(check(s)) cout << "NO\n";
		else {
			bool flag = false;;
			ll i=0;
			while(i<n) {
				ll j = i;
				string t = "";
				while(j<n && s[j] != 'W') t+=s[j++];
				if(check(t)) flag = true;
				// cout << t << " ";
				i = j+1;
			}
			if(flag) cout << "NO\n";
			else cout << "YES\n";
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
