#include <bits/stdc++.h>
#ifdef DAN13
#include "../../lib/debug.h"
#else
#define dbg(...)
#endif
using namespace std;

int main() {
	vector<string> g;
	string line;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();
	vector<vector<int>> d(n, vector<int>(m, 1e9));
	
	vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	queue<pair<int,int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'S') d[i][j] = 0, q.push({i, j});
	while(q.size()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] == '.' && d[nx][ny] > d[x][y] + 1) 
				d[nx][ny] = d[x][y] + 1, q.push({nx, ny});
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			ans += d[i][j] % 2 == 0 && d[i][j] <= 64;
	cout << ans << '\n';
}
