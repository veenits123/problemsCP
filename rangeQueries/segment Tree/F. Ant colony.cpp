#include <iostream>
#include <algorithm>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e5 + 5;
int a[N];

struct node {
	int gcd, count;
	node() {
		gcd = count = 0;
	}
	node(int val) {
		gcd = val;
		count = 1;
	}
} tree[4 * N];

node merge(node left, node right) {
	node parent;
	parent.gcd = __gcd(left.gcd, right.gcd);
	parent.count = 0;
	if (left.gcd == parent.gcd) {
		parent.count += left.count;
	}
	if (right.gcd == parent.gcd) {
		parent.count += right.count;
	}
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
	tree[pos] = node();
	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

node query(int l, int r, int st, int end, int pos) {
	if (st > end || l > end || st > r) return node(0);
	if (st >= l && r >= end) return tree[pos];
	int mid = (st + end) / 2;
	node res = node();
	res = merge(query(l, r, st, mid, 2 * pos), query(l, r, mid + 1, end, 2 * pos + 1));
	return res;
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
	while (q--) {
		int l, r; cin >> l >> r;
		int nrValues = query(l, r, 1, n, 1).count;
		cout << r - l + 1 - nrValues << endl;
	}


	return 0;
}