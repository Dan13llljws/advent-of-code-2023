#include <bits/stdc++.h>
using namespace std;

int main() {
	string inst;
	getline(cin, inst);
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

	int ans = 0;
	bool good = 0;
	string src = "AAA";
	while(!good) {
		for (char c : inst) {
			if (src == "ZZZ") { good = 1; break; }
			ans++;
			if (c == 'L') src = l[src];
			else src = r[src];
		}
	}
	cout << ans << '\n';
}
