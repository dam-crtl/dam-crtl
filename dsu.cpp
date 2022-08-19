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

//O(n)
int main() {
  int n, q;
  cin >> n >> q;
  dsu d(n);
  //n頂点0辺の向こうグラフを生成
  rep(i, 0, q){
    int t, u, v;
    cin >> t >> u >> v;
    if(t==0) {
      d.merge(u, v);
      //d.merge(int a, int b) 頂点a, bをつなげる。
      int a=d.leader(u);
      //d.leader(int a) 頂点aの代表元を返す。
      int sz = d.size(a);
      //d.size(int a)　頂点aに属する連結成分のサイズを返す。

    }
    else {
      if (d.same(u, v)) cout << 1 << endl;
      //d.same(int a, int b)頂点a, bが連結かどうかを返す。
      else cout << 0 << endl;
    }
  }
  VV<int> vv = d.groups();
  //グラフを連結成分に分けその情報を返す。
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/dsu.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_a
