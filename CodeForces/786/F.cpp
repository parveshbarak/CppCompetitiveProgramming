
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
    	vi arr(n); loop(i,0,n) cin >> arr[i];
    	// vi pre = arr, post = arr;
    	// for(int i=1;i<n;i++) pre[i] += pre[i-1];
    	// for(int i=n-2;i>=0;i--) post[i] += post[i+1];
    	ll i=1, j=n-2, wt1=arr[0], wt2=arr[n-1], ans = 0;
    	while(i<=j) {
    		cout << wt1 << " " << wt2 << " ";
    		if(wt1==wt2) ans = i+(n-j-1), wt1 += arr[i++], wt2 += arr[j--];
    		else if(wt1>wt2) wt2 += arr[j--];
    		else if(wt1<wt2) wt1 += arr[i++];
    	}
    	if(wt1==wt2) ans = n;
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
