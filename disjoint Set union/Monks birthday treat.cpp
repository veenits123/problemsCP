#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define int long long
#define pb push_back
#define endl '\n'

const int N = 1e3 + 5;
vector <int> Graph[N];
int vis[N];
int cnt;
int n, m;

void dfs(int src) {
	vis[src] = 1;
	cnt++;
	for (auto to : Graph[src]) {
		if (!vis[to]) {
			//cnt++;
			dfs(to);
		}
	}
}

int connected_comp() {
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		dfs(i);
		ans = min(ans, cnt);
	}
	return ans;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	cin >> n >> m;
	while (m--) {
		int x, y; cin >> x >> y;
		Graph[x].pb(y);
		//Graph[y].pb(x);
	}
	cout << connected_comp();

	return 0;
}