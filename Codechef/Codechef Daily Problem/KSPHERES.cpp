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
    // ll t; cin >> t;
    ll t = 1;
    while(t--) {
        ll n,m,c; cin >> n >> m >> c;
        vi up(n), lo(m);
        vi a(1001,0), b(1001,0), dp(1001,0), ans(c);
        loop(i,0,n) cin >> up[i], a[up[i]]++;
        loop(i,0,m) cin >> lo[i], b[lo[i]]++;
        // Now my a will store all for a, and b will store thewire prefixes
        loop(i,1,c+1) a[i] *= b[i], a[i]%mod;
        loop(i,1,c+1) dp[i] = a[i], b[i] = (b[i-1]+a[i])%mod;
        for(int i=0;i<=c;i++) cout << a[i] << " ";
        loop(i,1,c+1) {
            loop(j,1,c+1) dp[j] = (a[j]*b[j-1])%mod;
            loop(j,1,c+1) b[j] = (b[j-1]+dp[j])%mod;
            ans[i-1] = b[c];
        }
        loop(i,0,c) cout << ans[i] << " ";
        cout << "\n";
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





// #include <iostream>
// #include <cstdio>
// #include <algorithm>
// #include <vector>
// #include <string>
// #include <memory.h>
// #include <assert.h>

// using namespace std;

// const int maxC = 1000;
// const int maxT = 100000;
// const int maxN = 100000;
// int testNumber = 0;

// const long long mod = 1000000007;

// long long a[maxC+1];
// long long b[maxC+1];
// long long dp[maxC+1];
// int tt[maxN+1];
// int bb[maxN+1];
// int n,m,c;
// int ans[maxC+1];

// void solve() // solution
// {
// 	memset(a, 0, sizeof(a));
// 	memset(b, 0, sizeof(b));
// 	for (int i = 0; i<n; ++i)    // we calculate amount of upper halves of each radius
// 	{
// 		int x = tt[i];
// 		a[x]++; 
// 	}
// 	for (int j = 0; j<m; ++j)    // we calculate amount of lower halves of each radius
// 	{
// 		int x = bb[j];
// 		b[x]++;
// 	}
// 	b[0] = 0;
// 	for (int i = 1; i <= c; ++i) a[i] *= b[i], a[i] %= mod; // we calculate amount of spheres of each radius we can build
// 	for (int i = 1; i <= c; ++i) dp[i] = a[i], b[i] = b[i - 1] + dp[i], b[i] %= mod; // base of dynamic programming 
	
//     for(int i=0;i<=c;i++) cout << a[i] << " ";
// 	for (int len = 1; len <= c; ++len) // for each len-sequence
// 	{
// 		for (int i = 1; i <= c; ++i)
// 			dp[i] = a[i] * b[i - 1], dp[i] %= mod; // calculating dynamic programming array for each len-sequence
// 		for (int i = 1; i <= c; ++i)
// 			b[i] = b[i - 1] + dp[i], b[i] %= mod; // particular sums
// 		ans[len-1] = b[c]; // we know result for each len-sequence
// 	}
// }


// int main()
// {
//     // int T;
//     // scanf("%d",&T);
//     // while(T--)
//     // {
//         scanf("%d%d%d", &n, &m, &c);
//         for(int j = 0; j<n; ++j)
//         {
//             scanf("%d", &tt[j]); // reading upper halves radiuses
//         }
//         for(int j = 0; j<m; ++j)
//         {
//             scanf("%d", &bb[j]); // reading lower halves radiuses
//         }
//         solve();
//         for(int i=0;i<c;++i)
//         {
//             printf("%d ", ans[i]); // writing answers
//         }
//         printf("\n");
//     // }
// }