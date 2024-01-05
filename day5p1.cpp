#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<long long> seeds;
	string line;
	getline(cin, line);
	cout << line << endl;
	istringstream iss(line);
	string garbage;
	iss >> garbage;
	for (int x; iss >> x;) seeds.push_back(x);
	for (int i = 0; i < 7; i++) {
		getline(cin, line);
		vector<long long> new_seeds = seeds;
		while(getline(cin, line)) {
			if (line.empty()) break;
			istringstream iss(line);
			long long a, b, c;
			iss >> a >> b >> c;
			for (int i = 0; i < (int)seeds.size(); i++) {
				long long x = seeds[i];
				if (x >= b && x < b + c) new_seeds[i] = a - b + x;
			}
		}
		seeds = new_seeds;
	}
	cout << *min_element(seeds.begin(), seeds.end()) << '\n';
}
