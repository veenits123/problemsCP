#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define mp map<int,int>
#define vi vector<int>
#define pq priority_queue<int>
#define pqm priority_queue<int,vi,greater<int> >
#define mod 1e9+7
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x
#define mk(arr,n,type) type *arr=new type[n];
#define tc(x) int x;cin>>x;while(x--)
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define gcd(x,y) __gcd(x,y)
#define s2i(x) stoi(x)
#define i2s(x) to_string(x)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define endl '\n'
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

struct comp {
	bool operator() (const P &a, const P &b) const {
		int len_a = a.S - a.F + 1;
		int len_b = b.S - b.F + 1;
		if (len_a == len_b)
			return a.S < b.S;
		return len_a > len_b;
	}
};

void solve() {
	int n; cin >> n;
	set <P, comp> s;
	int a[n + 1];
	s.insert({1, n});
	for (int i = 1; i <= n; i++) {
		int l = s.begin()->F, r = s.begin()->S;
		//cout<<l<<" "<<r<<endl;
		s.erase({l, r});
		int id = (l + r) / 2;

		a[id] = i;
		if (id - l > 0)
			s.insert({l, id - 1});
		if (r - id > 0)
			s.insert({id + 1, r});
	}
	//for(auto x:s)
	//cout<<x.F<<" "<<x.S<<endl;
	for (int i = 1; i <= n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return ;
}

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	FIO;

	tc(t)
	solve();

	return 0;
}