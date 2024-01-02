#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int,map<int,int>> mp;
	string line;
	int x = 0, y = 0;
	mp[x][y] = 1;
	int max_x = 0, max_y = 0, min_x = 0, min_y = 0;

	vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
	while(getline(cin, line)) {
		istringstream iss(line);
		char dir; iss >> dir;
		int step; iss >> step;

		auto go = [&](int d, int step) -> void {
			while(step--) {
				x += dx[d], y += dy[d];
				mp[x][y] = 1;
				max_x = max(max_x, x);
				max_y = max(max_y, y);
				min_x = min(min_x, x);
				min_y = min(min_y, y);
			}
		};

		if (dir == 'R') go (0, step);
		else if (dir == 'D') go (1, step);
		else if (dir == 'L') go (2, step);
		else if (dir == 'U') go (3, step);
	}

	for (int i = min_x; i <= max_x; i++) {
		int cnt = 0, up = 0, down = 0;
		for (int j = min_y; j <= max_y; j++) {
			if (mp[i].count(j)) {
				bool above = mp[i - 1].count(j);
				bool below = mp[i + 1].count(j);
				if (above && below) cnt ^= 1;
				else if (above) {
					if (mp[i].count(j + 1)) {
						up = 1;
						down = 0;
					} else {
						if (down) cnt ^= 1;
						up = down = 0;
					}
				} else if (below) {
					if (mp[i].count(j + 1)) {
						down = 1;
						up = 0;
					} else {
						if (up) cnt ^= 1;
						up = down = 0;
					}
				}
			} else {
				if (cnt & 1) {
					mp[i][j] = 1;
				}
			}
		}
	}
	for (int i = min_x; i <= max_x; i++) {
		for (int j = min_y; j <= max_y; j++) {
			if (mp[i].count(j)) cout << '#';
			else cout << '.';
		}
		cout << endl;
	}

	int ans = 0;
	for (auto [x, v] : mp) ans += v.size();
	cout << ans << '\n';
}
