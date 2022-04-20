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
    ll h = 100005;
    vector<bool> dp(h,false);
    dp[1] = true;
    for(i=2;i<h;i++) {
        if(i%2 != 0) dp[i] = !(dp[i-1]);
        else {
            vector<int> pos; int x = i/2;
            pos.push_back(x);
            while(x>0) {
                if(x%2==0) { x = x/2; pos.push_back(x) };
                else x = x/2;
            }
            bool flag = true;
            for(int i=0;i<pos.size();i++) flag = (flag & dp[pos[i]]);
            dp[i] = !(flag);
        }
    }
    while(t--) {
        ll n; cin >> n;
        // if(n==1 || n==3 || n==4 || n==7 || n==8 || n==10 || n==12 || n==15 || n==16 || n==18 || n==20)
        //     cout << "Alice\n";
        // else
        //     cout << "Bob\n";

        if(dp[n]) cout << "Alice\n";
        else cout << "Bob\n";
        
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