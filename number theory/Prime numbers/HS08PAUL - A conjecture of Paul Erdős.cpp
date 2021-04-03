#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
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

const int N = 1e7 + 25;

bool is_prime(int n) {
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

vector <int> req;
void form() {
	for (int i = 1; i * i < N; i++) {
		for (int j = 1; j * j * j * j < N; j++) {
			if (is_prime(i * i + j * j * j * j)) {
				req.pb(i * i + j * j * j * j);
			}
		}
	}
	sort(req.begin(), req.end());
	unique(req.begin(), req.end());
}

void solve() {

	int n; cin >> n;
	if (n == 1)
		cout << 0 << endl;
	else {
		int l = 0, h = req.size() - 1;
		while (l < h) {
			int mid = (h + l + 1) / 2;
			if (req[mid] > n)
				h = mid - 1;
			else
				l = mid;
		}
		cout << l + 1 << endl;
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

	form();

	int t; cin >> t; while (t--)
		solve();

	return 0;
}