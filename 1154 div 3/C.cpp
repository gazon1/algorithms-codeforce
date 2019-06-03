#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define _DEBUG 1

#define DEBUG() if(_DEBUG)
#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define elif(x) else if(x)
#define BTW(x, a, b) (x >= a && x <= b)


vector<int> idx({0, 1, 2, 0, 2, 1, 0});

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];

  int full = min({a[0] / 3, a[1] / 2, a[2] / 2});
  a[0] -= 3 * full;
  a[1] -= 2 * full;
  a[2] -= 2 * full;

  int ans = 7 * full;
  for (int start = 0; start < 7; ++start) {
    int day = start;
    int curr = 0;
    vector<int> b = a;


    while (b[idx[day]] > 0) {
      b[idx[day]]--;
      day = (day + 1) % 7;
      curr++;
    }

    ans = max(ans, 7 * full + curr);

  }

  cout << ans;
}
