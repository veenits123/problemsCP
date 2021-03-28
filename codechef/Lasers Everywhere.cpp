#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long int
#define pb push_back
#define endl '\n'

const int N = 1e5 + 5;
int a[N];
int tree[4 * N];

struct event {
	int y, type, ind;
	event(int val, int t, int i) {
		y = val;
		type = t;
		ind = i;
	}
};

bool comp(const event &o, const event &p) {
	if (o.y != p.y)
		return o.y < p.y;
	else
		return o.type < p.type;
}

void update(int ind, int val, int st, int end, int pos) {
	if (st > end || ind < st || ind > end)
		return ;
	if (st == end) {
		tree[pos] = val;
		return ;
	}
	int mid = (st + end) / 2;
	update(ind, val, st, mid, 2 * pos);
	update(ind, val, mid + 1, end, 2 * pos + 1);
	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

int query(int l, int r, int st, int end, int pos) {
	if (st > r || l > end  || st > end)
		return 0;
	if (st >= l && r >= end) {
		return tree[pos];
	}
	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) + query(l, r, mid + 1, end, 2 * pos + 1);
}

void solve() {

	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector <event> all;
	for (int i = 1; i < n; i++) {
		all.pb(event(min(a[i], a[i + 1]), 1, i));
		all.pb(event(max(a[i], a[i + 1]), 3, i));
	}

	vector <int> l(N), r(N);
	for (int i = 1; i <= q; i++) {
		int y;
		cin >> l[i] >> r[i] >> y;
		all.pb(event(y, 2, i));
	}
	sort(all.begin(), all.end(), comp);
	int ans[q + 1];

	for (auto &x : all) {
		if (x.type == 1)
			update(x.ind, 1, 1, n - 1, 1);
		if (x.type == 2)
			ans[x.ind] = query(l[x.ind], r[x.ind] - 1, 1, n - 1, 1);
		if (x.type == 3)
			update(x.ind, 0, 1, n - 1, 1);
	}

	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
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

	int t; cin >> t; while (t--) {
		solve();
	}

	return 0;
}