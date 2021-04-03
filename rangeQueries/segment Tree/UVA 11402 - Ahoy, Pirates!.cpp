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

const int N = 1024000 + 5;
int a[N];
int tree[4 * N];
int lazy[4 * N];

void build(int st, int end, int pos) {
	if (st > end) return;
	if (st == end) {
		tree[pos] = a[st];
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

void update(int l, int r, int val, int st, int end, int pos) {
	if (lazy[pos]) {
		if (lazy[pos] == 1) {
			tree[pos] = (end - st + 1) - tree[pos];
			if (st != end) {
				if (lazy[2 * pos] == 0 || lazy[2 * pos] == 1) {
					lazy[2 * pos] = 1 - lazy[2 * pos];
				}
				else {
					lazy[2 * pos] = (lazy[2 * pos] == 2 ? 3 : 2);
				}

				if (lazy[2 * pos + 1] == 0 || lazy[2 * pos + 1] == 1) {
					lazy[2 * pos + 1] = 1 - lazy[2 * pos + 1];
				}
				else {
					lazy[2 * pos + 1] = (lazy[2 * pos + 1] == 2 ? 3 : 2);
				}
			}

		}
		else if (lazy[pos] == 2) {
			tree[pos] = (end - st + 1);
			if (st != end) {
				lazy[2 * pos] = 2;
				lazy[2 * pos + 1] = 2;
			}

		}
		else {
			tree[pos] = 0;
			if (st != end) {
				lazy[2 * pos] = 3;
				lazy[2 * pos + 1] = 3;
			}

		}
		lazy[pos] = 0;
	}
	if (st > end || l > end || st > r) return ;
	if (st >= l && r >= end) {
		if (val == 1) {
			tree[pos] = (end - st + 1) - tree[pos];
			if (st != end) {
				if (lazy[2 * pos] == 0 || lazy[2 * pos] == 1) {
					lazy[2 * pos] = 1 - lazy[2 * pos];
				}
				else {
					lazy[2 * pos] = (lazy[2 * pos] == 2 ? 3 : 2);
				}

				if (lazy[2 * pos + 1] == 0 || lazy[2 * pos + 1] == 1) {
					lazy[2 * pos + 1] = 1 - lazy[2 * pos + 1];
				}
				else {
					lazy[2 * pos + 1] = (lazy[2 * pos + 1] == 2 ? 3 : 2);
				}
			}

		}
		else if (val == 2) {
			tree[pos] = (end - st + 1);
			if (st != end) {
				lazy[2 * pos] = 2;
				lazy[2 * pos + 1] = 2;
			}
			lazy[pos] = 0;
		}
		else {
			tree[pos] = 0;
			if (st != end) {
				lazy[2 * pos] = 3;
				lazy[2 * pos + 1] = 3;
			}
			lazy[pos] = 0;
		}
		lazy[pos] = 0;
		return ;

	}
	int mid = (st + end) / 2;
	update(l, r, val, st, mid, 2 * pos);
	update(l, r, val, mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

int query(int l, int r, int st, int end, int pos) {
	if (lazy[pos]) {
		if (lazy[pos] == 1) {
			tree[pos] = (end - st + 1) - tree[pos];
			if (st != end) {
				if (lazy[2 * pos] == 0 || lazy[2 * pos] == 1) {
					lazy[2 * pos] = 1 - lazy[2 * pos];
				}
				else {
					lazy[2 * pos] = (lazy[2 * pos] == 2 ? 3 : 2);
				}

				if (lazy[2 * pos + 1] == 0 || lazy[2 * pos + 1] == 1) {
					lazy[2 * pos + 1] = 1 - lazy[2 * pos + 1];
				}
				else {
					lazy[2 * pos + 1] = (lazy[2 * pos + 1] == 2 ? 3 : 2);
				}
			}
		}
		else if (lazy[pos] == 2) {
			tree[pos] = (end - st + 1);
			if (st != end) {
				lazy[2 * pos] = 2;
				lazy[2 * pos + 1] = 2;
			}

		}
		else {
			tree[pos] = 0;
			if (st != end) {
				lazy[2 * pos] = 3;
				lazy[2 * pos + 1] = 3;
			}

		}
		lazy[pos] = 0;
	}
	if (st > end || l > end || st > r) return 0;
	if (st >= l && r >= end) return tree[pos];
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

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
		memset(a, 0, sizeof(a));
		cout << "Case " << i << ":" << endl;
		int m; cin >> m;
		string res = "";
		while (m--) {
			int c; cin >> c;
			string s; cin >> s;
			while (c--) {
				res += s;
			}
		}
		int n = res.size();
		for (int i = 0; i < n; i++) {
			a[i] = res[i] - '0';
		}
		//cout<<res<<endl;
		build(0, n - 1, 1);
		int q; cin >> q;
		int Q = 0;
		while (q--) {
			char x; cin >> x;
			int l, r; cin >> l >> r;

			if (x == 'E') {
				update(l, r, 3, 0, n - 1, 1);
			}
			else if (x == 'F') {
				update(l, r, 2, 0, n - 1, 1);
			}
			else if (x == 'I') {
				update(l, r, 1, 0, n - 1, 1);
			}
			else {
				Q++;
				cout << "Q" << Q << ": ";
				int ans = query(l, r, 0, n - 1, 1);
				cout << ans << endl;
			}
		}
	}


	return 0;
}