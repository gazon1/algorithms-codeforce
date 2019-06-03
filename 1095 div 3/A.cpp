#include <bits/stdc++.h>
using namespace std;
#include <sstream>
#include <cassert>

#define _DEBUG 0
#define DEBUG() if(_DEBUG)
#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }

size_t getLen(string t) {
  int len_s = 0;
  int i = 1;
  int add = 1;
  size_t counter = 0;
  while (static_cast<int>(t.length()) - len_s > 0) {
    len_s += i;
    i += add;
    counter += 1;
  }
  return counter;
}

void testGetLen() {
  const size_t expected = 3;
  const size_t given = getLen(string("baabbb"));
  assert(3 == getLen("baabbb"));
}

string getAnswer(string s) {
  size_t len = getLen(s);
  int add = 1;
  int idx = 0;
  stringstream ss;
  for (int i = 0; i < static_cast<int>(len); ++i, ++add) {
    ss << s[idx];
    idx += add;
  }

  return ss.str();
}


void test_getAnswer() {
  assert(string("oops") == getAnswer(string("ooopppssss")));
}

int main(int argc, char *argv[])


{
  DEBUG() freopen("input.txt", "r", stdin);
  DEBUG() testGetLen();
  DEBUG() test_getAnswer();
  string s;
  int t;
  cin >> t >> s;
  cout << getAnswer(s);
  return 0;
}


