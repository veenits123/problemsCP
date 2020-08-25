#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define int long long
#define F first
#define S second
#define P pair<int,int>
#define endl '\n'

const int N = 5e1 + 5;
char Graph[N][N];
int vis[N][N];
int n, m;

int row[] = {0, 1, -1, 0, 0};
int col[] = {0, 0, 0, 1, -1};

bool is_valid(int i, int j) {
	return (i >= 1 && i <= n && j >= 1 && j <= m);
}

void solve() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> Graph[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (Graph[i][j] == 'B') {
				if (Graph[i + 1][j] == '.')
					Graph[i + 1][j] = '#';
				if (Graph[i - 1][j] == '.')
					Graph[i - 1][j] = '#';
				if (Graph[i][j + 1] == '.')
					Graph[i][j + 1] = '#';
				if (Graph[i][j - 1] == '.')
					Graph[i][j - 1] = '#';
			}
		}
	}
	memset(vis, 0, sizeof(vis));

	queue <P> q;

	if (Graph[n][m] == '.') {
		q.push({n, m});
		vis[n][m] = 1;
	}
	while (!q.empty()) {
		P temp = q.front();
		q.pop();
		for (int i = 1; i <= 4; i++) {
			int x = temp.F + row[i];
			int y = temp.S + col[i];
			if (is_valid(x, y) && !vis[x][y] && Graph[x][y] != '#') {
				q.push({x, y});
				vis[x][y] = 1;
			}
		}
	}
	bool flag = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if ((Graph[i][j] == 'G' && !vis[i][j]) || (Graph[i][j] == 'B' && vis[i][j])) {
				flag = false;
				break;
			}
		}
	}
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}