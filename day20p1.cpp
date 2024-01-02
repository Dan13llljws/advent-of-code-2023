#include <bits/stdc++.h>
#ifdef DAN13
#include "../../lib/debug.h"
#else
#define dbg(...)
#endif
using namespace std;

int main() {
	string line;
	map<string,vector<string>> adj;
	map<string,int> type;
	map<string,vector<string>> mem;
	map<string,bool> state;
	while(getline(cin, line)) {
		istringstream iss(line);
		string from; iss >> from;
		if (from[0] == '%') from = from.substr(1), type[from] = 0; // flip-flop
		else if (from[0] == '&') from = from.substr(1), type[from] = 1; // conjunction
		if (type[from] == 0) state[from] = 0;
		string to;
		iss >> to;
		while(iss >> to) {
			if (to.back() == ',') to.pop_back();
			adj[from].push_back(to);
		}
	}

	for (auto [from, to] : adj) {
		for (auto v : to) {
			if (type[v] == 1) {
				mem[v].push_back(from);
			}
		}
	}

	struct Pulse {
		string to;
		bool pulse;
	};

	int iter = 1000;
	int low = 0, high = 0;
	while(iter--) {
		queue<Pulse> q;	
		low++;
		for (auto v : adj["broadcaster"]) {
			q.push({v, 0});
		}
		while(q.size()) {
			auto [to, pulse] = q.front(); q.pop();
			if (pulse) high++;
			else low++;
			if (type[to] == 0) { // flip-flop
				if (!pulse) {
					state[to] ^= 1;
					for (auto v : adj[to]) {
						q.push({v, state[to]});
					}
				}
			} else {
				bool f = 1;
				for (auto v : mem[to]) {
					f &= state[v];
				}
				state[to] = !f;
				for (auto v : adj[to]) {
					q.push({v, !f});
				}
			}
		}
	}

	cout << 1LL * low * high << '\n';
}
