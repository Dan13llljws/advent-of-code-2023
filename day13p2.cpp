#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int ans = 0;
	while(getline(cin, line)) {
		vector<string> g;
		g.push_back(line);
		while(getline(cin, line)) {
			if (line.empty()) break;
			g.push_back(line);
		}

		int n = g.size(), m = g[0].size();
		for (int i = 0; i < n - 1; i++) {
			int cnt = 0;
			for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) {
				for (int j = 0; j < m; j++)
					cnt += g[l][j] != g[r][j];
			}
			if (cnt == 1) ans += 100 * (i + 1);
		}
		for (int i = 0; i < m - 1; i++) {
			int cnt = 0;
			for (int l = i, r = i + 1; l >= 0 && r < m; l--, r++) {
				for (int j = 0; j < n; j++)
					cnt += g[j][l] != g[j][r];
			}
			if (cnt == 1) ans += i + 1;
		}
	}
	cout << ans << '\n';
}


