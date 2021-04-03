#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N=1e6+7;
int a[N];
int tree[4*N];

//build
void build_tree_min(int start, int end, int pos) {
	if (start == end) {
		tree[pos] = a[start];
		return ;
	}
	int mid = (start + end) / 2;

	build_tree_min(start, mid, 2 * pos);
	build_tree_min(mid + 1, end, 2 * pos + 1);

	tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

//query
int range_query_min(int q_low, int q_high, int start, int end, int pos) {
	if (q_low <= start and q_high >= end) {
		return tree[pos];
	}
	if (q_low > end or q_high < start) {
		return INT_MAX;
	}
	int mid = (start + end) / 2;
	int left = range_query_min(q_low, q_high, start, mid, 2 * pos);
	int right = range_query_min(q_low, q_high, mid + 1, end, 2 * pos + 1);

	return min(left, right);
}

//update
void update_min(int index, int val, int start, int end, int pos) {

	if (index<start or index>end) {
		return ;
	}
	if (start == end) {
		a[index]=val;
		tree[pos] = val;
		return ;
	}
	int mid = (start + end) / 2;

	update_min(index, val, start, mid, 2 * pos);
	update_min(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}


int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--){}
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	build_tree_min(1,n,1);
	while(q--){
		char x;cin>>x;
		int y,z;cin>>y>>z;
		if(x=='q'){
			cout<<range_query_min(y,z,1,n,1)<<endl;
		}
		else{
			update_min(y,z,1,n,1);
		}
	}


	return 0;
}