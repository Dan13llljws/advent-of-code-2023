#include <bits/stdc++.h>
using namespace std;

int main() {
	string inst;
	getline(cin, inst);
	int m = inst.size();
	string line;
	map<string,string> l, r;
	getline(cin, line);
	while(getline(cin, line)) {
		istringstream iss(line);
		string src; iss >> src;
		string x;
		iss >> x >> x;
		x = x.substr(1, 3);
		l[src] = x;
		iss >> x;
		x = x.substr(0, 3);
		r[src] = x;
	}

	long long ans = 1;
	for (auto [src, x] : l) {
		string cur = src;
		if (cur.back() != 'A') continue;
		int cnt = 0;
		while(cur.back() != 'Z') {
			if (inst[cnt % m] == 'L') cur = l[cur];
			else cur = r[cur];
			cnt++;
		}
		ans = lcm(ans, cnt);
	}
	cout << ans << '\n';
}
