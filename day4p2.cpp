#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int ans = 0;
	vector<int> c(200, 1);
	for (int i = 1; getline(cin, line); i++) {
		ans += c[i];
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
		for (int j = 1; j <= cnt; j++) c[i + j] += c[i];
	}
	cout << ans << '\n';
}
