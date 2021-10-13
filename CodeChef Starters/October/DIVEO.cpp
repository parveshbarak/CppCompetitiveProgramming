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

void printDivisors(int n)
{
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                cout <<" "<< i;
 
            else // Otherwise print both
                cout << " "<< i << " " << n/i;
        }
    }
}

void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,a,b; cin >> n >> a >> b;
        vi ans;

        while (n%2 == 0) ans.pb(2), n = n/2;  
        for (int i = 3; i <= sqrt(n); i = i+2) { 
            while (n%i == 0) ans.pb(i), n = n/i;   
        } 
        if (n > 2) ans.pb(n);

        for (ll i=2; i<=sqrt(n); i+=2){
            if (n%i == 0){
                if (n/i == i) ans.pb(i);
                 else ans.pb(i) , ans.pb(n/i);
            }
        }
        ll ct = 0;
        if(a<0) {
            if(b>0) {
                bool flag = false;
                for(ll i=0;i<ans.size();i++) {
                    if(ans[i]%2==0) flag = true;
                    else ct += b;
                }
                if(flag) ct += a;
            } else {
                bool flag = false, f2 = false;
                for(ll i=0;i<ans.size();i++) {
                    // cout << ans[i] << " ";
                    if(ans[i]%2!=0) flag = true;
                    else f2 = true;;
                }
                if(flag && f2) ct+=a, flag = false, f2 = false;
                if(flag) ct += b;
                if(f2) ct+=a;
            }
        }else if(b<0) {
            if(a>0) {
                bool flag = false;
                for(ll i=0;i<ans.size();i++) {
                    if(ans[i]%2!=0) flag = true;
                    else ct += a;
                }
                if(flag && ct==0) ct += b;
            } else {
                bool flag = false, f2 = false;
                for(ll i=0;i<ans.size();i++) {
                    if(ans[i]%2==0) flag = true;
                    else f2 = true;;
                }
                if(flag && f2) ct+=a, flag = false, f2 = false;
                if(flag) ct += a;
                if(f2) ct+=b;
            }
        } else {
            for(ll i=0;i<ans.size();i++) {
                if(ans[i]%2==0) ct+=a;
                else ct += b;
            }
        } 
        cout << ct << "\n";
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