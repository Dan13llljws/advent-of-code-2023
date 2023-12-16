#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int ans = 0;

	vector<string> dict = {"", "one","two","three","four","five","six","seven","eight","nine"};
	while(cin >> line) {
		int a = 0, b = 0;

		auto match = [&](int j) -> int {
			if (isdigit(line[j])) return line[j] - '0';
			for (int i = 1; i < 10; i++) {
				int len = dict[i].size();
				if (j + len <= (int)line.size() && line.substr(j, len) == dict[i]) return i;
			}
			return -1;
		};

		for (int i = 0; i < (int) line.size(); i++) {
			int cur = match(i);
			if (cur == -1) continue;
			if (!a) a = cur;
			b = cur;
		}
		ans += a * 10 + b;
	}
	cout << ans << '\n';
}

