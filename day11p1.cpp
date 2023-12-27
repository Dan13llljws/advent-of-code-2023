#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	vector<string> g;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();

	vector<int> x(n + 1, 1), y(m + 1, 1);
	vector<pair<int,int>> galaxies;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '#') {
				x[i + 1] = 0, y[j + 1] = 0;
				galaxies.emplace_back(i + 1, j + 1);
			}
		}
	}
	
	x[0] = y[0] = 0;
	for (int i = 1; i <= n; i++) x[i] += x[i - 1]; 
	for (int i = 1; i <= m; i++) y[i] += y[i - 1]; 
	for (auto &[i, j] : galaxies) {
		i += x[i], j += y[j];
	}
	int ans = 0;
	for (int i = 0; i < (int)galaxies.size(); i++) {
		for (int j = 0; j < i; j++) {
			ans += abs(galaxies[i].first - galaxies[j].first) + abs(galaxies[i].second - galaxies[j].second);
		}
	}
	cout << ans << '\n';
}
