#include <iostream>
#include <vector>
#include <algorithm>
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

void print(int a[], int n, int k, int high) {
	int sum = 0;
	int cnt = 1;
	vector <int> v;
	for (int i = n - 1; i >= 0; i--) {
		if (sum + a[i] > high || i == k - cnt - 1) {
			//cout<<i<<" "<<k - cnt - 1<<endl;
			v.pb(-1);
			sum = 0;
			cnt++;
		}
		sum += a[i];
		v.pb(a[i]);
	}
	reverse(v.begin(), v.end());
	for (auto x : v) {
		if (x == -1)
			cout << "/ ";
		else
			cout << x << " ";
	}
}

bool is_valid(int a[], int n, int k, int mid) {
	int sum = 0;
	int cnt = 1;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] + sum > mid) {
			cnt++;
			sum = a[i];
		}
		else
			sum += a[i];

		if (a[i] > mid) {
			cnt = 1e9;
			break;
		}
	}
	return (cnt <= k);
}

void binary_search(int a[], int n, int k, int low, int high) {
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (is_valid(a, n, k, mid))
			high = mid;
		else
			low = mid + 1;
	}
	print(a, n, k, high);
}

void solve() {
	int n, k; cin >> n >> k;
	int a[n];
	int low = 1e9, high = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		low = min(low, a[i]);
		high += a[i];
	}
	binary_search(a, n, k, low, high);
	cout << endl;

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

	int t; cin >> t; while (t--)
		solve();

	return 0;
}