#include <bits/stdc++.h>
using namespace std;

int main() {
	string garbage;
	cin >> garbage;
	vector<int> t, d;
	for (int x; cin >> x;) t.push_back(x);
	cin.clear();
	cin >> garbage;
	for (int x; cin >> x;) d.push_back(x);
	
	int ans = 1;
	for (int i = 0; i < (int)t.size(); i++) {
		int cnt = 0;
		for (int j = 0; j <= t[i]; j++)
			cnt += j * (t[i] - j) > d[i];
		ans *= cnt;
	}
	cout << ans << '\n';
}
