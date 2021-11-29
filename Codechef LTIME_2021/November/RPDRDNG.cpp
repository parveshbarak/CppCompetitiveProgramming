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
        vi b(2*n); loop(i,0,2*n) cin>>b[i];
        sort(b.begin(),b.end());
        if(n==1) {
            if(b[0]==b[1]) cout << b[0] << "\n";
            else cout << -1 << "\n";
        } 
        else {
            map<ll,ll> freq;
            loop(i,0,2*n) freq[b[i]]++;
            map<ll,ll> ideal;
            for(ll i=0;i<n-1;) {
                ll x = b[i];
                while(b[i]==x) i++;
                ideal[x]=2;
            }
            ideal[b[n-1]]=3;
            for(ll i=n+2;i<2*n;) {
                ll x = b[i];
                while(b[i]==x) i++;
                ideal[x]=2;
            }
            ideal[b[(2*n)-1]]=1;

            // cout << ideal.size() << " ";

            if(ideal.size() != n) cout << -1 << "\n";
            else {
                bool flag = true;
                for(auto x:ideal) {
                    // cout << x.first << " " << x.second << "  ";
                    if(ideal[x.first] != freq[x.first]) flag = false;
                }
                if(!flag) cout << -1 << "\n";
                else {
                    for(auto x: ideal) cout << x.first << " ";
                    cout <<"\n";
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