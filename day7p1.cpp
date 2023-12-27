#include <bits/stdc++.h>
using namespace std;

int main() {
	enum Kind {five, four, full, three, p2, p1, high};
	struct Hand {
		string hand;
		int bid;
		Kind kind;
	};
	string rank = "23456789TJQKA";
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
		sort(s.begin(), s.end());
		set<char> st;
		for (char c : s) st.insert(c);

		if (s[0] == s[4]) cur.kind = five;
		else if (s[0] == s[3] || s[1] == s[4]) cur.kind = four;
		else if ((int)st.size() == 2) cur.kind = full;
		else if (s[0] == s[2] || s[1] == s[3] || s[2] == s[4]) cur.kind = three;
		else if ((int)st.size() == 3) cur.kind = p2;
		else if ((int)st.size() == 4) cur.kind = p1;
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
