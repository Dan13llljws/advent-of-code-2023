#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	string garbage;
	cin >> garbage;
	string t, d;
	string x;
	for (int i = 0; i < 4; i++) cin >> x, t += x;
	cin >> garbage;
	for (int i = 0; i < 4; i++) cin >> x, d += x;
	ll ti = stoll(t), dis = stoll(d);
	
	cout << (ll)floor((ti + sqrt(ti * ti - 4 * dis)) / 2) - (ll)ceil((ti - sqrt(ti * ti - 4 * dis)) / 2) + 1 << '\n';
}
