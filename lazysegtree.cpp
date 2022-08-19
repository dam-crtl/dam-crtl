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

struct S {
  mint2 a;
  int size;
};
//元の型
struct F {
  mint2 a, b;
};
//写像の型
S op(S l, S r) { return S{l.a + r.a, l.size + r.size}; }
//prodで実行されるモノイド
S e() { return S{0, 0}; }
//交換条件が通用するもの
S mapping(F l, S r) { return S{r.a * l.a + r.size * l.b, r.size}; }
//関数の効果・変数設定
F composition(F l, F r) { return F{r.a * l.a, r.b * l.a + l.b}; }
//合成関数を考えた場合の変数の変化
F id() { return F{1, 0}; }
//f(x)=xとなる関数中の変数設定

int main() {
  int n, q;
  cin >> n >> q;
  V<S> a(n);
  rep(i, 0, n){
    int x;
    cin >> x;
    a[i] = S{x, 1};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(a);
  //lazy_segtreeを設定
  rep(i, 0, q){
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, c, d;
      cin >> l >> r >> c >> d;
      seg.apply(l, r, F{c, d});
      //seg.apply(l, r, ...) [l,...,r)間の変数に関数を適応させる
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << seg.prod(l, r).a.val() << endl;
      //seg.prod(l, r) [l,...,r)間の変数にopを適応させる
    }
  }
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/lazysegtree.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_k
