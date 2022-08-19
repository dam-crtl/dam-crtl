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
  int x = 100, n = 78, m = 33;
  //x^n mod cを求める
  ll nu = pow_mod(x, n, m);

  //xy=1 mod mとなるyのうち(0 <= y < m)を満たすものを返す
  ll nu1 = inv_mod(x, m);

  V<ll> r={3, 4}, m1={5, 6};
  //x=r[i] mod m1[i] となる中国剰余定理問題をとく
  //O(nlog(lcm(m[i])))
  pair<ll, ll> ans = crt(r, m1);

  int a=10, b=1000;
  //sumi_{0~n} {floor((a*i+b)/m)}
  //O(log(n+m+a+b))
  ll answer = floor_sum(n, m, a, b);

  mint c=1000, d=0;
  c = c.inv();
  //c = inv_mod(c, mod);
  //rep(i, 0, n)計算の時はfor(mint i=0;i<n;i++)の方がいいかも
  cout << c.val() << endl;
  if (c.val() > d.val())
    yes;
  //「.val()」を忘れない
  mint(2).pow((ll)1000 * 2);
  //intなどをmintに変換 mint(2)
  //mint t.pow(s)

  double l = log(4);
  //この場合底ネイピア数の対数が取れる
  l = log(4)/log(2);
  //こうすると底が2になる
  double pi = M_PI;
  double s = sin(pi/2.0);
  //double sin(double x) -1~1
  double co = cos(pi);
  //double cos(double x) -1~1
  double t=tan(pi/4.0);
  //double tan(double x)
  double as = asin(1.0);
  //double asin(double x) -pi/2~pi/2
  double  ac = acos(0.0);
  //double acos(double x) 0~pi
  double at = atan(1.0);
  //double atan(double x) -pi/2~pi/2
  double at1 = atan2(1.0, 1.0);
  //double atan2(double y, double x) -pi~pi
  //x, y共に0の時 0

  //小数点を反映した出力
  printf("%.3lf\n", s);
  printf("%.4lf\n", co);
  printf("%.5lf\n", t);
  printf("%.6lf\n", as);
  printf("%.7lf\n", ac);
  printf("%.9lf\n", at);
  printf("%.10lf\n", at1);

  //小数入力をさせる場合、string sを作り、cin >> sとして入力させる方法が一般的である

  int num=100000;
  ll i=1;
  ll q = max(0ll, (ll)num); //ok
  //q = max(i, num); //ng
  //またキャスト適切に用いることでオーバーフローを避けたりもしている

  V<int> vec;
  int cnt=0;
  rep(i, 0, 10) vec.pb(i);
  do{
    cnt++;
  }while(next_permutation(all(vec)));
  //next_permutationは数字型のベクトルしか反映できない。
  //よって文字列等を動かしたいならばハッシュマップを作ると良い。

  double x = 1.0, y = 1.0;
  double c = hypot(x, y);
  //hypot(double, double) 直角三角形の斜辺を求める

  int x = gcd(0, 10);
  //x=10;
  return 0;
}

