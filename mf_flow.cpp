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

//計算量的には (n, m)=(_, 10000), (1000, 10000)とかか?
int main() {
  int n, m;
  cin >> n >> m;
  V<string> grid(n);
  rep(i, 0, n) cin >> grid[i];
  /**
  * generate (s -> even grid -> odd grid -> t) graph
  * grid(i, j) correspond to vertex (i * m + j)
  **/
  mf_graph<int> g(n * m + 2);
  //グラフ生成
  int s = n * m, t = n * m + 1;
  // s -> even / odd -> t
  rep(i, 0, n)rep(j, 0, m){
    if (grid[i][j] == '#') continue;
    int v = i * m + j;
    if ((i + j) % 2 == 0) g.add_edge(s, v, 1);
    //g.add_edge(int from, int to, int cap) 辺を追加
    else g.add_edge(v, t, 1);
  }
  // even -> odd
  rep(i, 0, n)rep(j, 0, m){
    if ((i + j) % 2 || grid[i][j] == '#') continue;
    int v0 = i * m + j;
    if (i && grid[i - 1][j] == '.') {
      int v1 = (i - 1) * m + j;
      g.add_edge(v0, v1, 1);
    }
    if (j && grid[i][j - 1] == '.') {
      int v1 = i * m + (j - 1);
      g.add_edge(v0, v1, 1);
    }
    if (i + 1 < n && grid[i + 1][j] == '.') {
      int v1 = (i + 1) * m + j;
      g.add_edge(v0, v1, 1);
    }
    if (j + 1 < m && grid[i][j + 1] == '.') {
      int v1 = i * m + (j + 1);
      g.add_edge(v0, v1, 1);
    }
  }
  cout << g.flow(s, t) << endl;
  //g.flow(int from, int to) fromからtoへめいっぱい流す。
  //g.flow(int from, int to, int limit) とするとlimitだけ流す。
  //O(min(m*n^(2/3), m^(3/2))) (辺の容量が全て１の時)
  //O(n^2*m)　(その他)

  //これとは別にg.min_cut(int s):V<bool>　が存在する。
  //これはg.flow_limitなしで頂点sからiへ残余グラフで到達可能な時trueを返す長さnの配列を返すものである
  //O(n+m)
  auto edges = g.edges();
  //今の辺の状態を返す。
  //struct edges{int from, to, flow;};
  //edgeを変化させる場合 g.change_edge(int i, Cap new_cap, Cap new_flow);
  for (auto e : edges) {
    if (e.from == s || e.to == t || e.flow == 0) continue;
    int i0 = e.from / m, j0 = e.from % m, i1 = e.to / m, j1 = e.to % m;
    if (i0 == i1 + 1) {
      grid[i1][j1] = 'v';
      grid[i0][j0] = '^';
    }
    else if (j0 == j1 + 1) {
      grid[i1][j1] = '>';
      grid[i0][j0] = '<';
    }
    else if (i0 == i1 - 1) {
      grid[i0][j0] = 'v';
      grid[i1][j1] = '^';
    }
    else {
      grid[i0][j0] = '>';
      grid[i1][j1] = '<';
    }
  }
  rep(i, 0, n) cout << grid[i] << endl;
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/maxflow.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_d
