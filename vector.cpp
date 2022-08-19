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

int main() {
  V<int> v={-1, -2, 0};
  v.pb(0);
  v.pb(1);
  v.pb(2);
  cout << v.size() << endl;
  reverse(all(v));
  sort(all(v));

  int sum = accumulate(v.begin()+1, v.begin()+2, 0);
  //accumulate(最初,最後,基底(0));

  v.erase(unique(all(v)), v.end());
  //同一の要素を消している

  v.erase(v.begin());
  //先頭の要素を消去
  v.erase(v.end());
  //末尾の要素を消去

  int n=100, m=10;
  VV<int> g(n);
  //リスト表現
  //グラフの場合頂点の個数が入ることに注意

  VV<int> g1(n, vector<int>(m, 0));
  //行列表現
  //2000*2000が限界かも

  //VV<int> v;
  //v.resize(n);
  //v.resize(10, 10);
  //v.asign(n, -1);

  //lower_bound(all(v), 5) (v=vector), s.lower_bound(5) (s=set)　はlognで動く
  //lower_bound(all(s), 5) (s=set)　はlog(n)で動く
  //j = lower_bound(all(bp), P(m - na, -1)) - bp.begin();
  // V<P>　は{a, b}では通らない。 P(a, b)しかダメ
  return 0;
}

