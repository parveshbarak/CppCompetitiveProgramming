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
        vector<string> arr(n-2);
        loop(i,0,n-2) cin >> arr[i];
        string ans = "";
        if(n==3) ans += arr[0][0], ans+= arr[0][1] , ans += "a";
        else {
            bool flag = false;
            ans += arr[0][0];
            loop(i,0,n-2) {
                if(i==n-3) ans+= arr[i][1];
                else {
                    if(arr[i][1] == arr[i+1][0]) ans+=arr[i][1];
                    else ans+= arr[i][1], ans += arr[i+1][0], flag = true;
                }
            }
            if(!flag) ans += "a";
        }
        // cout << "\n";
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




// ll n; cin >> n;
//         vector<string> arr(n);
//         loop(i,0,n-2) cin >> arr[i];
//         cout << "\n";
//         loop(i,0,n-2) cout << arr[i] << " ";
//         cout << "\n";

//         string ans = "";
//         if(n==3) ans += arr[0][0], ans+= arr[0][1] , ans += "a";
//         else {
//             ans += arr[0][0];
//             loop(i,0,n-2) {
//                 if(i==n-3) ans+= arr[i][1];
//                 else {
//                     if(arr[i][1] == arr[i+1][0]) ans+=arr[i][1];
//                     else ans+= arr[i][1], ans += arr[i][0];
//                 }
//             }
//             cout << ans << "\n";
//         }