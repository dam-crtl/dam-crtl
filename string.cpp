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

//O(0)
int main() {
  string s;
  cin >> s;
  V<int> sa = suffix_array(s);
  //suffix_array(string s):小さい順に接尾配辞列の始まりを返す。V<int>
  ll answer = 1ll * s.size() * (s.size() + 1) / 2;
  for (auto x : lcp_array(s, sa))
    answer -= x;
  //lcp_array(string s, V<int> sa):LCPを返す。V<int>
  //sa[i-1]とsa[i]の一致している長さ。初めは0。
  V<int> v = z_algorithm(s);
  //s[0]から始まる接尾配辞列とs[i]から始まる接尾配辞列のlcp
  cout << answer << endl;
  return 0;
}

//解説URL:file:///Users/masa0095/Downloads/document_ja/string.html
//問題URL:https://atcoder.jp/contests/practice2/tasks/practice2_i
