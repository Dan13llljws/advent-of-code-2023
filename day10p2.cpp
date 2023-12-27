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
	vector<vector<int>> vis(n, vector<int>(m));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'S') {
				q.push({i, j}), vis[i][j] = 0;
				g[i][j] = '7';
			}
	while(q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (auto [dx, dy] : dir[g[x][y]]) {
			int nx = x + dx, ny = y + dy;
			if (!vis[nx][ny]) vis[nx][ny] = 1, q.push({nx, ny});
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0, up = 0, down = 0;
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) {
				if (g[i][j] == '|') cnt ^= 1;
				else if (g[i][j] == 'L') down = 1, up = 0;
				else if (g[i][j] == 'J') {
					if (up) cnt ^= 1;
					up = 0;
				} else if (g[i][j] == '7') {
					if (down) cnt ^= 1;
					down = 0;
				} else if (g[i][j] == 'F') up = 1, down = 0;
			} else {
				ans += cnt;
			}
		}
	}
	cout << ans << '\n';
}
