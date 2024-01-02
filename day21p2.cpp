#include <bits/stdc++.h>
#ifdef DAN13
#include "../../lib/debug.h"
#else
#define dbg(...)
#endif
using namespace std;
using ll = long long;

int main() {
	vector<string> g;
	string line;
	while(getline(cin, line)) g.push_back(line);
	int n = g.size(), m = g[0].size();
	
	vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	auto go = [&](int sx, int sy) -> vector<vector<int>> {
		vector<vector<int>> d(n, vector<int>(m, 1e9));
		queue<pair<int,int>> q;
		q.push({sx, sy});
		d[sx][sy] = 0;
		while(q.size()) {
			auto [x, y] = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && g[nx][ny] != '#' && d[nx][ny] > d[x][y] + 1) 
					d[nx][ny] = d[x][y] + 1, q.push({nx, ny});
			}
		}
		return d;
	};

	auto c = go(n / 2, m / 2);
	auto d = go(0, m / 2);
	auto u = go(n - 1, m / 2);
	auto r = go(n / 2, 0);
	auto l = go(n / 2, m - 1);
	auto dr = go(0, 0);
	auto dl = go(0, m - 1);
	auto ur = go(n - 1, 0);
	auto ul = go(n - 1, m - 1);
	
	auto count = [&](vector<vector<int>> v, int lim, int par) -> ll {
		int ans = 0;
		for (auto x : v) 
			for (auto y : x)
				ans += y <= lim && y % 2 == par;
		return ans;
	};

	ll ans = 0;

	const int S = 26501365; // odd
	int B = S / n; // even
	// center
	ans = count(c, n + m, 1);
	// axis
	ans += count(u, n - 1, 0) + count(u, S, 0) * (B / 2 - 1) + count(u, S, 1) * B / 2;
	ans += count(d, n - 1, 0) + count(d, S, 0) * (B / 2 - 1) + count(d, S, 1) * B / 2;
	ans += count(l, n - 1, 0) + count(l, S, 0) * (B / 2 - 1) + count(l, S, 1) * B / 2;
	ans += count(r, n - 1, 0) + count(r, S, 0) * (B / 2 - 1) + count(r, S, 1) * B / 2;
	int tmp = ans;
	// reachable completely not on axis
	ans += count(dr, n + m, 1) * (B - 2) * (B - 2) / 4 + count(dr, n + m, 0) * B / 2 * (B / 2 - 1);
	ans += count(dl, n + m, 1) * (B - 2) * (B - 2) / 4 + count(dl, n + m, 0) * B / 2 * (B / 2 - 1);
	ans += count(ur, n + m, 1) * (B - 2) * (B - 2) / 4 + count(ur, n + m, 0) * B / 2 * (B / 2 - 1);
	ans += count(ul, n + m, 1) * (B - 2) * (B - 2) / 4 + count(ul, n + m, 0) * B / 2 * (B / 2 - 1);
	// edges
	ans += count(dr, n + n / 2, 1) * (B - 1) + count(dr, n / 2, 0) * B;
	ans += count(dl, n + n / 2, 1) * (B - 1) + count(dl, n / 2, 0) * B;
	ans += count(ur, n + n / 2, 1) * (B - 1) + count(ur, n / 2, 0) * B;
	ans += count(ul, n + n / 2, 1) * (B - 1) + count(ul, n / 2, 0) * B;

	cout << ans << '\n';
}
