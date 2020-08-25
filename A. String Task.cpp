#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

int32_t main() {

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// code starts

	//int t;cin>>t;while(t--){}

	string s; cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	string s1 = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' 
			&& s[i] != 'o' && s[i] != 'u' && s[i] != 'y') {
			s1 += '.';
			s1 += s[i];
		}
	}
	cout << s1;
	



	return 0;
}