#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;


#define int long long int
#define ld long double
#define F first
#define S second
#define P pair <int,int>
#define vi vector <int>
#define vs vector <string>
#define vb vector <bool>
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define REP(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define REV(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define sp(x,y) fixed<<setprecision(y)<<x
#define pb push_back
#define endl '\n'
const int mod = 1e9 + 7;


const int N = 1e5 + 5;

vector<string> split_string(string);

// Complete the andProduct function below.
long andProduct(long a, long b) {
    long res = 0;
    long d = b - a;
    for (int i = 0; i < 32; i++) {
        if (d > (1ll << i))
            continue;
        else {
            if ((a & (1ll << i)) && (b & (1ll << i)))
                res += (1ll << i);
        }
    }
    return res;
}

int32_t main()
{
	//ofstream fout(getenv("OUTPUT_PATH"));

	ios_base:: sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int n_itr = 0; n_itr < n; n_itr++) {
		string ab_temp;
		getline(cin, ab_temp);

		vector<string> ab = split_string(ab_temp);

		long a = stol(ab[0]);

		long b = stol(ab[1]);

		long result = andProduct(a, b);

		cout << result << "\n";

		//fout << result << "\n";
	}

	//fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}