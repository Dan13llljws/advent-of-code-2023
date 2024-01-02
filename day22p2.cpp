#include <bits/stdc++.h>
#include "../../lib/debug.h"
using namespace std;

struct Brick {
	int x0, x1, y0, y1, z0, z1;
	int size() {
		return (x1 - x0 + 1) * (y1 - y0 + 1) * (z1 - z0 + 1);
	}
	bool operator<(const Brick &o) const {
		return tie(x0, y0, z0) < tie(o.x0, o.y0, o.z0);
	}
};

int main() {
	string line;
	vector<Brick> bricks;
	bricks.emplace_back(0, 1000, 0, 1000, 0, 0);
	map<Brick,vector<Brick>> adj;
	while(getline(cin, line)) {
		istringstream iss(line);
		char c;
		int x0, x1, y0, y1, z0, z1;
		iss >> x0 >> c;
		iss >> y0 >> c;
		iss >> z0 >> c;
		iss >> x1 >> c;
		iss >> y1 >> c;
		iss >> z1;
		assert(x0 <= x1 && y0 <= y1 && z0 <= z1);
		bricks.emplace_back(x0, x1, y0, y1, z0, z1);
	}
	
	auto below = [&](Brick a, Brick b) -> bool {
		if (b.z0 <= a.z1) return false;
		for (int i = a.x0; i <= a.x1; i++) 
			for (int j = a.y0; j <= a.y1; j++)
				for (int i1 = b.x0; i1 <= b.x1; i1++) 
					for (int j1 = b.y0; j1 <= b.y1; j1++)
						if (i == i1 && j == j1) return true;
		return false;
	};

	auto dist = [&](Brick a, Brick b) -> int { // b above a
		return b.z0 - a.z1 - 1;
	};
	
	for (auto x : bricks) {
		for (auto y : bricks) {
			if (below(x, y)) {
				adj[x].push_back(y);
			}
		}
	}

	map<Brick,int> d;
	struct State {
		Brick b; int dis;
		bool operator<(const State &o) const {
			return dis > o.dis;
		}
	};
	priority_queue<State> q;
	q.push({bricks[0], 0});
	d[bricks[0]] = 0;
	while(q.size()) {
		auto [u, dis] = q.top(); q.pop();
		for (auto v : adj[u]) {
			if (!d.count(v) || d[v] > d[u] + dist(u, v)) {
				d[v] = d[u] + dist(u, v);
				q.push(State{v, d[v]});
			}
		}
	}

	map<Brick,int> in;
	map<Brick,vector<Brick>> adj1;
	for (int i = 1; i < (int)bricks.size(); i++) {
		auto b = bricks[i];
		for (auto v : adj[b]) {
			if (d[v] == d[b] + dist(b, v)) {
				adj1[b].push_back(v);
				in[v]++;
			}
		}
	}

	auto calc = [&](Brick src) -> int {
		int ans = 0;
		queue<Brick> q;
		q.push(src);
		auto tin = in;
		while(q.size()) {
			ans++;
			auto u = q.front(); q.pop();
			for (auto v : adj1[u]) {
				if (!--tin[v]) q.push(v);
			}
		}
		return ans - 1;
	};

	int ans = 0;
	for (auto b : bricks) ans += calc(b);
	ans -= calc(bricks[0]);
	cout << ans << '\n';
}
