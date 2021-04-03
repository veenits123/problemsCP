#include <iostream>
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

int find_min(vector<int> a, int n) {
	int l = 0, r = n - 1;
	while (l <= r) {
		if (l == r)
			return a[l];
		int mid = l + (r - l) / 2;
		if (mid < r && a[mid] > a[mid + 1])
			return a[mid + 1];
		else if (mid > l && a[mid] < a[mid - 1])
			return a[mid];
		else if (a[r] > a[mid])
			r = mid - 1;
		else
			l = mid + 1;
	}
	return a[0];
}



int findMin(vector<int>& nums) {
	int n = nums.size();
	int l = 0, r = n - 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (nums[r] == nums[mid])
			r--;
		if (nums[mid] > nums[r])
			l = mid + 1;
		else
			r = mid;
	}
	return nums[r];
}

void solve() {
	int n; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << findMin(a) << endl;

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