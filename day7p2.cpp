#include <bits/stdc++.h>
using namespace std;

int main() {
	enum Kind {five, four, full, three, p2, p1, high};
	struct Hand {
		string hand;
		int bid;
		Kind kind;
	};
	string rank = "23456789TQKA";
	auto get_rank = [&](char c) -> int {
		for (int i = 0; i < (int)rank.size(); i++)
			if (c == rank[i]) return i;
		return -1;
	};

	vector<Hand> hands;
	string line;
	while(getline(cin,line)) {
		istringstream iss(line);
		Hand cur;
		iss >> cur.hand >> cur.bid;
		string s = cur.hand;
		map<char,int> cnt;
		int jcnt = 0;
		for (char c : s) {
			if (c == 'J') jcnt++;
			else cnt[c]++;
		}
		vector<pair<char,int>> f(cnt.begin(), cnt.end());
		sort(f.begin(), f.end(), [&](auto a, auto b) {
			int ta = get_rank(a.first), tb = get_rank(b.first);
			return tie(a.second, ta) > tie(b.second, tb);
		});
		if (f.empty()) f.emplace_back('A', 0);
		f[0].second += jcnt;
		if      (f[0].second == 5) cur.kind = five;
		else if (f[0].second == 4) cur.kind = four;
		else if (f[0].second == 3 && f[1].second == 2) cur.kind = full;
		else if (f[0].second == 3) cur.kind = three;
		else if (f[1].second == 2) cur.kind = p2;
		else if (f[0].second == 2) cur.kind = p1;
		else cur.kind = high;
		hands.push_back(cur);
	}
	
	sort(hands.begin(), hands.end(), [&](auto a, auto b) {
		if (a.kind == b.kind) {
			for (int i = 0; i < 5; i++) 
				if (a.hand[i] != b.hand[i]) return get_rank(a.hand[i]) < get_rank(b.hand[i]);
		} 
		return a.kind > b.kind;
	});
	
	long long ans = 0;
	for (int i = 0; i < (int)hands.size(); i++) 
		ans += 1LL * (i + 1) * hands[i].bid;
	cout << ans << '\n';
}
