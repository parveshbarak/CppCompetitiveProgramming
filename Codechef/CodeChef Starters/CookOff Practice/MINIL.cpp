#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll t;
    cin >> t;

    while(t--) {
        ll n,m,i,j,ans=0;
        cin >> n >> m;
        vector<vector<bool>> a(n,vector<bool>(m));
        for(i=0;i<n;i++) {
            for(j=0;j<m;j++) {
                char ch;
                cin >> ch;
                if(ch == '.')
                    a[i][j] = false;
                else
                    a[i][j] = true;
            }
        }

        // for(i=0;i<n;i++) {
        //     for(j=0;j<m;j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        //cout << "\n\n";

        if((n*m)%2 == 0) {
            ll c1=0,c2=0;
            for(i=0;i<n;i++) {
                if(i%2==0) {
                    for(j=0;j<m;j++) {
                        if(j%2==0) {
                            if(a[i][j]==false)
                                c1++;
                        } else {
                            if(a[i][j]==true)
                                c1++;
                        }
                    }
                } else {
                    for(j=0;j<m;j++) {
                        if(j%2==0) {
                            if(a[i][j]==true)
                                c1++;
                        } else {
                            if(a[i][j]==false)
                                c1++;
                        }
                    }
                }
                //cout << c1 << " ";
            }
            //cout << "\n";
            for(i=0;i<n;i++) {
                if(i%2!=0) {
                    for(j=0;j<m;j++) {
                        if(j%2==0) {
                            if(a[i][j]==false)
                                c2++;
                        } else {
                            if(a[i][j]==true)
                                c2++;
                        }
                    }
                } else {
                    for(j=0;j<m;j++) {
                        if(j%2==0) {
                            if(a[i][j]==true)
                                c2++;
                        } else {
                            if(a[i][j]==false)
                                c2++;
                        }
                    }
                }
                //cout << c2 << " ";
            }
            //cout << "\n";
            //cout << c1 << "   " << c2 << "\n"; 
            ans = (c1>c2) ? c2 : c1;
        }

        else {
            for(i=0;i<n;i++) {
                if(i%2==0) {
                    for(j=0;j<m;j++) {
                        if(j%2==0) {
                            if(a[i][j]==false)
                                ans++;
                        } else {
                            if(a[i][j]==true)
                                ans++;
                        }
                    }
                } else {
                    for(j=0;j<m;j++) {
                        if(j%2==0) {
                            if(a[i][j]==true)
                                ans++;
                        } else {
                            if(a[i][j]==false)
                                ans++;
                        }
                    }
                }
            }
        }

        cout << ans << "\n";

    }


	return 0;
}

