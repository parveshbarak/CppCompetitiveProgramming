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
        vi arr(n,0); loop(i,0,n) cin >> arr[i];
        sort(arr.begin(),arr.end());
        if(n==2) cout << 0 << "\n";
        else if(n==3) {
            cout << min(arr[1]-arr[0], arr[2]-arr[1]) << "\n";
        } 
        else {
            ll fmx = arr[n-1]; vi a(n-1,0); vi b(n-1,0);
            loop(i,0,n-1) a[i] = fmx-arr[i];
            loop(i,0,n-1) {
                if(i==0) b[i] = arr[n-2] - arr[1];
                else if(i==n-2) b[i] = arr[n-3] - arr[0];
                else b[i] = arr[n-2] - arr[0];
            }
            ll m = INT_MAX;
            loop(i,0,n-1) m = min(m,abs(b[i]-a[i]));

            ll a1=0,b1=0, b2=0,a4 =INT_MAX;
            if((n-1)%2==0) {
                ll a = (n-1)/2; ll b= (n-1)/2 + 1;
                loop(i,1,n) {
                    a1+= abs(arr[i]-arr[a]);
                    b1 += abs(arr[i]-arr[b]);
                }
                a4 = min(a1,b1);
            } else {
                ll a = n/2;
                loop(i,1,n) b2+= abs(arr[i]-arr[a]);
                a4 = b2;
            }

            ll c1=0,d1=0,d2=0, b4 = INT_MAX;
            if((n-1)%2==0) {
                ll a = (n-1)/2; ll b= (n-1)/2 - 1;
                loop(i,0,n-1) c1+= abs(arr[i]-arr[a]) , d1 += abs(arr[i]-arr[b]);
                b4 = min(c1,d1);
            } else {
                ll a = (n-1)/2;
                loop(i,0,n-1) d2+= abs(arr[i]-arr[a]);
                b4 = d2;
            }

            // cout << m << " " << a4 << " " << b4 << "   ";
            cout << min({m,b4,a4}) << "\n";
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