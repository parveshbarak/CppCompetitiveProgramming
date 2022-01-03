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

void primeFactors(ll n, unordered_map<ll,ll>&mp) {
	while (n % 2 == 0) 	{
        mp[2]++;
		n = n/2;
	}
	for (ll i = 3; i <= sqrt(n); i = i + 2) {
		while (n % i == 0) {
			mp[i]++;
			n = n/i;
		}
	}
    if (n > 2) mp[n]++;
}



void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        unordered_map<ll, ll> mp;
        primeFactors(n,mp);
        ll mx = 0, ans = n;
        for(auto x: mp) {
            if(x.second > mx) mx = x.second, ans = x.first;
            else if(x.second == mx) ans = min(ans,x.first);
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





// #include <bits/stdc++.h>
// #define print(x,...)
// 	#define IO
// 	using namespace std;
// #define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
// int ans = 0;
// typedef long long ll;
// long long smallestDivisor(long long n) {
//     if (n % 2 == 0) return 2;
//     for (int i = 3; i * i <= n; i += 2) {
//         if (n % i == 0) return i;
//     }
//     return n;
// }
// int main(int argc, char const *argv[])
// {
// 	IO;
// 	FastIO;
// 	clock_t start = clock();
// 	ll t; cin >> t;
//     while(t--) {
//         ll n; cin>>n;
//         cout<<smallestDivisor(n)<<"\n";
//     }
	
// 	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
// 	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
// 	return 0;

// }