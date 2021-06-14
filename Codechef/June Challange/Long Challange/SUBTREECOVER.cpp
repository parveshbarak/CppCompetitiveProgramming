#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007



ll getFarNode(ll node, vvi & G, ll n){
  vector<bool> done(n+1, false);
  ll fd=-1, far;  done[node] = true;
  queue<pair<ll, ll>> que; que.push({node, 0});
  while(que.size()){
    auto pi = que.front(); que.pop();
    ll nod = pi.first, dis = pi.second;
    if(fd < dis) fd = dis, far = nod;
    for(auto cnod: G[nod]){
      if(done[cnod]) continue;
      done[cnod] = true;
      que.push({cnod, dis+1});
    }
  }
  return far;
}

void dfs(ll nod, ll par, vvi & G, vi & H, vi & li, ll cur){
  bool isleaf = true;
  ll mx = 0;
  for(auto cnod: G[nod]) if(cnod != par) {isleaf = false; mx = max(mx, H[cnod]);}
  if(isleaf){ li.push_back(cur); return; }

  ll c = 0;
  for(auto cnod: G[nod]){
    if(cnod == par) continue;
    if(H[cnod] == mx && c==0){
      dfs(cnod, nod, G, H, li, cur+1); c++;
    }
    else dfs(cnod, nod, G, H, li, 1);
  }
}

void fixHeight(ll nod, ll par, vvi & G, vi & H){
  bool isleaf = true;
  for(auto cnod: G[nod]){
    if(cnod == par) continue;
    isleaf = false;
    fixHeight(cnod, nod, G, H);
    H[nod] = max(H[nod], 1 + H[cnod]);
  }
  if(isleaf) H[nod] = 1;
}

void breakIntoLines(ll nod, ll par, vvi & G, vi&li, ll n){
  vector<ll> H(n+1, 0);
  fixHeight(nod, par, G, H);
  dfs(nod, par, G, H, li, 1);
}

ll getSolution(vvi & arr, ll n, ll k){
  if(k==1) return 1;
  ll u = getFarNode(1, arr, n);
  vector<ll> li;
  breakIntoLines(u, 0, arr, li, n);
  sort(li.rbegin(), li.rend());
  ll size = 1, total = 0, i = 0;
  while(total < k){
    size++; total += li[i++];
  }
  return size;
}

void solve(){
     ll n, k;
     ll u, v;
     
    cin>>n>>k;
    vvi arr(n+1);
    for(ll i=1; i<n; i++){
      cin>>u>>v;
      arr[u].push_back(v); arr[v].push_back(u);
    }
    cout << getSolution(arr, n, k) << "\n";
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll t;
    cin>>t;
    int _=1;
    while(t--){
        solve();
    }

return 0;
}

