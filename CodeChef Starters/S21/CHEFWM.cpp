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


bool isPrime(int n) {
    if (n <= 1) return false;
    for (ll i = 2; i*i <= (n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}


void code_here() {
    vector<bool> prime(1005,true);
    for(ll p = 2; p * p < 1005; p++) {
        if (prime[p] == true) {
            for (ll i = p * p; i < 1005; i += p)
                prime[i] = false;
        }
    }

    ll t; cin >> t;
    while(t--) {
        ll x,y; cin >> x >> y;
        ll ans = 0; vi b;
        if(isPrime(y)) b.pb(y);
        for(ll i=2;i*i<=y;i++) {
            if(prime[i] && y%i==0) b.pb(y/i);
        } 
        ll n = b.size();
        // cout << n << " ";
        // loop(i,0,n) cout << b[i] << " ";
        for(ll i=0;i<n;i++) {
            bool flag = true;
            for(ll j=i+1;j<n;j++) {
                if((b[i]%b[j]==0) || (b[j]%b[i]==0)) flag = false;
            }
            if(flag) ans++;
        }
        // cout << ans << "     ";
        n = ans;
        if(y==1) cout << 0 << "\n";
        else if(min(n,x)==0 || min(n,x) == 1) {
            cout << min(n,x) << "\n";
        } else {
            ll z;
            for(ll i=n;i>0;i--) {
                if(x%i==0) {
                    z = i; break;
                }
            }
            cout << z << "\n";
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