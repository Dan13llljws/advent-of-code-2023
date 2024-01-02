#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	long long ans = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		vector<vector<int>> a(1);
		for (int x; iss >> x;) a[0].push_back(x);
		while(true) {
			bool all_zero = 1;
			for (int x : a.back())
				all_zero &= x == 0;
			if (all_zero) break;
			vector<int> b;
			for (int i = 1; i < (int)a.back().size(); i++) 
				b.push_back(a.back()[i] - a.back()[i - 1]);
			a.push_back(b);
		}

		for (auto v : a) {
			ans += v.back();
		}
	}
	cout << ans << '\n';
}
