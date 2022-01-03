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

void perm(set<vector<int>>&s, int n, vector<int>temp) {
    if(temp.size()==n) {
        s.insert(temp);
        return;
    }
    for(int i=0;i<3;i++) {
        temp.push_back(i);
        perm(s,n,temp);
        temp.pop_back();
    }
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        int n; cin >> n;
        ll ans = 0;
        if(n<3) cout << "0\n";
        else {
            set<vector<int>> s;
            perm(s,n,{});
            for(auto x: s) {
                for(int i=1;i<n-1;i++) {
                    if((x[i] > x[i-1] && x[i] > x[i+1]) || (x[i] < x[i-1] && x[i] < x[i+1])) ans++;
                }
            }
            cout << ans << "\n";
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