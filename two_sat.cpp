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

//O(n+m)
int main() {
  int n, d;
  cin >> n >> d;
  V<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  // ts[i] = (i-th flag is located on x[i])
  two_sat ts(n); //n変数の2-SATを作る
  rep(i, 0, n)rep(j, i+1, n){
    // cannot use both of x[i] and x[j]
    if (abs(x[i] - x[j]) < d) ts.add_clause(i, false, j, false); //ts.add_clause(int i, bool f, int j, bool g)
    if (abs(x[i] - y[j]) < d) ts.add_clause(i, false, j, true);  //クローズの追加
    if (abs(y[i] - x[j]) < d) ts.add_clause(i, true, j, false);  //この場合 x=true, y=false　となっている
    if (abs(y[i] - y[j]) < d) ts.add_clause(i, true, j, true);
  }
  if (!ts.satisfiable()){//条件を満たすような割り当てが存在するかを判定:O(n+m)
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  auto answer = ts.answer();//クローズを満たす割り当てを返す。vector<bool> v(n):O(n)
  rep(i, 0, n){
    if (answer[i]) cout << x[i] << endl;
    else cout << y[i] << endl;
  }
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/twosat.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_h
