#include <iostream>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int a, b; cin >> a >> b;
	if (a == b) {
		cout << 0 << endl;
		return ;
	}
	if (a > b)
		swap(a, b);

	int i = 0;
	while (a < b) {
		a *= 2;
		i++;
	}
	if (a != b) {
		cout << -1 << endl;
		return ;
	}
	else {
		cout << i / 3 + min((int)1, i % 3) << endl;
		return ;
	}
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