#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 3e5 + 7;
vector <int> tree[N];
int a[N];

vector <int> merge(vector <int> a, vector <int> b) {
	vector <int> ans;

	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] >= b[j]) {
			ans.pb(b[j]);
			j++;
		}
		else {
			ans.pb(a[i]);
			i++;
		}
	}
	while (i < a.size()) {
		ans.pb(a[i]);
		i++;
	}
	while (j < b.size()) {
		ans.pb(b[j]);
		j++;
	}
	return ans;
}

void build(int st, int end, int pos) {
	if (st > end) return;
	if (st == end) {
		tree[pos].pb(a[st]);
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);

	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);

	return ;
}

int query(int l, int r, int k, int st, int end, int pos) {

	if (l <= st && r >= end) {
		int ans = tree[pos].size() - (upper_bound(tree[pos].begin(), tree[pos].end(), k) -
		                              tree[pos].begin());
		return ans;
	}
	if (l > end || r < st) return 0;

	int mid = (st + end) / 2;
	return query(l, r, k, st, mid, 2 * pos) + query(l, r, k, mid + 1, end, 2 * pos + 1);
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

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, n, 1);


	int q; cin >> q;
	int ans=0;
	while (q--) {
		int l, r, k,i,j,kk; cin >> l >> r >> k;
		
		// i=l^ans;
		// j=r^ans;
		// kk=k^ans;

		ans = query(l, r, k, 1, n, 1);
		cout << ans << endl;
	}

	// for(int i=1;i<2*n+2;i++){
	// 	for(int j=0;j<tree[i].size();j++){
	// 		cout<<tree[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }



	return 0;
}