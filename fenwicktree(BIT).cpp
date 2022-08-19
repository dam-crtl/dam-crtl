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
  int n, q;
  cin >> n >> q;
  fenwick_tree<ll> fw(n);
  //fenwick_treeを生成
  rep(i, 0, n){
    int a;
    cin >> a;
    fw.add(i, a);
    //fw[i]+=a
  }
  rep(i, 0, q){
    int t;
    cin >> t;
    if (t == 0) {
      int p, x;
      cin >> p >> x;
      fw.add(p, x);
    }
    else {
      int l, r;
      cin >> l >> r;
      cout << fw.sum(l, r) << endl;
      //[l,...,r)間でa[i]の和を求める
    }
  }
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/fenwicktree.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_b
