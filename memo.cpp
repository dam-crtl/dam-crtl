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
  //ハッシュマップを作るヒント10^6程度に変数が収まっていること
  //llでおさまらなさそうな時、doubleを使うという手がある

  //lcaについて~オイラーツアー+rmq(最小値取得)~
  //オイラーツアーでは根から頂点をおとづれた順のベクトルを作る(v(2*n))
  //さらに各頂点の深さに変換したものをrmqにし、各頂点を初めておとづれた情報をベクトル化する
  //深さ=rmq.prod(初めて(v), 初めて(u)))

  //「nまでの」と「nの」素因数分解の計算量はそれぞれO(nloglogn), O(sqrt(n)loglogn)

  //if(!(10%5))　でなければならない
  //if(!10%5)は通じない

  //配列でd[2000][2000]は危険

  //余が出る時にその回数を含める：
  ll A=10, cur=1;
  ll need = (cur + A - 1) / A;

  //1ll, 0llなどはllになる
  //llabs(int a);

  int a=10, b=10, c=10;
  VVV<int> dp(a, vector(b, vector<int>(c, 5)));
  //segfo->「ベクトル長」、「ループ」がおかしいのどちらかを疑う

  //for(int i=0; i<=sqrt(n); i++)よりも
  //for(int i=0; i*i<=n; i++)を利用する

  //imos+fenwicktree(1点のみ)
  //pairの大小は>で表現可能
  
  //exit(0):どんな状況でもプログラムを強制終了
  return 0;
}
