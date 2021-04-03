#include <iostream>
#include <cstring>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5 + 7;
int tree[4 * N];
int lazy[4 * N];

void update(int l, int r, int st, int end, int pos) {

	if (lazy[pos]) {
		tree[pos] = (end - st + 1) - tree[pos];
		if (st != end) {
			lazy[2 * pos] = 1 - lazy[2 * pos];
			lazy[2 * pos + 1] = 1 - lazy[2 * pos + 1];
		}
		lazy[pos] = 0;
	}
	if (st > end || st > r || l > end) return ;
	if (st >= l && r >= end) {
		tree[pos] = (end - st + 1 - tree[pos]);
		if (st != end) {
			lazy[2 * pos] = 1 - lazy[2 * pos];
			lazy[2 * pos + 1] = 1 - lazy[2 * pos + 1];
		}
		lazy[pos] = 0;
		return ;
	}
	int mid = (st + end) / 2;
	update(l, r, st, mid, 2 * pos);
	update(l, r, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

int query(int l, int r, int st, int end, int pos) {
	if (st > end || st > r || l > end) return 0;
	if (lazy[pos]) {
		tree[pos] = (end - st + 1 - tree[pos]);
		if (st != end) {
			lazy[2 * pos] = 1 - lazy[2 * pos];
			lazy[2 * pos + 1] = 1 - lazy[2 * pos + 1];
		}
		lazy[pos] = 0;
	}
	if (st >= l && end <= r) {
		return tree[pos];
	}
	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) + query(l, r, mid + 1, end, 2 * pos + 1);
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

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	int n, q; cin >> n >> q;
	while (q--) {
		int x; cin >> x;
		if (x == 0) {
			int l, r; cin >> l >> r;
			update(l, r, 1, n, 1);
		}
		else {
			int l, r; cin >> l >> r;
			cout << query(l, r, 1, n, 1) << endl;
		}
	}


	return 0;
}