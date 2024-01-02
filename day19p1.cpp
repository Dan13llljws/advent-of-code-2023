#include <bits/stdc++.h>
#ifdef DAN13
#include "../../lib/debug.h"
#else
#define dbg(...)
#endif
using namespace std;

struct Part{
	int x, m, a, s;
	int get(const char &c) const {
		if (c == 'x') return x;
		if (c == 'm') return m;
		if (c == 'a') return a;
		return s;
	}
};
struct Rule {
	function<bool(Part)> f;
	string then;
};
using Workflow = vector<Rule>;

int main() {
	string line;
	map<string,Workflow> wfs;
	while(getline(cin, line)) {
		if (line.empty()) break;
		Workflow cur;

		auto i = line.find('{');
		string name = line.substr(0, i);
		dbg(name);
		line = line.substr(i + 1, (int)line.size() - i - 1);

		auto getRule = [&](string s) -> Rule {
			char c = s[0], op = s[1];
			auto j = s.find(':');
			int val = stoi(s.substr(2, j - 2));
			string then = s.substr(j + 1);
			auto lt = [=](Part p) { return p.get(c) < val; };
			auto gt = [=](Part p) { return p.get(c) > val; };
			if (op == '<') return Rule{lt, then};
			return Rule{gt, then};
		};

		string rule;
		for (char c : line) {
			if (c == ',') {
				cur.push_back(getRule(rule));
				rule.clear();
			} else rule.push_back(c);
		}
		rule.pop_back();
		cur.emplace_back([&](Part p) { return true; }, rule);
		wfs[name] = cur;
	}

	auto go = [&](Part p) -> int {
		string cur = "in";
		while(cur != "A" && cur != "R") {
			assert(wfs[cur].size());
			for (auto rule : wfs[cur]) {
				if (rule.f(p)) {
					cur = rule.then;
					break;
				}
			}
		}
		if (cur == "A") return p.x + p.m + p.a + p.s;
		return 0;
	};

	int ans = 0;
	while(getline(cin, line)) {
		istringstream iss(line);
		Part p; char c;
		iss >> c >> c >> c >> p.x >> c >> c >> c >> p.m >> c >> c >> c >> p.a >> c >> c >> c >> p.s;
		ans += go(p);
	}
	cout << ans << '\n';
}
