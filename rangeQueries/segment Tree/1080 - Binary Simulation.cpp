#include<iostream>
#include<cstring>

using namespace std;

//#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

inline int nextint() { int x; scanf("%d", &x); return x; }
const int N = 1e6 + 7;
int tree[4 * N];
int a[N];
int lazy[4 * N];

void build(int start, int end, int pos) {
	if (start == end) {
		tree[pos] = a[start];
		return ;
	}
	int mid = (start + end) / 2;

	build(start, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

void update(int l, int r, int st, int end, int pos) {

	if (lazy[pos]) {
		tree[pos] += (end - st + 1) * lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if (l > end || st > r) return ;

	if (st >= l && r >= end) {
		tree[pos] += (end - st + 1) * 1;
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

	tree[pos] = tree[2 * pos] + tree[2 * pos + 1];
	return ;
}

int query(int ind, int st, int end, int pos) {

	if (lazy[pos]) {
		tree[pos] += (end - st + 1) * lazy[pos];
		if (st != end) {
			lazy[2 * pos] += lazy[pos];
			lazy[2 * pos + 1] += lazy[pos];
		}
		lazy[pos] = 0;
	}
	if (ind < st || ind > end) return 0;

	if (st >= ind && ind >= end) {
		return tree[pos];
	}

	int mid = (st + end) / 2;
	return query(ind, st, mid, 2 * pos) + query(ind, mid + 1, end, 2 * pos + 1);
}

int main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t = nextint();
	for (int i = 1; i <= t; i++) {
		memset(lazy, 0, sizeof(lazy));

		printf("Case %d:\n", i);

		char s[N];
		scanf("%s", s);
		int n = strlen(s);

		for (int i = 0; i < n; i++) {
			a[i] = s[i] - '0';
			//cout<<a[i]<<" ";
		}
		build(0, n - 1, 1);

		int q = nextint();

		while (q--) {
			char x;
			scanf(" %c", &x);
			if (x == 'I') {
				int l = nextint();
				int r = nextint();
				update(l - 1, r - 1, 0, n - 1, 1);

			}
			if (x == 'Q') {
				int q = nextint();
				printf("%d\n", query(q - 1, 0, n - 1, 1) % 2);
			}
		}

	}


	return 0;
}