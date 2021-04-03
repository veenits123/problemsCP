#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define endl '\n'

const int N = 1e6 + 7;
int a[N];

struct arr
{
	int level, value;
} tree[4 * N];

//build;
void build(int start, int end, int pos) {

	if (start == end) {
		tree[pos].value = a[start];
		tree[pos].level = 0;
		return ;
	}
	int mid = (start + end) / 2;

	build(start, mid, 2 * pos);
	build(mid + 1, end, 2 * pos + 1);

	tree[pos].level = tree[2 * pos].level + 1;

	if (tree[pos].level & 1) {
		tree[pos].value = tree[2 * pos].value | tree[2 * pos + 1].value;
	}
	else {
		tree[pos].value = tree[2 * pos].value ^ tree[2 * pos + 1].value;
	}
	return ;
}

//update a single node;
void update_node(int index, int val, int start, int end, int pos) {

	if (index<start or index>end) {
		return ;
	}
	if (start == end) {
		tree[pos].value = val;
		return ;
	}
	int mid = (start + end) / 2;

	update_node(index, val, start, mid, 2 * pos);
	update_node(index, val, mid + 1, end, 2 * pos + 1);

	if (tree[pos].level & 1) {
		tree[pos].value = tree[2 * pos].value | tree[2 * pos + 1].value;
	}
	else {
		tree[pos].value = tree[2 * pos].value ^ tree[2 * pos + 1].value;
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

	//int t;cin>>t;while(t--){}
	int n, m; cin >> n >> m;

	n = pow(2, n);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	build(1, n, 1);

	while (m--) {
		int p, b; cin >> p >> b; //a[p]=b;
		update_node(p, b, 1, n, 1);
		cout << tree[1].value << endl;
	}

	return 0;
}