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
	int n; cin >> n;
	int A[n][n];
	int len = n, k = 1, p = 0, i;   /*k is to assign the values to the array from 1...n*n */
	/*len is used to update(decrease) array size so that values cans be assign to them */
	while (k <= n * n)
	{
		for (i = p; i < len; i++)  /*Loop to access the first row of the array*/
		{
			A[p][i] = k++;
		}
		for (i = p + 1; i < len; i++) /*Loop tp access the last column of the array*/
		{
			A[i][len - 1] = k++;
		}
		for (i = len - 2; i >= p; i--) /*Loop to access the last row of the array*/
		{
			A[len - 1][i] = k++;
		}
		for (i = len - 2; i > p; i--) /*Loop to access the first column of the array*/
		{
			A[i][p] = k++;
		}
		p++, len = len - 1;

	}
	if (!n % 2)                   /*This block will run only if n is even*/
	{
		A[(n + 1) / 2][(n + 1) / 2] = n * n; /*It will assign the last value to the centremost element*/
	}
	for (i = 0; i < n; i++)      /*This loop will print the array in matrix format*/
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
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