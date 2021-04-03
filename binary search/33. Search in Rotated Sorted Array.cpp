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

int binary_search(vector<int> a, int n, int key, int l, int r) {
	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (a[mid] == key)
			return mid;
		else if (a[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int pivot(vector<int> a, int n) {
	int l = 0, r = n - 1;
	while (l <= r) {
		if (l == r)
			return l;
		int mid = l + (r - l) / 2;
		if (mid < r && a[mid] > a[mid + 1])
			return mid;
		else if (mid > l && a[mid] < a[mid - 1])
			return mid - 1;
		else if (a[l] >= a[mid])
			r = mid - 1;
		else if (a[l] <= a[mid])
			l = mid + 1;
	}
	return -1;
}

int search(vector<int>& nums, int target) {
	int n = nums.size();
	int i = pivot(nums, n);
	if (i == -1)
		return binary_search(nums, n, target, 0, n - 1);
	else if (target == nums[i])
		return i;
	else if (target >= nums[0])
		return binary_search(nums, n, target, 0, i - 1);
	else
		return  binary_search(nums, n, target, i + 1, n - 1);
}

void solve() {
	int n; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int key; cin >> key;
	cout << search(a, key)<<endl;

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