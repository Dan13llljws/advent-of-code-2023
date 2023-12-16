#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int ans = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		string x;
		iss >> x;
		int id, r = 0, g = 0, b = 0, y;
		iss >> id;
		iss >> x;
		while(iss >> y >> x) {
			if (x[0] == 'b') b = max(b, y);
			if (x[0] == 'r') r = max(r, y);
			if (x[0] == 'g') g = max(g, y);
		}
		ans += r * g * b;
	}
	cout << ans << '\n';
}


