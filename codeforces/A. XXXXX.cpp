#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;


//#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'



int fill_the_cube(vector<int> area) {
	int n = area.size();
	stack<int> s;
	int ans = 0;
	int upper;
	int temp;

	int ptr = 0;
	while (ptr < n) {
		if (s.empty() || area[s.top()] <= area[ptr])
			s.push(ptr++);
		else {
			upper = s.top();
			s.pop();
			temp = area[upper] * (s.empty() ? ptr :
			                      ptr - s.top() - 1);
			if (ans < temp)
				ans = temp;
		}
	}
	while (!s.empty()) {
		upper = s.top();
		s.pop();
		temp = area[upper];
		if (s.empty())
			temp *= ptr;
		else
			temp *= ptr - s.top() - 1;
		if (ans < temp)
			ans = temp;
	}

	return ans;
}

void solve() {
	int n; cin >> n;
	int c = 0, d = 0;
	vector <int> row, col;
	char a[n][n];
	for (int i = 0; i < n; i++) {
		d = 0;
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'D')
				d++;
		}
		row.pb(d);
	}
	d = 0;
	for (int i = 0; i < n; i++) {
		d = 0;
		for (int j = 0; j < n; j++) {
			if (a[j][i] == 'D')
				d++;
		}
		col.pb(d);
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	int ans = -1;
	int aa = fill_the_cube(row);
	int bb = fill_the_cube(col);
	ans = max(aa, bb);
	cout << int(sqrt(ans)) << endl;

	return ;
}

int main() {


	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif


	//int t;cin>>t;while(t--)
	solve();

	return 0;
}