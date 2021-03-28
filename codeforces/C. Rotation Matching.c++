#include <iostream>
#include <map>

using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void shift(int a[], int n) {
	int x = a[0];
	for (int i = 0; i < n; i++) {
		a[i] = a[i + 1];
		if (i == n - 1) {
			a[n - 1] = x;
		}
	}
}

void solve() {
	map <int, int> m;
	int n; cin >> n;
	int a[n], b[n];
	int pos[n];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	// shift(b,n);
	// for(int i=0;i<n;i++)
	// 	cout<<b[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int temp = pos[b[i]] - i;
		//cout<<temp<<" ";
		if (temp < 0)
			temp += n;
		m[temp]++;
	}
	for (auto x : m)
		ans = max(ans, x.S);
	cout << ans;

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