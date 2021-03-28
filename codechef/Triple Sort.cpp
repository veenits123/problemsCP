#include <iostream>
#include <vector>

using namespace std;

#define int long long int
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

void solve() {
	int n, k; cin >> n >> k;

	vector <int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	//storing all cycles
	//all swaps needed to sorting
	vector <vector<P>> cycles;
	//storing odd length cycles only
	vector <vector<P>> odd_cycles;
	vector <P> swaps;
	vector <pair<P, int>> ans;

	int parity = 0;

	for (int i = 1; i <= n; i++) {
		vector <P> temp;
		//a[i] is position where element currently on i should be moved;
		while (a[i] != i) {
			temp.pb({i, a[i]});
			swap(a[i], a[a[i]]);
			parity++;
		}
		if (temp.size()) {
			//odd no. of swaps(even size cycle);
			if (temp.size() & 1 ^ 1) {
				cycles.pb(temp);
			}
			//even no. of swaps(odd size cycle);
			else {
				odd_cycles.pb(temp);
			}
		}
	}
	//k<n/2 not more than n/2 operation;
	for (int i = 0; i < odd_cycles.size(); i++) {
		cycles.pb(odd_cycles[i]);
	}
	//permutation (inversion) is odd, impossible to sort using shift;
	if (parity & 1) {
		cout << -1 << endl;
		return ;
	}
	//base case n==3;
	if (n == 3) {
		if (b[1] == 1) {
			cout << 0 << endl;
			return ;
		}
		else if (b[1] == 2) {
			cout << 1 << endl;
			cout << "1 2 3" << endl;
			return ;
		}
		else {
			cout << 1 << endl;
			cout << "1 3 2" << endl;
			return ;
		}
	}
	//all swaps going to array swaps;
	for (auto x : cycles) {
		for (auto y : x) {
			if (y.F > y.S) {
				swap(y.F, y.S);
			}
			swaps.pb(y);
		}
	}
	for (int i = 0; i < swaps.size(); i += 2) {
		P f = swaps[i], g = swaps[i + 1];
		int i1 = f.F, j1 = f.S;
		int i2 = g.F, j2 = g.S;
		if (i1 > j1)
			swap(i1, j1);
		if (i2 > j2)
			swap(i2, j2);
		/* any two indices are equal;
		 two swaps(1 shift) in this case belongs to same cycle; */
		if (i1 == i2) {
			ans.pb({{i1, j1}, j2});
			continue;
		}
		if (j1 == j2) {
			ans.pb({{j1, i1}, i2});
			continue;
		}
		if (i1 == j2) {
			ans.pb({{i1, j1}, i2});
			continue;
		}
		if (i2 == j1) {
			ans.pb({{j1, i1}, j2});
			continue;
		}
		/*four different indices (i,j,k,l) in order;
		2 shifts(4 swaps); */
		ans.pb({{i1, j1}, j2});
		ans.pb({{i2, j2}, i1});
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x.F.F << " " << x.F.S << " " << x.S << endl;
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

	int t; cin >> t; while (t--) {
		solve();
	}
	return 0;
}