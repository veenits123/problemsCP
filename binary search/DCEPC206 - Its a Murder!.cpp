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

int ans = 0;

void merge(int a[], int n, int mid, int st, int en) {
	int i = st, j = mid + 1;
	int temp[n];
	int k = st;
	while (i <= mid && j <= en) {
		if (a[i] < a[j]) {
			temp[k] = a[i];
			ans += a[i] * (en - j + 1);
			//cout << a[i] << " " << en - j + 1 << endl;
			i++; k++;
		}
		else {
			temp[k] = a[j];
			j++; k++;
		}
	}
	while (i <= mid) {
		temp[k] = a[i];
		i++; k++;
	}
	while (j <= en) {
		temp[k] = a[j];
		j++; k++;
	}
	for (int i = st; i <= en; i++)
		a[i] = temp[i];
}

void mergesort(int a[], int n, int st, int en) {
	if (st >= en)
		return ;
	int mid = (st + en) / 2;
	mergesort(a, n, st, mid);
	mergesort(a, n, mid + 1, en);
	merge(a, n, mid, st, en);
}

void solve() {
	int n; cin >> n;
	int a[n];
	ans = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	mergesort(a, n, 0, n - 1);
	cout << ans << endl;
	// for (int i = 0; i < n; i++)
	// 	cout << a[i] << " ";

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