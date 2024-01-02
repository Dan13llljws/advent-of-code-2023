#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	string cur;

	auto proc = [&]() -> int {
		int hash = 0;
		for (char c : cur) hash = ((hash + c) * 17) % 256;
		return hash;
	};

	int ans = 0;
	for (char c : s) {
		if (c == ',') ans += proc(), cur.clear();
		else cur.push_back(c);
	}
	ans += proc();
	cout << ans << '\n';
}
