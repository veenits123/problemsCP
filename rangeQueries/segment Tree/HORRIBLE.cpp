#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5 + 7;
int tree[4 * N];
int lazy[4 * N];

//lazy propagation
void update_range(int l, int r, int val, int st, int end, int pos) {

	if (lazy[pos] != 0) {
		tree[pos] += (end - st + 1) * lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1]  += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (l > end or r < st) {
		return ;
	}

	if (l <= st and r >= end) {
		tree[pos] +=   (end - st + 1) * val;
		if (st != end) {
			lazy[2 * pos] += val;
			lazy[2 * pos + 1] += val;
		}
		lazy[pos] = 0;
		return ;
	}

	int mid = (st + end) / 2;
	update_range(l, r, val, st, mid, 2 * pos);
	update_range(l, r, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];

	return ;
}

int query(int l, int r, int st, int end, int pos) {

	if (lazy[pos] != 0) {
		tree[pos] += (end - st + 1) * lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}

	if (st > r or end < l) {
		return 0;
	}

	if (st >= l and end <= r) {
		return tree[pos];
	}

	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) +
	       query(l, r, mid + 1, end, 2 * pos + 1);

}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {

		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));

		int n, c; cin >> n >> c;


		while (c--) {
			int x; cin >> x;
			if (x == 0) {
				int p, q, v; cin >> p >> q >> v;
				update_range(p - 1, q - 1, v, 0, n - 1, 1);
			}
			else {
				int p, q; cin >> p >> q;
				cout << query(p - 1, q - 1, 0, n - 1, 1) << endl;
			}
		}
	}



	return 0;
}