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

const int N = 1e5 + 5;
vi graph[N];
vb vis;
vi cnt;
int one, two;
int n;

void dfs(int src, int col) {
	vis[src] = 1;
	if (col == 0)
		one++;
	if (col == 1)
		two++;
	for (int to : graph[src]) {
		if (!vis[to]) {
			dfs(to, col ^ 1);
		}
	}
}

void solve() {

	vis.assign(N, false);
	cnt.assign(N, 0);
	REP(i, 1, N - 1)
	graph[i].clear();

	cin >> n;

	int mx = -1;

	REP(i, 1, n) {
		int u, v; cin >> u >> v;
		mx = max(max(u, v), mx);
		cnt[u] = cnt[v] = 1;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	int ans = 0;
	REP(i, 1, mx) {
		if (!vis[i] && cnt[i]) {
			one = two = 0;
			dfs(i, 0);
			ans += max(one, two);
		}
	}
	cout << ans << endl;

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

	int t, tc; cin >> t; tc = t; while (t--) {
		cout << "Case " << tc - t << ": ";
		solve();
	}

	return 0;
}