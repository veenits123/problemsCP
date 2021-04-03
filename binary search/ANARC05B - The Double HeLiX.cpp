#include <iostream>
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

int binary_search(int a[], int n, int key) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
			r = mid - 1;
		else if (a[mid] < key)
			l = mid + 1;
	}
	return -1;
}

void solve() {

	while (true) {
		int n; cin >> n;
		if (n == 0)
			return ;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int m; cin >> m;
		int b[m];
		for (int i = 0; i < m; i++)
			cin >> b[i];

		int ap[n] = {0};
		ap[0] = a[0];

		int bp[m] = {0};
		bp[0] = b[0];

		//prefix-sum
		for (int i = 1; i < n; i++)
			ap[i] = ap[i - 1] + a[i];

		for (int i = 1; i < m; i++)
			bp[i] = bp[i - 1] + b[i];

		bool flag = false;
		int first = -1, second = -1;
		int prev1 = 0, prev2 = 0;
		int ans = 0;

		for (int i = 0; i < m; i++) {
			int pos = binary_search(a, n, b[i]);
			if (pos == -1)
				continue;
			if (pos >= 0) {
				if (!flag) {
					first = ap[pos];
					second = bp[i];
					flag = true;
				}
				else {
					first = ap[pos] - ap[prev1];
					second = bp[i] - bp[prev2];
				}
				ans += max(first, second);
				prev1 = pos;
				prev2 = i;
			}
		}
		if (!flag) {
			ans += max(ap[n - 1], bp[m - 1]);
		}
		else {
			first = ap[n - 1] - ap[prev1];
			second = bp[m - 1] - bp[prev2];
			ans += max(first, second);
		}
		cout << ans << endl;
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

	//int t;cin>>t;while(t--)
	solve();

	return 0;
}