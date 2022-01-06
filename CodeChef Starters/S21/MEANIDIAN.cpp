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
        ll n,sum = 0; cin >> n;
        vi arr(n); loop(i,0,n) cin >> arr[i], sum += arr[i];
        sort(arr.begin(),arr.end());
        ll median = arr[(n)/2];
        ll mean = sum/n;
        if(mean == median) cout << 0 << "\n";
        else if(mean < median) {
            ll ans = (median*n) - sum;
            cout << ans << "\n";
        } else {
            ll s = sum - median;
            ll new_med;
            ll lo = mean+1, hi = 1e9;
            while(lo < hi) {
                ll mid = (lo+hi)/2;
                if((mid*n < mid+s) && (n*(mid+1) >= mid+s+1)) {
                     new_med = mid+1; break;
                }
                if(mid*n < mid+s) lo = mid+1;
                else hi = mid;
            }
            ll ans = new_med*n - sum;
            cout << ans << "\n";
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