#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int minSwaps(int arr[], int n)
{
	// Create an array of pairs where first
	// element is array element and second element
	// is position of first element
	pair<int, int> arrPos[n];
	for (int i = 0; i < n; i++)
	{
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	// Sort the array by array element values to
	// get right position of every element as second
	// element of pair.
	sort(arrPos, arrPos + n);

	// To keep track of visited elements. Initialize
	// all elements as not visited or false.
	vector<bool> vis(n, false);

	// Initialize result
	int ans = 0;

	// Traverse array elements
	for (int i = 0; i < n; i++)
	{
		// already swapped and corrected or
		// already present at correct pos
		if (vis[i] || arrPos[i].second == i)
			continue;

		// find out the number of  node in
		// this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!vis[j])
		{
			vis[j] = 1;

			// move to next node
			j = arrPos[j].second;
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0)
		{
			ans += (cycle_size - 1);
		}
	}

	// Return result
	return ans;
}

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	int t; cin >> t; while (t--) {
		int n, m; cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		if (m == 0) cout << minSwaps(a, n) << endl;
		else cout << 1 << endl;
		while (m--) {
			int x, y; cin >> x >> y;
		}

	}


	return 0;
}