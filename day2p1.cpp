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
			if (x[0] == 'b') b += y;
			if (x[0] == 'r') r += y;
			if (x[0] == 'g') g += y;
			if (r > 12 || b > 13 || g > 14) { ans -= id; break; }
			if (x.back() != ',') r = g = b = 0;
		}
		ans += r * g * b;
	}
	cout << ans << '\n';
}


