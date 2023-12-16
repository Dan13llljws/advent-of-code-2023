#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> g, h;
	string x;
	while(cin >> x) g.push_back(x);
	queue<pair<int,int>> q;
	for (int i = 0; i < (int)g.size(); i++) {
		for (int j = 0; j < (int)g[0].size(); j++) {
			int c = g[i][j];
			if (!isdigit(c) && c != '.') q.push({i, j});
		}
	}
	h = g;
	while(q.size()){ 
		int x = q.front().first, y = q.front().second; q.pop();
		for (int dx : {-1, 0, 1}) {
			for (int dy : {-1, 0, 1}) {
				if (dx || dy) {
					int nx = x + dx, ny = y + dy;
					if (nx >= 0 && nx < (int)g.size() && ny >= 0 && ny < (int)g[0].size() && isdigit(g[nx][ny])) {
						g[nx][ny] = g[x][y];
						q.push({nx, ny});
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (int)g.size(); i++) 
		for (int j = 0; j < (int)g[0].size(); j++) 
			if (!isdigit(h[i][j]) || isdigit(g[i][j])) h[i][j] = ' ';
	for (string &s : h) {
		istringstream iss(s);
		int x;
		while(iss >> x) ans += x;
	}
	cout << ans << '\n';
}
