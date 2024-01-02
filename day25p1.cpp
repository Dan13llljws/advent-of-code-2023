#include <bits/stdc++.h>
#include "../../lib/debug.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int main() {
	map<string,int> dict;
	int t = 0;
	auto get_id = [&](string s) -> int {
		return dict.count(s) ? dict[s] : dict[s] = t++;
	};
	map<int,vector<int>> adj;
	string line;
	vector<string> vces;
	while(getline(cin, line)) {
		istringstream iss(line);
		string src; iss >> src;
		src.pop_back();
		int id = get_id(src);
		for (string v; iss >> v;) {
			adj[id].push_back(get_id(v));
			adj[get_id(v)].push_back(id);
		}
	}
	int n = dict.size();
	Dinic g(n);
	for (auto [u, vec] : adj)
		for (auto v : vec)
			g.addEdge(u, v, 1);
	dbg(g.calc(12, 9)); // guess the src and snk
	int left = 0;
	for (int i = 0; i < n; i++) left += g.leftOfMinCut(i);
	cout << left * (n - left) << '\n';
}

