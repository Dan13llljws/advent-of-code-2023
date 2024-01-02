#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> g;
	string line;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();

	using vi = vector<int>;
	using vvi = vector<vi>;
	using vvvi = vector<vvi>;
	vector<vvvi> d(n, vvvi(m, vvi(4, vi(4, 1e9))));
	struct State{
		int x, y, dir, cnt, loss;
		bool operator <(const State &other) const {
			return loss > other.loss;
		}
	};
	vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	priority_queue<State> q;
	for (int i : {0, 1, 2, 3}) {
		q.push({0, 0, i, 0, 0});
		d[0][0][i][0] = 0;
	}
	while(q.size()) {
		auto [x, y, dir, cnt, loss] = q.top(); q.pop();
		if (loss > d[x][y][dir][cnt]) continue;
		for (int i = 0; i < 4; i++) {
			if ((dir + 2) % 4 == i) continue;
			int nx = x + dx[i], ny = y + dy[i], ncnt = 1 + (dir == i ? cnt : 0);
			if (ncnt <= 3 && nx >= 0 && ny >= 0 && nx < n && ny < m && d[nx][ny][i][ncnt] > loss + g[nx][ny] - '0')
				d[nx][ny][i][ncnt] = loss + g[nx][ny] - '0', q.push({nx, ny, i, ncnt, loss + g[nx][ny] - '0'});
		}
	}

	int ans = 1e9;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) 
			ans = min(ans, d[n - 1][m - 1][i][j]);
	cout << ans << '\n';
}
