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
        if(k==0) cout << "YES\n0\n";
        else if(k%2==0) cout << "NO\n";
        else {
            ll x = log2(k) + 1;
            ll y = (1<<x) - 1;
            // cout << y << "  ";
            ll k2 = k;
            ll i=0; bool flag = false;
            while(k2<=n) {
                if(k2==y) {
                    flag = true; break;
                } else {
                    // cout << k2 << " " << y << "    ";
                    y-= (1<<i);
                    k2+= (1<<i);
                    // cout << k2 << " " << y << "    ";
                    i++;
                }
            }
            if(flag) {
                cout << "YES\n";
                ll j=0;
                if(i==0) {
                    cout << (ll)log2(k)+1 << "\n";
                    while(k>0) {
                        cout << (1<<j) << "\n";
                        k -= (1<<j); j++;
                    }
                } else {
                    vi ans;
                    while(i--) {
                        ans.pb(k+(1<<j)); j++;
                    }
                    ll res =1;
                    ans.pb(1); k2-= (1<<j);
                    while(k2>0) {
                        res+=(1<<j);
                        ans.pb(res);
                        k2 -= (1<<j); j++;
                    }
                    cout << ans.size() << "\n";
                    loop(l,0,ans.size()) cout << ans[l] << "\n";
                }
            } else cout << "NO\n";
        }

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


// 9
// 5 0
// 3 3
// 2 2
// 6 5
// 13 9
// 7 7
// 15 9
// 16 11
// 15  51



        // ll n,k; cin >> n >> k;
        // if(k==0) cout << "YES\n0\n";
        // else if(k%2==0) cout << "NO\n";
        // else {
        //     ll z = log2(n)+1;
        //     ll y = (1<<z) - 1;
        //     ll x1 = y - k;
        //     if((n-k)*2 >= x1) { 
        //         ll x = (1<<(log2(k)+1))-1;
        //         cout << "YES\n";
        //         cout << z << "\n";
        //         ll ans = 0;
        //         if(x==0) {
        //             ll j =0; 
        //             while(z--) { ans = (1<<j); cout << ans << "\n"; j++; }
        //         } else {
        //             ll a = x/2; a = log2(a) + 1;
        //             ll j= 0; ll b = a;
        //             while(a--) { ans = (1<<j); cout << k+ans << "\n"; j++; }
        //             z = z-b-1; cout << 1 << "\n";
        //             while(z--) {
        //                 cout << (1<<j) +1 << "\n"; j++;
        //             }
        //         }
        //     }
        //     else cout << "NO\n";

        // }