#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e9
#define ll long long
#define countBits(x) __builtin_popcount(x)
#define MOD 1e9+7

void swap(ll* a, ll* b) {
    ll t = *a;
    *a = *b;
    *b = t;
}

ll partition(ll arr[], ll l, ll h) {
    ll pivot = arr[l];
    ll i, j = h;
    i = l+1; j = h;
    while(i<j) {
        while(arr[i]<pivot) i++;
        while(arr[j]>pivot) j--;
        if(i<j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[l], &arr[j]);
    return j;
}

ll Quick_sort(ll arr[], ll l, ll h, ll k) {
    ll j;
    // K is smaller than no of elements in the array
    if(k>0 && k < h-l+1) {
        if(l<h) {
            j = partition(arr,l,h);
            if(j==k-1)
                return arr[j];
            if(j>k-1)
                return Quick_sort(arr,l,j-1,k);
            else
                return Quick_sort(arr,j+1,h,k);
        }
    }
    // Else if K is more than no of elements
    return -1;
}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll n,k;
    cin >> n >> k;   //size of array and k
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin >> arr[i];

    cout << Quick_sort(arr,0,n-1,k) << "\n";

    // for(ll i=0;i<n;i++)
    //     cout << arr[i] << " ";
    // cout << "\n";


	return 0;
}

