
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

bool rec(ll x1, ll y1, ll x2, ll y2, ll ct) {
	if(x1 <= 0 || y1 <=0 || x1 > 8 || y1 > 8 || ct > 100) return false;
	if((x1 == x2) && (y1 == y2)) return true;
	return (rec(x1+1, y1+2, x2, y2, ct+1) || rec(x1-1, y1+2, x2, y2, ct+1) || rec(x1+2, y1+1, x2, y2, ct+1) || rec(x1-2, y1+1, x2, y2, ct+1) || rec(x1+1, y1-2, x2, y2, ct+1) || rec(x1-1, y1-2, x2, y2, ct+1) || rec(x1+2, y1-1, x2, y2, ct+1) || rec(x1-2, y1-1, x2, y2, ct+1));
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
    	ll x1, y1, x2, y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	if((x2+y2-x1-y1)%2==0) cout << "YES\n";
    	else cout << "NO\n";
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
