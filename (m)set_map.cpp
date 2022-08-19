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
  //multiset
  multiset<int> ms;
  //挿入された要素を昇順に格納
  ms.insert(0);
  ms.insert(1);
  ms.insert(0);
  //{0, 0, 1}
  //msに要素を挿入
  auto ret = ms.equal_range(0);
  //要素の始まりと終了のiteratorを返す pair<iterator, iterator>
  cout << *(ret.fi) << " " << *(ret.se) << endl;
  if(ms.find(0)!=ms.end()) cout << "find" << endl;
  if(ms.count(0)) cout << "find" << endl;
  auto it = ms.lower_bound(0);
  //lower_bound(all(ms), 0);だとO(n)なので上記以外禁止
  cout << *it << endl;
  ms.erase(0);
  //要素/イテレータを消す
  //multiset.erase(値)は内部にある値全てを消去してしまうので一つだけ消去したい時は
  //ms.find(値)でイテレータを出してからmultiset(itr)とする。

  //set
  set<int> s;
  //multisetと違うのは同じ要素は省略されてしまうところ
  //それ以外は同じなので省略

  //map
  map<char, int> m;
  m.insert({'a', 10});
  m.insert({'b', 20});
  m.insert({'c', 40});
  cout << m['a'] << endl;
  //10
  cout << m.size() << endl;
  cout << m.count('a') << endl;
  //map::count()はkey存在するかを確認する
  if(m.find('a') != m.end()) cout << "find" << endl;
  m.erase('a');
  //key部分を消す
  m.clear();
  //m.erase(all(m));でも同じ
  return 0;
}
