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
        ll n,k,ans=0; cin >> n >> k;
        vector<ll> arr(n,0);
        loop(i,0,n) cin >> arr[i];
        bool flag = true;
        vector<bool> fags(n,false);
        loop(i,0,n) { if(arr[i] > 0) fags[i] = true;}
        loop(i,0,n) ans += arr[i];
        if(ans == 0) cout << 0 << "\n";
        else {
            ans = 0;

            while(k>0 && flag) {
                flag = false;
                loop(i,0,n) {
                    if(arr[i] == 0) flag = true;
                }
                loop(i,0,n) {
                    if(arr[i] > 0 && fags[i] && flag) {
                        if(i==0) { arr[i+1]++; arr[n-1]++; }
                        else if(i==n-1)  { arr[i-1]++; arr[0]++; }
                        else { arr[i-1]++; arr[i+1]++; }
                    }
                }
                loop(i,0,n) { if(arr[i] > 0) fags[i] = true;}
                if(flag) k--;
            }

            loop(i,0,n) ans += arr[i];
            // loop(i,0,n) cout << arr[i] << " ";

            ans += n*k*2;
            cout << ans << "\n";
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