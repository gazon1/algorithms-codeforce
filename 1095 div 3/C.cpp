
#include <vector>
#include <cassert>
#include <bits/stdc++.h>
using namespace std;
#include <sstream>
#include <cassert>
#include <tuple>
#define _DEBUG 0
#define DEBUG() if(_DEBUG)
#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }

string sol(int, int);

void test() {
  PVAR(sol(9, 4));
  stringstream answer;

  answer << "YES" << endl << "1 2 2 4";
  assert(sol(9, 4) == answer.str());

  answer.str(string());
  answer << "YES" << endl << "8";
  PVAR(sol(8, 1));
  assert(sol(8, 1) == answer.str());
}



string sol(int n, int k) {
  queue<int> q;
  stringstream ss;
  map<int, int> ans;
  
  for (int i = 0, t; i < 30; ++i) {
    t = 1 << i;
    if (n & t) {
      if (i > 0) q.push(t);
      ans[t]++;
    }
  }

  int cnt = static_cast<int>(ans.size());
  if (cnt > k) {
    ss << "NO";
    return ss.str();
  }
  while (cnt < k && !q.empty()) {
    int z = q.front();
    q.pop();
    ans[z]--;
    ans[ z / 2 ] += 2;

    if (z / 2 > 1) {
      q.push(z / 2);
      q.push(z / 2);
    }
    cnt++;
  }

  if (cnt < k) {
    ss << "NO";
    return ss.str();
  }

  ss << "YES" << endl;
  for (auto x : ans) {
    for (int i = 0; i < x.second; ++i) {
      ss << x.first << " ";
    }
  }

  string answer(ss.str());
  return answer.substr(0, static_cast<int>(answer.size()) - 1);

}


int main(int argc, char *argv[])
{
  int n, k;
  cin >> n >> k;
  string answer(sol(n, k));
  DEBUG() test();
  cout << answer;
  
  return 0;
}


