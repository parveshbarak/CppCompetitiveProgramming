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

unordered_set<char> vowels{'a' ,'e' ,'i' ,'o' , 'u'};

void code_here() {
    ll t; cin >> t;
    while(t--) {
        int n;
		cin>>n;
		string s , p;
		cin>>s>>p;
		int ans = 0 , c = 0 , v = 0;
		unordered_map<char , int> freq;
		for(int i = 0;i<n;i++){
			if(s[i]!='?' and p[i] !='?'){
				if(s[i] != p[i]) {
					if(vowels.count(s[i]) and vowels.count(p[i])){
						ans+=2;
					}
					else if(!vowels.count(s[i]) and !vowels.count(p[i])){
						ans+=2;
					}
					else ans++;
				}
			}

			if(s[i] == '?' and p[i]!='?'){
				if(vowels.count(p[i])){
					freq[p[i]]++;
					v++;
				}
				else{
					freq[p[i]]++;
					c++;
				} 
			}
			if(s[i] != '?' and p[i] =='?'){
				if(vowels.count(s[i])){
					freq[s[i]]++;
					v++;
				}
				else {
					freq[s[i]]++;
					c++;
				}
			}
		}
		int maxiv = 0 , maxic = 0;
		int sum = 0;
		for(auto x : freq){
			if(vowels.count(x.first)){
				if(x.second > maxiv) maxiv = x.second;
			}
			else if(x.second > maxic) maxic = x.second;
		}
		ans = ans + min(c+2*v-2*maxiv , 2*c +v -2* maxic);
		cout<<ans<<"\n";
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