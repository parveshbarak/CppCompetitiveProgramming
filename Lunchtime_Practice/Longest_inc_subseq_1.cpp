// Note :-> This is a O(N^2) sol using Dynamic programming but we can also further optimize as follows:-
//         When we are searching for the max value from (j=0 to j = i-1) in dp array => We can use
//         Data structure like segment tree/Fenwick Tree to do the same in logn time instead of N time
//         *** Also we can use binary search insted of segment trees which will be great to use:-
//         *** Using binary search is solved in 2nd program


#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1000000007



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    vector<ll> dp(n,1), p(n, -1);

    // d[i]=1: the required subsequence consists of only the element a[i].
    // d[i]>1: then in the required subsequence is another number before the number a[i]. 
    // Let's focus on that number: it can be any element a[j] with j=0…i−1 and a[j]<a[i]. 
    // In this fashion we can compute d[i] using the following formula: If we fixate the index j, 
    // than the longest increasing subsequence ending in the two elements a[j] and a[i] has the length d[j]+1. 
    // All of these values d[j] are already known, so we can directly compute d[i] with:
    
    // The below implementaion is just to cal the length :- 

    /*
    for (ll i=0;i<n;i++) {
        for (ll j=0;j<i;j++) {
            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
        */

    // Now with the above two nested loops we have calculated length of longest subseq till ith element!
    // Now we need to know the exact subseq :->
    // To be able to restore the subseq, we will generate an additional array p,
    // where p[i] will store index j of second last element in LIS ending in i.
    // Basically this array will point to the ancesstor.

    // Implementation including restoration.

    for(ll i=0;i<n;i++){
        for(ll j=0;j<i;j++) {
            if(arr[j] < arr[i] && (dp[i] < (dp[j]+1))) {
                dp[i] = dp[j]+1;
                p[i] = j;
            }
        }
    }

    ll ans = dp[0], pos = 0;
    for(ll i=1;i<n;i++) {
        if(dp[i]>ans) {
            ans = dp[i];
            pos = i;
        }
    }

    // After the above loop :- ans  will be max value of the dp ans pos will the index of that

    vector<ll> subseq;
    while(pos != -1) {
        cout << pos << "   ";
        subseq.push_back(arr[pos]);
        pos = p[pos];
    }

    reverse(subseq.begin(), subseq.end());
    for(auto ele: subseq)
        cout << ele << " ";
    cout << "\n";


return 0;
}
