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
        ll n,k; cin >> n >> k;
        if(k==n-1) cout << "-1\n";
        else {
            cout << k << " " << n-1 << "\n";
            vector<bool> vis(n,false);
            vis[n-1] = true; vis[k] = true;
            vp ans;
            revloop(i,n-2,0) {
                if(!vis[i]) {
                    ll x = log2(i), p = 0;
                    if(log2(i)==log2(i+1)) x+=1;
                    for(ll j=x;j>=0;j--) {
                        ll y = i&(1<<j);
                        if(y==0) p |= (1<<j);
                    }
                    p = p&((1<<x)-1);
                    if(p==k) p = 0;
                    cout << i << " " << p << "\n";
                    vis[i] = true; vis[p] = true;
                }
            }
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