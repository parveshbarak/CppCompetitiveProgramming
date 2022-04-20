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
        ll n; cin >> n;
        vi arr(n+1,0); loop(i,1,n+1) cin >> arr[i];
        ll ans = INT_MAX, k = (n+1)/2;
        sort(arr.begin(),arr.end());
        for(ll i=1;i<k;i++) {
            ll x = arr[i];
            ll j = i+(i-1);
            // cout << x << " ";
            if((n-j)%2==0) {
                ll y = arr[(n-j)/2 + j];
                ll z = arr[(n-j)/2 + j+1];
                // cout << y << " " << z << " ";
                ll temp = min(abs(x-y),abs(x-z));
                ans = min(ans,temp);
            }
            else {
                ll y = arr[(n-j)/2 + j];
                // cout << y << " ";
                ans = min(ans,abs(x-y));
            }
            // cout << "\n";
        }
        // cout<<"\n";
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