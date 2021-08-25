#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7


void merge(ll arr[], ll l, ll mid, ll h) {
    ll temp[h-l+1]; ll i=l, j=mid+1, k=l;
    // cout << i << "  " << j << "  "<< k << "  \n";
    while(i<=mid && j<=h) {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    // cout << i << "  " << j << "  "<< k << "  \n";
    // Copyong Remaining Elements if any
    while(i<=mid) {
        temp[k++] = arr[i++];
    }
    while(j<=h) {
        temp[k++] = arr[j++];
    }
    // Coplying back from temp array to arr
    for(i=l;i<=h;i++)
        arr[i] = temp[i];
}

void _merge_sort(ll arr[], ll l, ll h) {
    if(l>=h) return;
    ll mid = (l+h)/2;
    _merge_sort(arr,l, mid);
    _merge_sort(arr, mid+1, h);

    merge(arr, l ,mid, h);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n;
    cin >> n;   //size of array and k so that to find kth largest..
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    for(ll i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";

    _merge_sort(arr,0,n-1);

    for(ll i=0;i<n;i++)
        cout << arr[i] << " ";
    cout << "\n";


	return 0;
}

