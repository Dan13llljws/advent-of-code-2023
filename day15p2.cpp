#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string cur;

	vector<vector<pair<string,int>>> hmap(256);
	auto proc = [&]() -> void {
		int hash = 0;
		for (char c : cur) {
			if (c == '=' || c == '-') break;
			hash = ((hash + c) * 17) % 256;
		}

		auto &v = hmap[hash];
		if (isdigit(cur.back())) {
			int val = cur.back() - '0';
			cur.pop_back(), cur.pop_back();
			bool found = 0;
			for (int i = 0; i < (int)v.size(); i++) 
				if (v[i].first == cur) v[i].second = val, found = 1;
			if (!found) v.emplace_back(cur, val);
		} else {
			cur.pop_back();
			for (int i = 0; i < (int)v.size(); i++)
				if (v[i].first == cur) {
					v.erase(v.begin() + i);
					break;
				}
		}
	};

	for (char c : s) {
		if (c == ',') proc(), cur.clear();
		else cur.push_back(c);
	}
	proc();

	int ans = 0;
	for (int i = 0; i < 256; i++)
		for (int j = 0; j < (int)hmap[i].size(); j++)
			ans += (i + 1) * (j + 1) * hmap[i][j].second;
	cout << ans << '\n';
}
