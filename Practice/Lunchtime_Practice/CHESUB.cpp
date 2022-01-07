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

ll dp[100005][105];
ll prefix_dp[100005][105];

void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        ll arr[n], b[k];
        loop(i,0,n)
            cin >> arr[i];
        loop(i,0,k)
            b[i] = i+1;

        // Initialising Dp and prefix_dp
        loop(i,0,n) {
            dp[i][0] = 0; prefix_dp[i][0] = 0;
            loop(j,1,k+1) {
                dp[i][j] = -inf;
                prefix_dp[i][j] = -inf;
            }
        }

        //base case :-
        dp[0][1] = arr[0]*b[0];
        prefix_dp[0][1] = dp[0][1];

        // other cases :
        loop(i,1,n){
            loop(j,1,k+1) {
                dp[i][j] = max(dp[i-1][j], prefix_dp[i-1][j-1]) + arr[i]*b[j-1];
                 // if(a[i] has been -ve dp[i][j] may be even less than -inf so ignore that)
                dp[i][j] = max(dp[i][j], (ll)-inf);
                prefix_dp[i][j] = max(prefix_dp[i-1][j], dp[i][j]);
            }
        }

        // loop(i,0,n){
        //     loop(j,0,k+1) {
        //         cerr << dp[i][j] << " ";
        //     }
        //     cerr << "\n";
        // } cerr << "\n";

        ll ans = -inf;
        loop(i,0,n) {
            ans = max(ans,dp[i][k]);
            // cerr << ans << " ";
        }

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