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

tuple<int, size_t> max_elem(vector<int> ar) {
  int max = ar.at(0);
  size_t max_idx = 0;
  size_t t = ar.size();
  for (size_t i = 0; i < static_cast<size_t>(t); ++i) {
    if (max < ar.at(i)) {
      max = ar.at(i);
      max_idx = i;
    }
  }
  return tie(max, max_idx);
}

int min_elem(vector<int> ar) {
  int min = ar.at(0);
  for (auto& i : ar) {
    if (min > i) {
      min = i;
    }
  }

  return min;

}

int sol(vector<int> ar) {
 tuple<int, size_t> q(max_elem(ar));
  ar.erase(ar.begin() + get<1>(q));
  return get<0>(max_elem(ar)) - min_elem(ar);
}

void testProgr() {
  assert(2 == sol({1, 3, 3, 7}));
}

int main(int argc, char *argv[])
{
  DEBUG() testProgr();

  int t;
  string s;
  cin >> t;
  vector<int> ar;
  for (int i = 0, temp; i < t; ++i) {
    cin >>  temp;
    ar.push_back(temp);

  }
  cout << sol(ar);
  
  
  return 0;
}
