#include <bits/stdc++.h>
#ifdef DAN13
#include "../lib/debug.h"
#else
#define dbg(...) 69
#endif
using namespace std;
// containers
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
#define af(x) x.begin(), x.end()
#define pb push_back
// rng
mt19937 g1(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a,ll b){return uniform_int_distribution<ll>(a,b)(g1);}
template<class T> void rem_dup(vector<T> &v){sort(af(v));v.resize(unique(af(v))-v.begin());}
template<class T> bool ckmin(T &a,const T &b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T &a,const T &b){return b>a?a=b,1:0;}
const int MOD1 = 1e9+7, MOD2 = 998244353;

void solve(){

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tests = 1;
//     cin >> tests;
    for (int i = 1; i <= tests; i++){
        solve();
    }
}

