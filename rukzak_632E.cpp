// https://codeforces.com/problemset/problem/632/E?locale=ru
// fft: https://cp-algorithms.com/algebra/fft.html
// another explanation of fft: https://codeforces.com/blog/entry/43499

#include <bits/stdc++.h>
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename A, typename B> inline ostream& operator<< (ostream& out, const pair<A, B>& p) { return out << "(" << p.x << ", " << p.y << ")"; }
template<typename T> inline ostream& operator<< (ostream& out, const vector<T>& a) { out << "["; forn(i, sz(a)) { if (i) out << ','; out << ' ' << a[i]; } return out << " ]"; }
template<typename T> inline ostream& operator<< (ostream& out, const set<T>& a) { return out << vector<T>(all(a)); }
 

const li INF64 = li(1e18);
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2*i];
        a1[i] = a[2*i+1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n/2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n/2] /= 2;
        }
        w *= wn;
    }
}




vector<int> multiply(vector<int> const& a, vector<int> const& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < static_cast<int>(a.size() + b.size()))
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

 
int n, k;
vector<int> a;
 
bool read() {
    if (!(cin >> n >> k)) return false;
    a.resize(n);
    for (int i=0; i < n; i++) assert(scanf("%d", &a[i]) == 1);
    return true;
}


#define forn(i, n) for (int i = 0; i < int(n); i++)

const int LOGN = 20, N = (1 << LOGN) + 3;

void binPow(int* a, int b) {
    static int ans[N];
    forn(i, 1 << LOGN) ans[i] = !i;
    while (b) {
      if (b & 1) multiply(vector<int>(begin(ans), end(ans)),
			  vector<int>(begin(a), end(a)));
        mul(a, a);
        b >>= 1;
    }
    forn(i, 1 << LOGN) a[i] = ans[i];
}



void solve() {
    static int ans[N];
    memset(ans, 0, sizeof(ans));
    for (int i=0; i <  sz(a); i++) ans[a[i]] = 1;
 
    binPow(ans, k);
 
    bool f = true;
    forn(i, 1 << LOGN)
        if (ans[i]) {
            if (f) f = false;
            else putchar(' ');
            printf("%d", i);
        }
    puts("");
}
 
 
int main() {
#ifdef SU1
  assert(freopen("input.txt", "rt", stdin));
  //assert(freopen("output.txt", "wt", stdout));
#endif
   
  cout << setprecision(10) << fixed;
  cerr << setprecision(5) << fixed;
 
  while (read()) {
    solve();
    //break;
  }
   
  return 0;
}
