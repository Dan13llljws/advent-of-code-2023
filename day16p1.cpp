#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> g;
	string line;
	while(getline(cin, line)) g.push_back(line);

	int n = g.size(), m = g[0].size();
	vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(4)));
	d[0][0][0] = 1;

	struct Beam{
		int x, y, dir;
	};
	queue<Beam> q;
	q.push({0, 0, 0});
	vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	while(q.size()) {
		auto [x, y, dir] = q.front(); q.pop();
		
		auto in_grid = [&](int x, int y) -> bool {
			return x >= 0 && y >= 0 && x < n && y < m;
		};
		auto push_queue = [&](int new_dir) -> void {
			int nx = x + dx[new_dir], ny = y + dy[new_dir];
			if (in_grid(nx, ny) && !d[nx][ny][new_dir]) q.push({nx, ny, new_dir}), d[nx][ny][new_dir] = 1;
		};

		if (g[x][y] == '.') {
			push_queue(dir);
		} else if (g[x][y] == '/') {
			push_queue(dir ^ 3);
		} else if (g[x][y] == '\\') {
			push_queue(dir ^ 1);
		} else if (g[x][y] == '|') {
			if (dir & 1) push_queue(dir);
			else push_queue((dir + 1) % 4), push_queue((dir + 3) % 4);
		} else if (g[x][y] == '-') {
			if (dir & 1) push_queue((dir + 1) % 4), push_queue((dir + 3) % 4);
			else push_queue(dir);
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans += d[i][j][0] || d[i][j][1] || d[i][j][2] || d[i][j][3];
	cout << ans << '\n';

}
