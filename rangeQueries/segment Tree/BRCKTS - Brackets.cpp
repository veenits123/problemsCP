#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

//#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e5 + 5;
char a[N];

struct node {
	int open, close;
	node() {
		open = close = 0;
	}
	node(int val) {
		open = val;
		close = val;
	}
} tree[4 * N];

node merge(node left, node right) {
	node parent;

	int t = min(left.open, right.close);
	parent.open = left.open + right.open - t;
	parent.close = left.close + right.close - t;

	return parent;
}

void build(int st, int end, int pos) {
	if (st > end) return ;
	if (st == end) {
		if (a[st] == '(') {
			tree[pos].open = 1;
			tree[pos].close = 0;
		}
		else {
			tree[pos].close = 1;
			tree[pos].open = 0;
		}
		return ;
	}
	int mid = (st + end) / 2;
	build(st, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);
	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

void update(int index, int st, int end, int pos) {
	if (st == end) {
		if (a[index] == '(') {
			tree[pos].open = 0;
			tree[pos].close = 1;
			a[index] = ')';
		}
		else {
			tree[pos].open = 1;
			tree[pos].close = 0;
			a[index] = '(';
		}
		return ;
	}
	if (index > end || index < st || st > end) return ;
	int mid = (st + end) / 2;
	if (index <= mid) update(index, st, mid, 2 * pos);
	else update(index, mid + 1, end, 2 * pos + 1);

	tree[pos] = merge(tree[2 * pos], tree[2 * pos + 1]);
	return ;
}

int main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//for (int i = 1; i <= 10; i++) {
		int n; scanf("%d", &n);
		scanf("%s", a);

		//printf("Test %d:\n", i);

		build(0, n - 1, 1);

		int q; scanf("%d", &q);

		while (q--) {
			int x; scanf("%d", &x);
			if (x == 0) {
				if (tree[1].open == 0 && tree[1].close == 0) printf("YES\n");
				else printf("NO\n");
			}
			else {
				update(x - 1, 0, n - 1, 1);
			}
		}
	//}


	return 0;
}