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
    ll n; cin >> n;
    ll s = n*(n+1)/2;
    if(n%4 != 0)  {cout << "N0\n"; return; }
    else {
        cout << "YES\n";
        vi v1,v2;
        int a=1,b=n; int flag = 0, check = n/2;
        while(check) {
            if(flag == 0) {
                v1.push_back(a); a++; flag = 1;
            } else {
                v1.push_back(b); b--; flag = 0;
            }
            check--;
        }
        for(int i=a;i<=b;i++) v2.push_back(i);
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        for(auto val : v1) {
            cout << val << " ";
        }
        cout << "\n";
        for(auto val : v2) {
            cout << val << " ";
        }
        cout << "\n";
        return;

    } 
}


int main() {
    
    clock_t start = clock();
    
    io_file();

    ll t; cin >> t;
    while(t--) {
        code_here();
    }
    
    clock_t end = clock();
    cerr<<endl<<endl<<"Executed In: "<<double(end - start) / CLOCKS_PER_SEC*1000<<" ms";
    
    return 0;
}