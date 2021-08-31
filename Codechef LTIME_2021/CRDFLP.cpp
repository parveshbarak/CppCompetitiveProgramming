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
        ll arr[n], arr2[n];
        vector<vector<ll>> a(n,vector<ll>(32,0));
        vector<vector<ll>> b(n,vector<ll>(32,0));
        vector<bool> flip(n,true);

        loop(i,0,n) cin >> arr[i];
        loop(i,0,n) cin >> arr2[i];

        int ar[n],ar2[n];
        loop(i,0,n) {
            ar[i] = arr[i]; ar2[i] = arr2[i];
        }

        loop(i,0,n) {
            loop(j,0,32) {
                a[i][j] = (arr[i]&1); arr[i] /= 2;
                b[i][j] = (arr2[i]&1); arr2[i] /= 2;
            }
        }

        revloop(i,31,0) {
            vector<ll> idx; bool poss = true;
            loop(j,0,n) {
                if(poss) {
                    if(a[j][i] == 0 && b[j][i] == 0)
                        poss = false;
                    else if(a[j][i] == 0 && b[j][i] == 1) {
                        if(flip[j])
                            idx.pb(j);
                        else
                            poss = false;
                    }
                }
            }
            if(poss) {
                loop(r,0,idx.size()) {
                    flip[idx[r]] = false;
                    vi temp = a[idx[r]];
                    a[idx[r]] = b[idx[r]];
                    b[idx[r]] = temp;
                }
            }
            idx.clear();
        }

        ll ct=0;
        loop(i,0,n) {
            if(!(flip[i])) {
                ct++;
                ar[i] = ar2[i];
            }
        }


        // loop(i,0,n) {
        //     cerr << flip[i] << " ";
        // }
        // cerr << "\n";

        // loop(i,0,n) {
        //     cerr << ar[i] << " ";
        // }
        // cerr << "\n\n";

        ll ans = ar[0];
        loop(i,1,n) {
            ans = (ans&ar[i]);
        }
        
        cout << ans << " " << ct << "\n";
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