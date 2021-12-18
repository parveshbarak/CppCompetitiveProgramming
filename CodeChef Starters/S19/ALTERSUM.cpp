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
        vi arr(n); loop(i,0,n) cin >> arr[i];    
        vi a(n,0), b(n,0); a[0] = arr[0]; b[0] = -1*arr[0];
        for(ll i=1;i<n;i++) { 
            if(i%2==1) a[i] = a[i-1] - arr[i];
            else a[i] = a[i-1] + arr[i];
        }
        for(ll i=1;i<n;i++) {
            if(i%2==0) b[i] = b[i-1] - arr[i];
            else b[i] = b[i-1] + arr[i];
        }
        ll ans = INT_MIN;
        if(n%2==1) {
            for(ll i=0;i<n;i+=2) {
                ll x = b[n-1] - b[i] + a[i];
                ans = max(x,ans);
            }
        }
        else {
            for(ll i=0;i<n;i+=2) {
                ll x = b[n-1] - b[i] - a[i];
                ans = max(x,ans);
            }
        }
        cout << ans << "\n";
    }
}


int main() {
    
    clock_t start = clock();
    
    // io_file();
    code_here();
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}




#include<bits/stdc++.h>
using namespace std;

//@Himanshu_nobee

#define f(i,s,e) for(long long i=s;i<e;i++)
#define endl "\n"
#define ll long long

int t;
int main()
{
    //@Himanshu_nobee
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--)
    {
        //@Himanshu_nobee
        ll n;cin>>n;
        ll v[n];f(i,0,n) cin>>v[i];
        vector<ll> dp(n+1);
        f(i,0,n)
        {
            if(i%2) dp[i+1]=dp[i]-v[i];
            else dp[i+1]=dp[i]+v[i];
        }
        ll ans=dp[n];
        if(n%2){
            f(i,0,n)
            {
                ll pre=dp[i];
                ll post=dp[n]-dp[i+1];
                ans=max(ans,pre-post+v[i]);
            }
        }
        else {
            f(i,0,n)
            {
                ll pre=dp[i];
                ll post=dp[n]-dp[i+1];
                ans=max(ans,pre-post-v[i]);
            }
        }
        cout<<ans<<endl;
}}
