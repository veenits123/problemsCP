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
	int n, i, j, k;

	cin >> n;
	for (j = 0; j < 2 * n + 1; j++) {
		i = n - abs(j - n);
		k = 0;
		while (k < n - i) {
			cout << "  ";
			k++;
		}
		k = i;
		while (k > -i) {
			cout << i - abs(k) << " ";
			k--;
		}
		cout << 0 << endl;
	}
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}