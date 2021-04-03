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
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define mod (int)1e9+7
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

const int N = 1e5 + 5;
int par[N];
int n, m;

void init() {
	for (int i = 0; i < N; i++)
		par[i] = (-1) * i;
}

int find(int n) {
	if (par[n] < 0)
		return n;
	return par[n] = find(par[n]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) {
		//m-I;
		// if (x < y)
		// 	swap(x, y);
		// par[y] = x;

		//m-II;
		par[x] = min(par[x], par[y]);
		par[y] = x;
	}
}

void solve() {

	cin >> n >> m;

	while (m--) {
		int u, v; cin >> u >> v;
		unite(u, v);
	}

	int q; cin >> q;
	while (q--) {
		int u, v; cin >> u >> v;
		int x = find(u);
		int y = find(v);
		//cout << par[x] << " " << par[y] << endl;

		if (par[x] == par[y])
			cout << "TIE" << endl;
		if (par[x] > par[y])
			cout << v << endl;
		if (par[x] < par[y])
			cout << u << endl;
	}

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

	init();

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}