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

const int N = 1e6 + 7;
int a[N];

struct node {

	int max1;
	int max2;
	int sum;

	node() {
		max1 = max2 = sum = 0;
	}
	node(int val) {
		max1 = sum = val;//i!=j given;
		max2 = 0;
	}

} tree[4 * N];

node merge(node left, node right) {

	node parent;

	vector <int> arr;

	arr.pb(left.max1); arr.pb(left.max2);
	arr.pb(right.max1); arr.pb(right.max2);
	sort(arr.begin(), arr.end());

	parent.max1 = arr[3];
	parent.max2 = arr[2];
	parent.sum = arr[3] + arr[2];

	return parent;
}

void build(int st, int end, int pos) {

	if (st > end) return ;

	if (st == end) {
		tree[pos] = node(a[st]);
		return ;
	}

	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);

	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);

	return ;
}

void update(int index, int val, int st, int end, int pos) {

	if (st > end || index < st || index > end) return ;

	if (st == end) {
		tree[pos] = node(val);
		return ;
	}

	int mid = (st + end) / 2;
	update(index, val, st, mid, 2 * pos);
	update(index, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);

	return ;
}

node query(int l, int r, int st, int end, int pos) {

	if (st > end || l > end || st > r) {
		node n = node();
		return n;
	}

	if (st >= l && end <= r) {
		return tree[pos];
	}

	int mid = (st + end) / 2;
	node left = query(l, r, st, mid, 2 * pos);
	node right = query(l, r, mid + 1, end, 2 * pos + 1);

	return merge(left, right);
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
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	build(0, n - 1, 1);
	int q; cin >> q;
	while (q--) {
		char x; cin >> x;
		if (x == 'Q') {
			int l, r; cin >> l >> r;
			cout << query(l - 1, r - 1, 0, n - 1, 1).sum << endl;
		}
		else {
			int i, v; cin >> i >> v;
			update(i - 1, v, 0, n - 1, 1);
		}
	}


	return 0;
}