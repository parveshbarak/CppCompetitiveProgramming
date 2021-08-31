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

ll countSetBits(ll n) {
    if (n == 0)
        return 0;
    else
        return (n & 1) + countSetBits(n >> 1);
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n,m; cin >> n >> m;
        ll arr[n],sum=0; vi ans;
        loop(i,0,n) cin >> arr[i], sum += arr[i];
        ll j = n-1, ct=0, k=0;
        bool flag = false;
        ll r_sum = sum;
        if(sum%m == 0) flag = true;
        if(flag) cout << 0 << "\n";
        else {
            while(j>0) {
                if(sum%m == 0)
                    ans.pb(ct);
                sum -= arr[j]; j--; ct++;
            }
            j= n-1, ct=0; sum = r_sum;
            while(j>n/2) {
                if(sum%m == 0)
                    ans.pb(ct);
                sum = sum - arr[j] - arr[k]; j--; k++; ct++;
            }
            j= n-1, ct=0,k=0; sum = r_sum;
            while(j>k) {
                cerr << " " << sum << " " << arr[k] << " " << arr[j]  << " " << ct << "   ";
                if((sum-arr[k]-arr[j])%m == 0) {
                    sum = sum - arr[j] - arr[k]; j--; k++; ct++;
                    ans.pb(ct); 
                } else if((sum-arr[j])%m == 0) {
                    sum = sum - arr[j]; j--; ct++;
                    ans.pb(ct);
                } else {
                    sum = sum - arr[j]; j--; ct++;
                }
            }

            ll result = INT_MAX;
            ll sz = ans.size();

            loop(i,0,sz)
                cerr << ans[i] << " ";
            cerr << "\n";

            // loop(i,0,sz) {
            //     loop(p,0,sz)
            //         ans.pb(ans[i]+ans[p]);
            // }

            loop(i,0,ans.size()) {
                ll x = countSetBits(ans[i]);
                result = min(result,x);
            }
            if(result == INT_MAX)
                result = -1;
            cout << result << "\n";
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