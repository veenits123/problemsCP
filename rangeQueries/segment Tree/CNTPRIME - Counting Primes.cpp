#include <iostream>

using namespace std;

#define ll long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e6 + 7;
int a[N];
int tree[4 * N];
int lazy[4 * N];
int prime[N];

void is_prime() {
	prime[0] = 1;
	prime[1] = 1;
	// prime[2] = 1;
	// for (int i = 3; i <= N; i++) {
	// 	if (i & 1) prime[i] = 1;
	// }
	for (ll i = 2; i < N; i++) {
		if (prime[i] == 0) {
			for (ll j = i * i; j < N; j += i) {
				prime[j] = 1;
			}
		}
	}
}

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		if (prime[a[st]] == 0)
			tree[pos] = 1;
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
		if (prime[lazy[pos]] == 0)
			tree[pos] = (end - st + 1);
		else
			tree[pos] = 0;
		if (st != end) {
			lazy[2 * pos] = lazy[pos];
			lazy[2 * pos + 1] = lazy[pos];
		}
		lazy[pos] = 0;
	}
	if (st > end || l > end || r < st) return ;
	if (st >= l && r >= end) {
		if (prime[val] == 0)
			tree[pos] = (end - st + 1);
		else
			tree[pos] = 0;
		if (st != end) {
			lazy[2 * pos] = val;
			lazy[2 * pos + 1] = val;
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

	if (st > end || l > end || r < st) return 0;
	if (lazy[pos]) {
		if (prime[lazy[pos]] == 0)
			tree[pos] = (end - st + 1);
		else
			tree[pos] = 0;
		if (st != end) {
			lazy[2 * pos] = lazy[pos];
			lazy[2 * pos + 1] = lazy[pos];
		}
		lazy[pos] = 0;
	}
	if (st >= l && r >= end) {
		return tree[pos];
	}
	int mid = (st + end) / 2;
	return query(l, r, st, mid, 2 * pos) + query(l, r, mid + 1, end, 2 * pos + 1);
}

//inline int nextint() { int x; scanf("%d", &x); return x; }

int main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	is_prime();

	int t; scanf("%d", &t); for (int i = 1; i <= t; i++) {

		for (int i = 0; i < 4 * N; i++) {
			tree[i] = lazy[i] = 0;
		}

		printf("Case %d:\n", i);
		int n, q;
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		build(0, n - 1, 1);
		while (q--) {
			int x;
			scanf("%d", &x);
			if (x == 0) {
				int l, r, v;
				scanf("%d%d%d", &l, &r, &v);
				update(l - 1, r - 1, v, 0, n - 1, 1);
			}
			else {
				int l, r;
				scanf("%d%d", &l, &r);
				printf("%d\n", query(l - 1, r - 1, 0, n - 1, 1));
			}
		}
	}
	//cout<<is_prime((21));


	return 0;
}