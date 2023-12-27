#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<string> g;
	string line;
	while(getline(cin, line)) {
		g.push_back(line);
	}

	int ans = 0;
	int n = g.size(), m = g[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0, k = 0; j < n; j++) {
			if (g[j][i] == '#') {
				k = j + 1;
				continue;
			}
			if (g[j][i] == 'O') swap(g[j][i], g[k][i]), k++;
		}
		for (int j = 0; j < n; j++)
			if (g[j][i] == 'O')
				ans += n - j;
	}
	cout << ans << '\n';
}


