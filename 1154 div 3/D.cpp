#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define _DEBUG 1

#define DEBUG() if(_DEBUG)
#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define elif(x) else if(x)
#define BTW(x, a, b) (x >= a && x <= b)


int n, b, a;
int maxa;


void use_battery(int s) {
  if ( s == 1 ) a = min ( a + 1, maxa );
  --b;
}

void use_accum() {
  --a;
}

int main() {


  cin >> n >> b >> a;
  maxa = a;
  vector<int> s(n);
  for (int i = 0; i < n; ++i)  cin >> s.at(i);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    if ( a == 0 && b == 0 ) break;
    else if ( a == 0 ) use_battery(s.at(i));
    else if ( b == 0 ) use_accum();
    else if ( s.at(i) == 1 && a < maxa ) use_battery(s.at(i));
    else use_accum();

    ans++;

  }

  cout << ans;
}
