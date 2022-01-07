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
#define get_mid(l,r) (l+(r-l)/2)
#define loop(i,a,b) for(ll i=(a);i<(b);i++)
#define revloop(i,a,b) for(ll i=(a);i>=(b);i--)
#define printarr(arr,a,b) for(ll z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;



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
        ll n,m,k;
        vp moves;
        cin >> n >> m >> k;
        loop(i,0,n*m){
            ll x,y;
            cin >> x >> y;
            moves.pb(mp(x,y));
        }

        ll l=0,h=n*m-1,ans=n*m;
        while(l<=h) {
            cerr << l << " " << h << " " << ans <<"\n";
            ll mid = get_mid(l,h);
            ll a[n+1][m+1];
            loop(i,0,n+1) {
                loop(j,0,m+1)
                    a[i][j] = 0;
            }

            //Populate upto mid(m) moves
            loop(i,0,mid+1) {
                if(i%2==0)
                    a[moves[i].ff][moves[i].ss] = 1;
                else
                    a[moves[i].ff][moves[i].ss] = -1;
            }

            // Prefix Sum
            loop(i,1,n+1) {
                loop(j,1,m+1) {
                    a[i][j] += a[i][j-1] + a[i-1][j] - a[i-1][j-1];
                }
            }

            //debug
            // loop(i,1,n+1) {
            //     loop(j,1,m+1) {
            //         cerr << a[i][j] << " ";
            //     }
            //     cerr << "\n";
            // }
            // cerr << "\n";

            //make found bool false and check if we found or not
            bool found = false;
            loop(i,k,n+1) {
                loop(j,k,m+1) {
                    ll cnt = a[i][j] - a[i-k][j] - a[i][j-k] + a[i-k][j-k];
                    if(abs(cnt)==k*k)
                        found=true;
                }
            }

            // if found ans = mid, h = mid-1;
            if(found) {
                ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }

        if(ans == n*m)
            cout << "Draw\n";
        else if(ans%2==0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
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