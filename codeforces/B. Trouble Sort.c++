#include <iostream>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

bool sorted(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

void solve() {
	int n; cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int z = 0, o = 0;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (b[i] == 0)
			z++;
		if (b[i] == 1)
			o++;
	}
	if (z == 0 || o == 0) {
		if (!sorted(a, n))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
		return ;
	}
	cout << "Yes" << endl;

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