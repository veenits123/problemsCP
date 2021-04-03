#include <iostream>
#include <cstring>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 1e5 + 5;
int lazy[4 * N];

struct node {
	int count0, count1, count2;
	node() {
		count0 = 1;
		count1 = count2 = 0;
	}
	node(int val) {
		count0 = val;
		count1 = count2 = 0;
	}
} tree[4 * N];

node merge(node left, node right) {
	node parent;
	parent.count0 = left.count0 + right.count0;
	parent.count1 = left.count1 + right.count1;
	parent.count2 = left.count2 + right.count2;
	return parent;
}

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		tree[pos] = node();
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	//tree[pos] = node(0);
	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

void update_lazy(int st, int end, int pos) {
	lazy[pos] %= 3;
	if (lazy[pos] == 1) {
		int t0 = tree[pos].count0;
		int t1 = tree[pos].count1;
		int t2 = tree[pos].count2;

		tree[pos].count0 = t2;
		tree[pos].count1 = t0;
		tree[pos].count2 = t1;
	}
	if (lazy[pos] == 2) {
		int t0 = tree[pos].count0;
		int t1 = tree[pos].count1;
		int t2 = tree[pos].count2;

		tree[pos].count0 = t1;
		tree[pos].count1 = t2;
		tree[pos].count2 = t0;
	}
	if (st != end) {
		lazy[2 * pos] += lazy[pos];
		lazy[2 * pos + 1] += lazy[pos];
	}
	lazy[pos] = 0;
}

void update(int l, int r, int st, int end, int pos) {

	if (lazy[pos]) {
		update_lazy(st, end, pos);
	}

	if (st > end || l > end || st > r) return ;

	if (st >= l && r >= end) {
		int t0 = tree[pos].count0;
		int t1 = tree[pos].count1;
		int t2 = tree[pos].count2;

		tree[pos].count0 = t2;
		tree[pos].count1 = t0;
		tree[pos].count2 = t1;
		if (st != end) {
			lazy[2 * pos] += 1;
			lazy[2 * pos + 1] += 1;
		}
		lazy[pos] = 0;
		return ;
	}

	int mid = (st + end) / 2;
	update(l, r, st, mid, 2 * pos);
	update(l, r, mid + 1, end, 2 * pos + 1);

	//tree[pos] = node();
	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

node query(int l, int r, int st, int end, int pos) {

	if (lazy[pos]) {
		update_lazy(st, end, pos);
	}

	if (st > end || st > r || l > end) return node(0);

	if (st >= l && r >= end) return tree[pos];

	int mid = (st + end) / 2;
	node left = query(l, r, st, mid, 2 * pos);
	node right = query(l, r, mid + 1, end, 2 * pos + 1);
	//node res = node();
	node res = merge(left, right);
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
	int n, q; cin >> n >> q;

	//memset(lazy,0,sizeof(lazy));

	build(0, n - 1, 1);

	while (q--) {
		int x, l, r; cin >> x >> l >> r;

		if (x == 1) {

			cout << query(l, r, 0, n - 1, 1).count0 << endl;
		}

		else {

			update(l, r, 0, n - 1, 1);
		}
	}
	// cout << "Tree\n";
	// for(int i = 1; i < 8; i++)
	// 	cout << i << " , " << tree[i].count0 << "\n";
	// cout << "\n";
	// cout << "Lazy Tree\n";
	// for(int i = 1; i < 8; i++)
	// 	cout << lazy[i] << "\n";
	// cout << "\n";


	return 0;
}