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
  string s="abcdefjhijklmnopqrstuvwxyz", t=s;
  int n = s.size();
  //文字列の長さを取得

  if(s.empty()) cout << "empty" << endl;
  //文字列が空かを判定

  string s1="a", s2="b";
  cout << s1+s2 << endl;
  //文字列の結合

  cout << s.substr(0) << endl;
  //abcdefghijklmnopqrstuvwxyz
  //s.substr(i):i番目以降の文字列を取り出す

  cout << s.substr(2, 4) << endl;
  //cdef
  //s.substr(i, j):i番目以降の文字列をj文字だけ取り出す

  cout << s.erase(1) << endl;
  //a
  //s.erase(i):i文字目以降の文字列を削除

  s=t;
  cout << s.erase(3, 4) << endl;
  //s.erase(i, j):i番目以降の文字列をj文字だけ削除

  s=t;
  cout << s.find("a") << endl;
  //s.find("char"):文字列s中でcharの最初の出現位置を返す
  //見つからない見つからない場合は非常に大きな数(string::npos)になる

  cout << s.replace(2, 1, "d") << endl;
  //s.replace(i, j, "char"):i番目から数えてj個の文字列をcharに置換

  s=t;
  if(s[0]=='b') cout << "b" << endl;
  //文字列比較:""ではなく''を使うことに注意

  if(s[0] >= 'a' && s[0] <= 'z') cout << "small" << endl;
  if(islower(s[0])) cout << "small" << endl;
  //文字が英小文字かどうか判定

  if(s[0] >= 'A' && s[0] <= 'Z') cout << "large" << endl;
  if(isupper(s[0])) cout << "large" << endl;
  //文字が英大文字かどうか判定

  if(s[0] >= '0') cout << "number" << endl;
  //文字が数字かどうか判定
  //isalpha(s[0]) アルファベットがどうか
  //isdigit(s[0]) 数字かどうか

  string s3 = "5";
  int a = s3[0] - '0';
  //文字型を数値型に変換
  //他にも stoi(s), stoll(s), stod(s)

  string s4 = to_string(a);
  cout << s4 << endl;
  //数値型を文字型に変更

  sort(all(s));
  //文字列昇順並び替え
  //順番は 数字'0'~'9' -> 英大文字 'A'~'Z' -> 英小文字 'a'~'z'
  reverse(all(s));
  //文字列反転

  cout << s[0] + n << endl;
  //英文字をアルファベット順にn個ずらして出力

  s.push_back('2');
  //末尾に文字追加
  s.pop_back();
  //末尾の文字列削除

  //回文判定
  s = t;
  reverse(all(t));
  if(s==t) cout << "Palindrome" << endl;

  if(s[0]^s[1]^s[2]=='a'^'b'^'c')
  //任意の文字判定
  //今回の場合s[0], s[1], s[2]のうちいずれかが'a','b','c'に該当すれば真

  if(s=="ARC") yes;
  if(s[0]=='A') yes;
  //ifの条件について、sがstring型なのかchar型なのかで"",''かが異なる。
  //string型では" "が用いられ、char型では' 'が用いられる。

  cout << count(all(s), 'c') << endl;
  //文字型なので''で囲む

  //回転変化(n)
  //左に回転
  rotate(s.begin(), s.begin()+1, s.end());
  //右に回転
  rotate(s.rbegin(), s.rbegin()+1, s.rend());
  rotate(s.begin(), s.end()-1, s.end());

  //s.back() == s[n-1];
  //s.back()はsの後方

  // fill(all(s), '#');
  //'#'で埋められた文字列を返す。
  return 0;

  //参考URL:https://qiita.com/seal_qiita/items/d62192f8d0b1e4ca8de2
}

