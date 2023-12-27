#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll ans = 0;
	string line;
	while(getline(cin, line)) {
		istringstream iss(line);
		string pattern; iss >> pattern;
		string tmp = pattern;
		for (int i = 0; i < 4; i++) pattern += "?" + tmp;
		char comma; int s;
		vector<int> damage;
		iss >> s; damage.push_back(s);
		while(iss >> comma >> s) damage.push_back(s);
		int t = damage.size();
		for (int i = 0; i < 4 * t; i++) damage.push_back(damage[i % t]);

		int n = pattern.size(), m = damage.size();
		vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(2)));
		dp[0][0][0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (pattern[i - 1] == '.' || pattern[i - 1] == '?') dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
				int k = damage[j - 1];
				if (i < k || !j) continue;
				bool good = 1;
				for (int i1 = i - 1; i1 >= i - k; i1--) {
					good &= pattern[i1] == '#' || pattern[i1] == '?';
				}
				if (good) dp[i][j][1] = dp[i - k][j - 1][0];
			}
		}

		ll cur = 0;
		if (pattern.back() == '.' || pattern.back() == '?') cur += dp[n][m][0];
		if (pattern.back() == '#' || pattern.back() == '?') cur += dp[n][m][1];
		ans += cur;
	}
	cout << ans << '\n';
}

