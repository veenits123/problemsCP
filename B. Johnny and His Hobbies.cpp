#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1025;
int a[N];
bool vis[N];
int n;

bool check(int k) {
	for (int i = 1; i <= n; i++)
		if (!vis[a[i]^k])
			return false;
	return true;
}

void solve() {
	memset(vis, false, sizeof(vis));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		vis[a[i]] = true;
	}
	for (int i = 1; i < 1024; i++) {
		if (check(i)) {
			cout << i << endl;
			return ;
		}
	}
	cout << -1 << endl;
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