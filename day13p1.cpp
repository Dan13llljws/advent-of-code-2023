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
			bool good = 1;
			for (int l = i, r = i + 1; l >= 0 && r < n; l--, r++) 
				good &= g[l] == g[r];
			if (good) ans += 100 * (i + 1);
		}
		for (int i = 0; i < m - 1; i++) {
			bool good = 1;
			for (int l = i, r = i + 1; l >= 0 && r < m; l--, r++) {
				for (int j = 0; j < n; j++)
					if (g[j][l] != g[j][r]) good = 0;
			}
			if (good) ans += i + 1;
		}
	}
	cout << ans << '\n';
}


