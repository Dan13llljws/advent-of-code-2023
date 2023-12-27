#include <bits/stdc++.h>
using namespace std;

int main() {
	map<char,vector<pair<int,int>>> dir = {{'|', {{1, 0}, {-1, 0}}},
																				 {'-', {{0, 1}, {0, -1}}},
																				 {'L', {{-1, 0}, {0, 1}}},
																				 {'J', {{-1, 0}, {0, -1}}},
																				 {'7', {{1, 0}, {0, -1}}},
																				 {'F', {{1, 0}, {0, 1}}}};
	vector<string> g;
	string line;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();
	queue<pair<int,int>> q;
	vector<vector<int>> vis(n, vector<int>(m, 1e9));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'S') {
				q.push({i, j}), vis[i][j] = 0;
				g[i][j] = '-';
			}
	int ans = 0;
	int cnt = 0;
	while(q.size()) {
		auto [x, y] = q.front(); q.pop();
		cnt++;
		ans = max(ans, vis[x][y]);
		for (auto [dx, dy] : dir[g[x][y]]) {
			int nx = x + dx, ny = y + dy;
			if (vis[nx][ny] > vis[x][y] + 1) vis[nx][ny] = vis[x][y] + 1, q.push({nx, ny});
		}
	}
	cout << ans << '\n';
}
