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

//segtreeの使い方
//op, eを設定する。
int op(int a, int b) {return max(a, b);} //prodで実行される操作。モノイドである必要がある。
int e() {return -1;} //op(a, e)=op(e, a)が成り立つe(元)

int target;
bool f(int v) {return v < target;} //max_rightのため

//O(qlogn)
int main() {
  int n, q;
  cin >> n >> q;
  V<int> a(n);
  rep(i, 0, n) cin >> a[i];
  segtree<int, op, e> seg(a); //segtreeを作成。今回の場合seg初期値にベクトルaを代入
  rep(i, 0, q){
    int t;
    cin >> t;
    if (t==1){
      int x, v;
      cin >> x >> v;
      x--;
      seg.set(x, v);
      //seg.set(int a, int b) seg[a]=b
    }
    else if (t==2) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l, r) << endl;
      //seg.prod(int l, int r) [l,..,r)までの範囲でopを実行
    }
    else if (t==3) {
      int p;
      cin >> p >> target;
      p--;
      cout << seg.max_right<f>(p)+1 << endl;
      //関数 bool f(S x) を定義する必要がある。segtreeの上で二分探索をします。
      //以下の条件を両方満たす r を(いずれか一つ)返します。
      //1.r = l もしくは f(op(a[l], a[l + 1], ..., a[r - 1])) = true
      //2.r = n もしくは f(op(a[l], a[l + 1], ..., a[r])) = false
      //rとlを逆にした (int) seg.min_left<F>(int r, F f) もある
    }
  }
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/segtree.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_j
