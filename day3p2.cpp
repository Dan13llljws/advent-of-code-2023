#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> g;
	string x;
	while(cin >> x) g.push_back(x);
	int n = g.size(), m = g[0].size();
	vector<vector<int>> h(n, vector<int>(m));
	queue<pair<int,int>> q;
	int id = 0;

	auto dfs = [&](auto self, int i, int j) -> void {
		h[i][j] = id;
		if (j && !h[i][j - 1] && isdigit(g[i][j - 1])) self(self, i, j - 1);
		if (j < m - 1 && !h[i][j + 1] && isdigit(g[i][j + 1])) self(self, i, j + 1);
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isdigit(g[i][j]) && !h[i][j]) id++, dfs(dfs, i, j);
		}
	}
	vector<int> val(id + 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (h[i][j]) val[h[i][j]] = val[h[i][j]] * 10 + g[i][j] - '0';
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (g[i][j] == '*') {
				set<int> st;
				for (int dx : {-1, 0, 1}) {
					for (int dy : {-1, 0, 1}) {
						if (dx || dy) {
							int nx = i + dx, ny = j + dy;
							if (nx >= 0 && ny >= 0 && nx < n && ny < m && h[nx][ny]) st.insert(h[nx][ny]);
						}
					}
				}
				if ((int)st.size() == 2) ans += val[*st.begin()] * val[*st.rbegin()];
			}
		}
	}
	cout << ans << '\n';
}
