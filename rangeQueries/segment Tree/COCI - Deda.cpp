#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

#define int long long int
#define endl '\n'

const int N = 2e5 + 5;
//const int M = 1e9 + 1;
int tree[4 * N];

void update(int ind, int val, int st, int end, int pos) {
	if (st > end || ind > end || ind < st) return ;
	if (st == end && st == ind) {
		tree[pos] = val;
		return ;
	}
	int mid = (st + end) / 2;
	//if(ind<=mid)
	update(ind, val, st, mid, 2 * pos);
	//else
	update(ind, val, mid + 1, end, 2 * pos + 1);
	tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

int query(int l, int r, int val, int st, int end, int pos) {
	if (st > end) return INT_MAX;
	if (st == l && r == end && l == r)
		return l;
	int mid = (st + end) / 2;
	int a = -1, b = -1;
	if (tree[2 * pos] <= val && l <= mid) {
		a = query(l, min(mid, r), val, st, mid, 2 * pos);
	}
	if (a == -1 && tree[2 * pos + 1] <= val && r > mid) {
		b = query(max(l, mid + 1), r, val, mid + 1, end, 2 * pos + 1);
	}
	if (a == -1)
		return b;
	else {
		if (b == -1)
			return a;
		else
			return min(a, b);
	}
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

	fill(tree, tree + 4 * N, INT_MAX);

	int n, q; cin >> n >> q;
	while (q--) {
		char x;
		int val, ind; cin >> x >> val >> ind;
		if (x == 'M') {
			update(ind, val, 1, n, 1);
		}
		else {
			cout << query(ind, n, val, 1, n, 1) << endl;
		}
	}


	return 0;
}