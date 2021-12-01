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
        ll n,p,q; cin >> n >> p >> q;
        string s; cin >> s;
        p = abs(p); q = abs(q);
        if(p+q > n) cout << "N0\n";
        else {
            ll o=0,z=0;
            loop(i,0,n) {
                if(s[i]=='0') z++;
                else o++;
            }
            while(p>0 && q>0 && z>0) {
                p -= 1; z -= 1;
                if(z>0) q -= 1, z -= 1;
            }
            if(z>0 && p==0 && q==0) {
                o = o-z;
                if(o>=0) {
                    if(o%2==0) cout << "YES\n";
                    else cout << "NO\n";
                }
                else {
                    if(o%4==0) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
            else {
                if(z>0) {
                    z -= z/4;
                    o = o-z;
                }
                while(p>0 && o>0) p--, o--;
                while(q>0 && o>0) q--, o--;
                if(o>0) {
                    if(o%2==0) cout << "YES\n";
                    else cout << "NO\n";
                }
                else {
                    if(p==o && q==0) cout << "YES\n";
                    else cout << "NO\n";
                }
            }
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


// #include <iostream>
// using namespace std;

// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n , p ,q;
// 	    cin>>n>>p>>q;
// 	    string s;
// 	    cin>>s;
// 	    int zero = 0 , ones = 0;
// 	    for(auto x : s){
// 	        zero+=(x == '0');
// 	        ones+=(x == '1');
// 	    }
// 	    p = abs(p);
// 	    q = abs(q);
// 	    int x = p , y = q;
// 	    if(zero %2 == 0){
// 	        x = abs(x-zero/2);
// 	        y = abs( y-zero/2);
	       
// 	        if(x+y <= ones && (ones-x-y)%2==0) cout<<"Yes\n";
// 	        else cout << "NO\n";
// 	    }
// 	    else {
// 	        x = abs( x -zero/2);
// 	        y = abs(y - (1+zero/2));
// 	        if(x+y <= ones && (ones-x-y)%2==0) cout<<"Yes\n";
// 	        else cout << "NO\n";
// 	        // else {
// 	        //     x = p;
// 	        //     y =q;
// 	        //     x = abs(x-(1+zero/2));
// 	        //     y = abs(y - (zero/2));
// 	        //     if(x+y <= ones){
// 	        //          cout<<"Yes\n";
// 	        //          continue;
// 	        //     }
// 	        // }
// 	    }
// 	    cout<<"NO\n";
// 	}
// 	return 0;
// }