#include <bits/stdc++.h>
#include "../../lib/debug.h"
using namespace std;

int main() {
	string line;
	vector<string> g;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();

	vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	vector<pair<int,int>> conj;
	conj.emplace_back(0, 1);
	conj.emplace_back(n - 1, m - 2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '#') continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k], ny = j + dy[k];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] != '#') cnt++;
			}
			if (cnt > 2) conj.emplace_back(i, j);
		}
	}

	auto go = [&](int x, int y, int px, int py) -> pair<int,pair<int,int>> {
		for(int i = 1;; i++) {
			if (find(conj.begin(), conj.end(), make_pair(x, y)) != conj.end()) return {i, {x, y}};
			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k], ny = y + dy[k];
				if ((nx != px || ny != py) && nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] != '#') {
					px = x, py = y, x = nx, y = ny;
					break;
				}
			}
		}
	};

	vector<vector<vector<pair<int,pair<int,int>>>>> adj(n, vector<vector<pair<int,pair<int,int>>>>(m));
	for (auto [x, y] : conj) {
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] != '#') 
				adj[x][y].emplace_back(go(nx, ny, x, y));
		}
	}


	set<pair<int,int>> st;
	int ans = 0;
	auto dfs = [&](auto self, int x, int y, int d) -> void {
		if (x == n - 1 && y == m - 2) { ans = max(ans, d); return; }
		st.insert({x, y});
		for (auto [w, v] : adj[x][y]) {
			if (st.count(v)) continue;
			self(self, v.first, v.second, d + w);
		}
		st.erase({x, y});
	};
	dfs(dfs, 0, 1, 0);
	cout << ans << '\n';
}
