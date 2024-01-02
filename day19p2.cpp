#include <bits/stdc++.h>
#ifdef DAN13
#include "../../lib/debug.h"
#else
#define dbg(...)
#endif
using namespace std;
using ll = long long;

struct Rule {
	char c, op; int val;
	string then;
};
using Workflow = vector<Rule>;

int main() {
	string line;
	map<string,Workflow> wfs;
	map<string,int> in;
	while(getline(cin, line)) {
		if (line.empty()) break;
		Workflow cur;

		auto i = line.find('{');
		string name = line.substr(0, i);
		line = line.substr(i + 1, (int)line.size() - i - 1);

		auto getRule = [&](string s) -> Rule {
			char c = s[0], op = s[1];
			auto j = s.find(':');
			int val = stoi(s.substr(2, j - 2));
			string then = s.substr(j + 1);
			in[then]++;
			return Rule{c, op, val, then};
		};

		string rule;
		for (char c : line) {
			if (c == ',') {
				cur.push_back(getRule(rule));
				rule.clear();
			} else rule.push_back(c);
		}
		rule.pop_back();
		cur.emplace_back('x', '>', 0, rule);
		in[rule]++;
		wfs[name] = cur;
	}


	struct State {
		map<char,int> l, r;
	};
	map<string,vector<State>> states;
	queue<string> q;
	q.push("in");
	states["in"].push_back({{{'x', 1}, {'m', 1}, {'a', 1}, {'s', 1}}, {{'x', 4000}, {'m', 4000}, {'a', 4000}, {'s', 4000}}});
	while(q.size()) {
		auto u = q.front(); q.pop();
		for (auto [l, r] : states[u]) {
			for (auto [c, op, val, v] : wfs[u]) {
				auto l1 = l, r1 = r;
				if (op == '<') {
					r1[c] = min(r1[c], val - 1);
					l[c] = max(l[c], val);
				} else {
					l1[c] = max(l1[c], val + 1);
					r[c] = min(r[c], val);
				}
				if (r1[c] >= l1[c]) states[v].emplace_back(l1, r1);
				if (!--in[v]) q.push(v);
			}
		}
	}
	
	ll ans = 0;		
	for (auto [l, r] : states["A"]) {
		ll cur = 1;
		for (auto c : {'x', 'm', 'a', 's'}) {
			cur *= r[c] - l[c] + 1;
		}
		ans += cur;
	}
	cout << ans << '\n';
}
