#include <bits/stdc++.h>
#ifdef GOURISHANKER
	#define IO freopen("/media/gouri/Heart/inputf.in","r",stdin); freopen("/media/gouri/Heart/errorf.in","w",stderr); freopen("/media/gouri/Heart/outputf.in","w",stdout);
	#include "/media/gouri/Heart/myheader.h"
	#define print(args...) riint(_LINE_,#args,args)
#else
#define print(x,...)
	#define IO
	using namespace std;
#endif	
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


struct node {
	int sum, prefixsum, suffixsum, maxsum;
};
void build(node (tree)[] ,int a[] , int n){
	for(int i = 0;i<n;i++){
		tree[n+i].maxsum = a[i];
		tree[n+i].prefixsum = a[i];
		tree[n+i].suffixsum = a[i];
		tree[n+i].sum = a[i];
	}
	for(int i = n-1;i>0;i--){
		tree[i].sum = tree[i<<1].sum + tree[i<<1|1].sum;
		tree[i].prefixsum = max(tree[i<<1].prefixsum , tree[i<<1].sum + tree[i<<1|1].prefixsum);
		tree[i].suffixsum = max(tree[i<<1|1].suffixsum ,tree[i<<1|1].sum +tree[i<<1].suffixsum );
		tree[i].maxsum = max(tree[i].prefixsum , max(
						tree[i].suffixsum ,max(
						tree[i<<1].maxsum ,max(
						tree[i<<1|1].maxsum ,
						tree[i<<1].suffixsum+tree[i<<1|1].prefixsum))));
	}
	
}
int main(int argc, char const *argv[])
{
	IO;
	FastIO;
	clock_t start = clock();
	int a[] = { 1,2,-3,4,-7,8};
	int n = sizeof(a) / sizeof(a[0]);
	node tree[2*n];
	build(tree , a , n);
	for(int i =1;i<2*n;i++){
        cout << "sum => " << tree[i].sum << "  "<< "prefixsum => " << tree[i].prefixsum << "  "<< "suffixsum => " << tree[i].suffixsum << "  "<< "maxsum => " << tree[i].maxsum << "\n";
	}

	
	float time = (float)(clock()-start)/CLOCKS_PER_SEC;
	cerr<<"Program executed sucessfully in: "<< time<<" seconds";
	return 0;

}