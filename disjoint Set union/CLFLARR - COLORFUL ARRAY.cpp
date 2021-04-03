//method - I DSU <3;
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 2e5 + 5;
int par[N];
int ans[N];

struct node {
	int l, r, c;
};

vector <node> q(N);

void make(int n) {
	par[n] = n;
}

int find(int n) {
	if (n == par[n])
		return n;
	return par[n] = find(par[n]);
}

void solve() {

	int n, m; cin >> n >> m;
	REP(i, 1, m) {
		cin >> q[i].l >> q[i].r >> q[i].c;
	}
	REP(i, 1, N) {
		make(i);
	}
	REV(i, m, 1) {
		int l = q[i].l;
		int r = q[i].r;
		int c = q[i].c;
		for (int x = find(l); x <= r; x = find(x)) {
			ans[x] = c;
			par[x] = x + 1;
		}
	}
	REP(i, 1, n)
	cout << ans[i] << endl;

	return ;
}

int32_t main() {

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

	//int t;cin>>t;while(t--)
	solve();
	
	return 0;
}

//method - II segment tree;
// #include <bits/stdc++.h>
// using namespace std;

// #define int long long int
// #define ld long double
// #define F first
// #define S second
// #define P pair<int,int>
// #define pb push_back
// #define endl '\n'

// const int N = 2e5 + 5;
// int tree[4 * N];
// int lazy[4 * N];

// //lazy propagation
// void update_lazy(int l, int r, int val, int st, int end, int pos) {

// 	if (lazy[pos] != 0) {
// 		tree[pos] = lazy[pos];
// 		if (st != end) {
// 			lazy[2 * pos] = lazy[pos];
// 			lazy[2 * pos + 1]  = lazy[pos];
// 		}
// 		lazy[pos] = 0;
// 	}

// 	if (l > end or r < st) {
// 		return ;
// 	}

// 	if (l <= st and r >= end) {
// 		tree[pos] = val;
// 		if (st != end) {
// 			lazy[2 * pos] = val;
// 			lazy[2 * pos + 1] = val;
// 		}
// 		lazy[pos] = 0;
// 		return ;
// 	}

// 	int mid = (st + end) / 2;
// 	update_lazy(l, r, val, st, mid, 2 * pos);
// 	update_lazy(l, r, val, mid + 1, end, 2 * pos + 1);

// 	return ;
// }

// void print(int st, int end, int pos) {
// 	if (lazy[pos] != 0) {
// 		tree[pos] = lazy[pos];
// 		if (st != end) {
// 			lazy[2 * pos] = lazy[pos];
// 			lazy[2 * pos + 1]  = lazy[pos];
// 		}
// 		lazy[pos] = 0;
// 	}
// 	if (st == end) {
// 		cout << tree[pos] << endl;
// 		return ;
// 	}
// 	int mid = (st + end) / 2;
// 	print(st, mid, 2 * pos);
// 	print(mid + 1, end, 2 * pos + 1);
// }

// int32_t main() {

// 	ios_base:: sync_with_stdio(false);
// 	cin.tie(NULL); cout.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	// code starts

// 	//int t;cin>>t;while(t--){}
// 	int n, m; cin >> n >> m;

// 	while (m--) {
// 		int l, r, c; cin >> l >> r >> c;
// 		update_lazy(l, r, c, 1, n, 1);
// 	}
// 	print(1, n, 1);

// 	return 0;
// }