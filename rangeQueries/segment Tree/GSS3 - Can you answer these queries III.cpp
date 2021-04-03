#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;


#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 5e5 + 7;
int a[N];

struct node {

	int sum;
	int prefix_sum;
	int suffix_sum;
	int subarray_sum;

	node() {
		prefix_sum = suffix_sum = subarray_sum = INT_MIN;
		sum = INT_MIN;
	}

} tree[4 * N];

node merge(node left_child, node right_child) {
	node parent;

	parent.prefix_sum = max(left_child.prefix_sum, left_child.sum + right_child.prefix_sum);
	parent.suffix_sum = max(right_child.suffix_sum, right_child.sum + left_child.suffix_sum);
	parent.subarray_sum = max({left_child.subarray_sum, right_child.subarray_sum,
	                           left_child.suffix_sum + right_child.prefix_sum
	                          });
	parent.sum = left_child.sum + right_child.sum;

	return parent;
}

void build(int st, int end, int pos) {

	if (st > end) return ;

	if (st == end) {
		tree[pos].prefix_sum = a[st];
		tree[pos].suffix_sum = a[st];
		tree[pos].subarray_sum = a[st];
		tree[pos].sum = a[st];
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);

	tree[pos] = node();

	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);

	return ;
}

void update(int index, int value, int st, int end, int pos) {

	if (st > end || st > index || index > end) {
		return ;
	}

	if (st == end) {
		tree[pos].sum = value;
		tree[pos].suffix_sum = value;
		tree[pos].prefix_sum = value;
		tree[pos].subarray_sum = value;
		return ;
	}
	int mid = (st + end) / 2;
	update(index, value, st, mid, 2 * pos);
	update(index, value, mid + 1, end, 2 * pos + 1);

	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);

	return ;
}

node query(int l, int r, int st, int end, int pos) {
	if (st > end || l > end || r < st) {
		node n = node();
		return n;
	}

	if (l <= st && r >= end) {
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
		int x; cin >> x;
		if (x == 1) {
			int l, r; cin >> l >> r;
			cout << query(l - 1, r - 1, 0, n - 1, 1).subarray_sum << endl;
		}
		else {
			int ind, val; cin >> ind >> val;
			update(ind - 1, val, 0, n - 1, 1);
		}
	}


	return 0;
}