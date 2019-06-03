#include <bits/stdc++.h>
using namespace std;

long long a[100001];
int main(int argc, char *argv[])
{
  int n, m, l;
  int p, d;
  int query;

  cin >> n >> m >> l;
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] > l) ans += a[i-1] <= l;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> query;
    if (query == 0) cout << ans << endl;
    else {
      cin >> p >> d;
      if (a[p] <= l && a[p] +d > l) {
	  ans += 1 - (a[p-1]>l) -(a[p+1]>l);
      }
      a[p] += d;
    }

  }
  
  return 0;
}
