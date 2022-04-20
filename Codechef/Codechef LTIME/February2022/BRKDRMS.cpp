#include <bits/stdc++.h>
#ifdef parveshbarak
	#define IO freopen("/home/parvesh/Desktop/Codes/DebuggingFiles/inputf.in","r",stdin); freopen("/home/parvesh/Desktop/Codes/DebuggingFiles/errorf.in","w",stderr); freopen("/home/parvesh/Desktop/Codes/DebuggingFiles/outputf.in","w",stdout);
	#include "/home/parvesh/Desktop/Codes/DebuggingFiles/myheader.h"
	#define print(args...) riint(__LINE__,#args,args)
#else
#define print(x,...)
	#define IO
	using namespace std;
#endif	
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long;

int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();

	int t; cin >> t;
	while(t--) {
		int n,k; cin >> n >> k;
		string s; cin >> s;
		unordered_map<char, vector<int>> mp;
		for(int i=0;i<n;i++) {
			mp[s[i]].push_back(i);
		}
		if(k == 1) cout << s << "\n";
		else {
			k = k-1;
			vector<vector<int>> dv;
			while(k--) {
				for(int i=0;i<26;i++) {
					char c = 'a'+i;
					vector<int> v(mp[c].size());
					if(mp[c].size()) {
						for(auto x: mp[c]) v.push_back(x), mp[c].pop_back();
						int last = v.back();
						for(int j = i+1;j<26;j++) {
							char d = 'a'+j;
							if(mp[d].size()) {
								int pos = lower_bound(mp[d].begin(), mp[d].end(), last) - mp[d].begin();
								for(int l = pos;l<mp[d].size();l++) v.push_back(l);
								int z = mp[d].size() - pos;
								while(z--) mp[d].pop_back();
							}
						}
					}
					if(v.size()) dv.push_back(v);
				}
			}

			string ans = "";

			for(auto vect : dv) {
				for(auto idx : vect) {
					ans += s[idx];
				}
			}

			cout << ans << "\n";
		}

	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}