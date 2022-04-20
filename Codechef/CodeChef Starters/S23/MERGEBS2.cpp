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

int memo[1001][1001];
int solve(string &a , string&b , int i , int j , int zero){
	if(i == -1){
		int res = 0;
		for(;j>=0;j--){
			if(b[j] == '0') zero++;
			else res+=zero;
		}
		return res;
	}
	if(j == -1){
		int res = 0;
		for(;i>=0;i--){
			if(a[i] == '0') zero++;
			else res+=zero;
		}
		return res;
	}
	if(memo[i][j]!=-1) return memo[i][j];
	int ans = INT_MAX;
	if(a[i] == '1'){
		if(b[j] == '1') ans = min(ans , zero+solve(a , b , i-1 ,j-1 ,zero));
		else ans = min(ans , zero+solve(a , b , i-1 ,j ,zero));
	}
	else{
		if(b[j] == '1') ans = min(ans , zero+solve(a , b , i ,j-1 ,zero));
		else {
			ans = min(ans , solve(a , b , i-1 ,j ,zero+1));
			ans = min(ans , solve(a , b , i ,j-1 ,zero+1));
		}
	}
	return memo[i][j] = ans;
}


void code_here() {
    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        string a, b; cin >> a >> b;
        // cout << rec(a,b,"",0,0) << "\n";
        memset(memo  , -1 ,sizeof(memo));
        cout<<solve(a , b , a.size()-1 , b.size()-1 , 0)<<"\n";
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