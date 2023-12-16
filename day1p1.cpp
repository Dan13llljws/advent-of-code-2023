#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	int ans = 0;
	while(cin >> line) {
		int a = 0, b = 0;
		for (char c : line) 
			if (isdigit(c)) {
				b = c - '0';
				if (!a) a = c - '0';
			}
		ans += a * 10 + b;
	}
	cout << ans << '\n';
}

