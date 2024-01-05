#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	vector<pair<ll,ll>> seeds;
	string line;
	getline(cin, line);
	istringstream iss(line);
	string garbage;
	iss >> garbage;
	for (ll x, y; iss >> x >> y;) seeds.emplace_back(x, y);
	for (int i = 0; i < 7; i++) {
		getline(cin, line);
		vector<pair<ll,ll>> new_seeds;
		vector<ll> A, B, C;
		while(getline(cin, line)) {
			if (line.empty()) break;
			istringstream iss(line);
			ll x, y, z;
			iss >> x >> y >> z;
			A.push_back(x);
			B.push_back(y);
			C.push_back(z);
		}
		for (int i = 0; i < (int)seeds.size(); i++) {
			auto [x, y] = seeds[i];
			bool good = 0;
			for (int j = 0; j < (int)A.size(); j++) {
				ll a = A[j], b = B[j], c = C[j];
				if (x >= b && x + y < b + c) new_seeds.emplace_back(a - b + x, y), good = 1;
				else if (x >= b && x < b + c) new_seeds.emplace_back(a - b + x, b + c - x), seeds.emplace_back(b + c, x + y - b - c), good = 1;
				else if (x < b && x + y > b && x + y <= b + c) seeds.emplace_back(x, b - x), new_seeds.emplace_back(a, x + y - b), good = 1;
				else if (x < b && x + y > b + c) seeds.emplace_back(x, b - x), new_seeds.emplace_back(a, c), seeds.emplace_back(b + c, x + y - b - c), good = 1;
				if (good) break;
			}
			if (!good) new_seeds.push_back(seeds[i]);
		}
		seeds = new_seeds;
	}
	ll ans = 1e18;
	for (auto [x, y] : seeds) ans = min(ans, x);
	cout << ans << '\n';
}
