#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> g;
	string line;
	while(getline(cin, line)) {
		g.push_back(line);
	}

	int ans = 0;
	int n = g.size(), m = g[0].size();
	auto rotate = [&]() -> void {
		for (int i = 0; i < n / 2; i++) swap(g[i], g[n - i - 1]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				swap(g[i][j], g[j][i]);
	};
	map<vector<string>,int> cache;

	for (int i = 0, k = 1e9; k; i++, k--) {
		for (int t = 0; t < 4; t++) {
			for (int i = 0; i < m; i++) {
				for (int j = 0, k = 0; j < n; j++) {
					if (g[j][i] == '#') {
						k = j + 1;
						continue;
					}
					if (g[j][i] == 'O') swap(g[j][i], g[k][i]), k++;
				}
			}
			rotate();
		}
		if (cache.count(g)) {
			k %= i - cache[g];
		}

		cache[g] = i;
	}
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++)
			if (g[j][i] == 'O') ans += n - j;
	cout << ans << '\n';
}


