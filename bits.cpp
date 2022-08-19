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
  //bitset
  //部分和問題の高速化に
  int N, K, A[100009];
  cin >> N >> K;
  rep(i, 1, N+1) cin >> A[i];
  // DP の遷移を bitset に落とし込む
  bitset<100001> dp;
  dp.set(0);
  rep(i, 1, N+1) dp |= (dp << A[i]);
  if (dp[K] == 1) cout << "Yes" << endl;
  else cout << "No" << endl;

  //__builtin_popcount
  int a=__builtin_popcount(9);

// mint の計算について
// (1<<i)を計算したいときは (1ll<<i) に直す
// mintでは基本的に mod以下の数値を計算しないとエラーを起こす
// (mint)をつければ問題なし
// ex) mint dig=((mint)(1ll<<60))*((mint)(1ll<<60))


// ２の累乗 1<<i
// 2の 1>>i
  return 0;
}
