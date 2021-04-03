#include <iostream>
#include <deque>
#include <vector>
using namespace std;

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

/* → → → → → → → → → → → → → → → → → → → → → → → → → → → →
	→ → → → → → → → → → → → → → → → → → → → → → → → → → → → */

void solve() {
	int n; cin >> n;

	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	int k; cin >> k;

	vector <int> ans;

	deque <int> q;

	for (int i = 1; i <= k; i++) {

		while (!q.empty() && a[i] >= a[q.back()]) {
			q.pop_back();
		}
		q.pb(i);
	}

	for (int i = k + 1; i <= n; i++) {

		ans.pb(a[q.front()]);

		while (!q.empty() && q.front() <= i - k) {
			q.pop_front();
		}

		while (!q.empty() && a[i] >= a[q.back()]) {
			q.pop_back();
		}
		q.pb(i);
	}
	ans.pb(a[q.front()]);

	for (auto x : ans)
		cout << x << " ";

	return ;
}

/*
//brute-force;
void solve() {
	int n, k; cin >> n;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> k;
	vector <int> ans;
	for (int i = 0; i <= n - k; i++) {
		int mx = 0;
		for (int j = 1; j <= k; j++) {
			//cout << a[i + j] << " ";
			mx = max(mx, a[i + j]);
		}
		//cout << endl;
		ans.pb(mx);
	}
	for (auto x : ans)
		cout << x << " ";

	return ;
}
*/

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