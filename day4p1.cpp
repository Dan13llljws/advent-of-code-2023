#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int ans = 0;
	while(getline(cin, line)) {
		string x;
		istringstream iss(line);
		iss >> x >> x;
		set<int> good;
		int y;
		for (int i = 0; i < 10; i++) {
			iss >> y;
			good.insert(y);
		}
		iss >> x;
		int cnt = 0;
		while(iss >> y) {
			if (good.count(y)) cnt++;
		}
		if (cnt) ans += 1 << (cnt - 1);
	}
	cout << ans << '\n';
}
