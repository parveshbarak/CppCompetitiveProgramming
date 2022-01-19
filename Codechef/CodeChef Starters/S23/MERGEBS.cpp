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

ll inversions(string &s) {
    ll ct = 0, n = s.size();
    for(ll i=0;i<n;i++) {
        if(s[i]=='1') {
            for(ll j=i+1;j<n;j++) {
                if(s[j]=='0') ct++;
            }
        }
    }
    return ct;
}

void one_dist(string& s, vector<ll>&ans) {
    ll n = s.size();
    for(ll i=0;i<n;i++) {
        if(s[i]=='0') {
            ll j = i+1, ct = 0;
            while( j<n && s[j]=='0') j++, ct++;
            if(ct==0) ans[i] = n;
            else ans[i] = ct;
            // ans[i] = ct;
        }
    }
}

void zero_dist(string& s, vector<ll>&ans) {
    ll n = s.size();
    for(ll i=0;i<n;i++) {
        if(s[i]=='1') {
            ll j = i+1, ct = 0;
            while( j<n && s[j]=='1') j++, ct++;
            if(ct==0) ans[i] = n;
            else ans[i] = ct;
            // ans[i] = ct;
        }
    }
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        string c = "";
        ll i=0,j=0;
        vector<ll> aone(n,0), bone(n,0), azero(n,0), bzero(n,0);

        one_dist(a,aone); one_dist(b,bone);
        zero_dist(a,azero); one_dist(b,bzero);

        while(i<n && j<n) {
            if(a[i]=='1' && b[j]=='1') {
                c+= "1";
                if(azero[i]<=bzero[j]) i++;
                else j++;
            }
            else if(a[i]=='0' && b[j]=='0') {
                c+= "0";
                if(aone[i]<=bone[j]) i++;
                else j++;
            }
            else if(a[i]=='0' && b[j]=='1') {
                c+= "0";
                i++;
            }
            else {
                c+= "0";
                j++;
            }
        }
        while(i<n) {
            if(a[i]=='1') c+="1";
            else c+="0";
            i++;
        }
        while(j<n) {
            if(b[j]=='1') c+="1";
            else c+="0";
            j++;
        }
        cout << c << "  ";
        cout << inversions(c) << "\n";
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