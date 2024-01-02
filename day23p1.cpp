#include <bits/stdc++.h>
#include "../../lib/debug.h"
using namespace std;

int main() {
	string line;
	vector<string> g;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();

	vector<vector<int>> dp(n, vector<int>(m, -1));
	vector<vector<pair<int,int>>> p(n, vector<pair<int,int>>(m));
	vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
	auto dfs = [&](auto self, int x, int y, int px, int py) -> int {
		if (x == n - 1 && y == m - 2) return 0;
		if (dp[x][y] != -1) return dp[x][y];
		dp[x][y] = -1e9;
			int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx == px && ny == py) continue;
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] != '#') {
				if (g[nx][ny] == 'v' && i != 0) continue;
				if (g[nx][ny] == '>' && i != 1) continue;
				if (g[nx][ny] == '^' && i != 2) continue;
				if (g[nx][ny] == '<' && i != 3) continue;
				cnt++;
				int res = self(self, nx, ny, x, y);
				if (dp[x][y] <= res) dp[x][y] = res, p[x][y] = {nx, ny};
			}
		}
		return ++dp[x][y];
	};

	int sx = 0, sy = 1;

	cout << dfs(dfs, sx, sy, 0, 0) << '\n';
}
