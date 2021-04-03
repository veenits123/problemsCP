#include <iostream>
#include <algorithm>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 3e4 + 5;
char a[N];

struct node {
	int open, close, ans;
	node() {
		open = close = ans = 0;
	}
	node(int o, int c, int a) {
		open = o;
		close = c;
		ans = a;
	}
} tree[4 * N];

node merge(node left, node right) {
	node parent;
	int t = min(left.open, right.close);
	parent.open = left.open + right.open - t;
	parent.close = left.close + right.close - t;
	parent.ans = left.ans + right.ans + 2 * t;
	return parent;
}

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		if (a[st] == '(') {
			tree[pos].open++;
		}
		else {
			tree[pos].close++;
		}
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

node query(int l, int r, int st, int end, int pos) {
	if (st > end || l > end || r < st) return node();
	if (st >= l && r >= end) return tree[pos];
	int mid = (st + end) / 2;
	node res = merge(query(l, r, st, mid, 2 * pos), query(l, r, mid + 1, end, 2 * pos + 1));
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
	string s; cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		a[i] = s[i - 1];
	}
	build(1, s.size(), 1);
	int q; cin >> q;
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(l, r, 1, s.size(), 1).ans << endl;
	}


	return 0;
}