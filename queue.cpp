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
  //queue
  queue<int> q;
  q.push(0);
  q.pop();
  if(!q.empty()) cout << "empty" << endl;

  //dequeue
  deque<int> deq;
  deq.push_front(0);
  deq.push_back(1);
  deq.push_back(2);
  deq.pop_front();
  deq.pop_back();
  deq.clear();
  if(!deq.empty()) cout << "empty" << endl;

  //priority_queue
  minpq<int> pq1; //降順に並ぶ
  maxpq<int> pq2; //昇順に並ぶ
  pq1.push(0);
  pq1.push(-1);
  int a1 = pq1.top();
  pq1.pop();
  cout << a1 << endl;
  // -1

  //stack
  stack<int> a;
  a.push(179); // その時点で下から順に {179}
  a.push(173); // その時点で下から順に {179, 173}
  a.push(156); // その時点で下から順に {179, 173, 156}
  int x1 = a.top();
  a.pop(); // その時点で下から順に {179, 173}
  a.push(117); // その時点で下から順に {179, 173, 117}
  a.push(202); // その時点で下から順に {179, 173, 117, 202}
  int x2 = a.top();
  a.pop(); // その時点で下から順に {179, 173, 117}
  int x3 = a.top();
  int x4 = a.size();
  int x5 = 0;
  if (a.empty()) x5 = 10000;
  
  return 0;
}

