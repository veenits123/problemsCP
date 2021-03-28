#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int findCnt(int arr[], int n, int k)
{
	int ans = 0;

	for (int i = 1; i < n; i++) {
		arr[i] += arr[i - 1];
		if (arr[i] > k or arr[i] < -1 * k)
			ans++;
	}

	if (arr[0] > k || arr[0] < -1 * k)
		ans++;

	// Sorting prefix-sum array
	sort(arr, arr + n);

	// Loop to find upper_bound
	// for each element
	for (int i = 0; i < n; i++)
		ans += n -
		       (upper_bound(arr, arr + n, arr[i] + k) - arr);

	// Returning final answer
	return ans;
}

int findSubarraySum(int arr[], int n, int sum)
{
	
	unordered_map<int, int> prevSum;

	int res = 0;

	// Sum of elements so far.
	int currsum = 0;

	for (int i = 0; i < n; i++) {

		// Add current element to sum so far.
		currsum += arr[i];

		// If currsum is equal to desired sum,
		// then a new subarray is found. So
		// increase count of subarrays.
		if (currsum == sum)
			res++;

		// currsum exceeds given sum by currsum
		//  - sum. Find number of subarrays having
		// this sum and exclude those subarrays
		// from currsum by increasing count by
		// same amount.
		if (prevSum.find(currsum - sum) !=
		        prevSum.end())
			res += (prevSum[currsum - sum]);


		// Add currsum value to count of
		// different values of sum.
		prevSum[currsum]++;
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

	// code starts

	int t; cin >> t; while (t--) {
		int n; cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			if (a[i] & 1) {a[i] = 0;}
			else if (a[i] % 4 == 0) {a[i] = 2;}
			else a[i] = 1;
		}
		//for(auto x:a) cout<<x<<" ";
		int zero = findSubarraySum(a, n, 0);
		//cout<<zero;
		int two = findCnt(a, n, 1);
		zero += two;
		//cout<<two;
		//int four=findSubarray(a,n,2);
		//cout<<four;
		cout << zero << endl;
	}


	return 0;
}