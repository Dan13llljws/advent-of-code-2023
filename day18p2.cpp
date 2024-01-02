#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string line;
	map<char,pair<int,int>> mp = {{'R', {0, 1}}, {'D', {1, 0}}, {'L', {0, -1}}, {'U', {-1, 0}}};

	vector<ll> x, y;
	vector<char> dir;
	x.push_back(0);
	y.push_back(0);
	ll cur_x = 0, cur_y = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		char d; iss >> d;
		int step; iss >> step;
		string col; iss >> col;
		d = "RDLU"[col[7] - '0'];
		col = col.substr(2, 5);
		stringstream ss;
		ss << hex << col;
		ss >> step;
		cur_x += mp[d].first * step, cur_y += mp[d].second * step;
		x.push_back(cur_x);
		y.push_back(cur_y);
		dir.push_back(d);
	}

	bool flag = 1;
	ll ans = 0;
	for (int i = 1; i < (int)x.size(); i++) {
		int dx = 0, dy = 0;
		if (dir[i - 1] == 'R' && dir[i] == 'D') dy++;
		if (dir[i - 1] == 'R' && dir[i] == 'U') dx++, dy++;
		if (dir[i - 1] == 'D' && dir[i] == 'L') dx++, dy++;
		if (dir[i - 1] == 'D' && dir[i] == 'R') dx++;
		if (dir[i - 1] == 'L' && dir[i] == 'U') dx++;
		if (dir[i - 1] == 'U' && dir[i] == 'L') dy++;
		if (i > 1 && dir[i] == dir[i - 2]) flag ^= 1;
		if (flag) dx ^= 1, dy^= 1;
		x[i] += dx, y[i] += dy;
		ans += x[i] * y[i - 1] - y[i] * x[i - 1];
	}
	cout << ans / 2 << '\n';
}
