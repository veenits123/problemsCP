//Your solution is too long for this problem, the limit is 700 bytes!
#include <iostream>
using namespace std;
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'
int mod_exp(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = (res * a) % 10;
			n--;
		}
		a = (a * a) % 10;
		n >>= 1;
	}
	return res;
}
int32_t main() {
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t; cin >> t; while (t--) {
		int a, b; cin >> a >> b;
		int ans = mod_exp(a, b);
		cout << ans % 10 << endl;
	}
	return 0;
}