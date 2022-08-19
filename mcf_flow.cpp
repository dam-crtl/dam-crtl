#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using namespace internal;
using mint = modint1000000007;
using mint2 = modint998244353;
template <class T> using maxpq = priority_queue<T>;
template <class T> using minpq = priority_queue<T, vector<T>, greater<> >;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<V<V<T>>>;
template <class T> using VVVV = V<V<V<V<T>>>>;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define taka cout << "Takahashi" << endl
#define aoki cout << "Aoki" << endl
#define pb push_back
#define fi first
#define se second
#define all(c) (c).begin(), (c).end()
#define sz(x) ((int)(x).size())
#define md 1000000007
#define md2 998244353
#define chmin(x,y) x = min((x),(y));
#define chmax(x,y) x = max((x),(y));
#define rep(i, a, b) for (int i=a; i<b; i++)
#define repr(i, a, b) for (int i=a; i>=b; i--)

const ll BIG = 1'000'000'000;
int main() {
  int n, k;
  cin >> n >> k;
  /**
  * generate (s -> row -> column -> t) graph
  * i-th row correspond to vertex i
  * i-th col correspond to vertex n + i
  **/
  mcf_graph<int, ll> g(2 * n + 2);
  //グラフ生成
  int s = 2 * n, t = 2 * n + 1;
  // we can "waste" the flow
  g.add_edge(s, t, n * k, BIG);
  //int g.add_edge(int from, int to, Cap cap, Cost cost);
  //fromからtoへ最大容量cap, コストcostの辺を追加する。何番目に追加された辺かを返す。
  rep(i, 0, n){
    g.add_edge(s, i, k, 0);
    g.add_edge(n + i, t, k, 0);
  }
  rep(i, 0, n)rep(j, 0, n){
    ll a;
    cin >> a;
    g.add_edge(i, n + j, 1, BIG - a);
  }
  auto result = g.flow(s, t, n * k);
  //pair<Cap, Cost> g.flow(int s, int t, (Cap flow_limit));
  //s からt へ流せるだけ流し、その流量とコストを返す。
  cout << 1LL * n * k * BIG - result.second << endl;
  V<string> grid(n, string(n, '.'));
  auto edges = g.edges();
  //struct edge<Cap, Cost>{int from, to; Cap cap, flow; Cost cost;};
  for (auto e : edges) {
    if (e.from == s || e.to == t || e.flow == 0) continue;
    grid[e.from][e.to - n] = 'X';
  }
  rep(i, 0, n) cout << grid[i] << endl;
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/mincostflow.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_e
