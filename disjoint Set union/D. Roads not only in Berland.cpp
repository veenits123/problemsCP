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

const int N = 1e3 + 5;
int par[N];
int sz[N];

void init() {
	REP(i, 1, N) {
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int a) {
	if (a == par[a])
		return a;
	return par[a] = find(par[a]);
}

void unite(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) {
		if (sz[x] < sz[y])
			swap(x, y);
		par[y] = x;
		sz[x] += sz[y];
	}
}

void solve() {

	vector <P> del;

	int n; cin >> n;
	REP(i, 1, n - 1) {
		int u, v; cin >> u >> v;
		int x = find(u);
		int y = find(v);
		if (x == y) {
			del.pb({u, v});
		}
		else {
			unite(x, y);
		}
	}
	vector <P> make;
	REP(i, 2, n) {
		int x = find(1);
		int y = find(i);
		if (x != y) {
			unite(x, y);
			make.pb({1, i});
		}
	}
	cout << make.size() << endl;//no. of edges to be deleted and added are equal
	// bcz it is tree and there's always be (n-1) edges;
	REP(i, 0, make.size() - 1) {
		cout << del[i].F << " " << del[i].S << " " << make[i].F << " " << make[i].S << endl;
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