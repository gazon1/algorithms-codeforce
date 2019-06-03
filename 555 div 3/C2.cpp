#include <bits/stdc++.h>

using namespace std;


pair<string, int> if_equals(vector<int> ar) {
  int t = 0;
  string str;
  
  while ( (t < j - 1) && (ar.at(t) > ar.at(t+1)) {
      t++;
      str += 'R';
    }
    
    int t2 = 0;
    string str2;
    while ( (t > 1) && (ar.at(t) > ar.at(t-1)) ) {
	t2++;
	str2 += 'L';
    }
    
    if (t1 < t2) {
      return make_pair(str2, t2);
    } else {
      return make_pair(str1, t1);
    }


    }


  void print_ans(pair<string, int> p) {
    
    cout << p.second << endl; << p.first;
  }
int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  //	freopen("output.txt", "w", stdout);
#endif
  int n;
  vector<int> ar(n);
  cin >> n;
  for (auto& i: ar) {
    cin >> i;
  }
  
  string moves;
  
  int last_el;
  int i = 0;
  int j = n - 1;

  if (ar.at(i) > ar.at(j)) {
    last_el = ar.at(i);
    i += 1;
    moves += 'L';
  } else if (ar.at(j) > ar.at(i)) {
    last_el = ar.at(j);
    j -= 1;
    moves += 'R';
  } else {
    pair<string, int> ans = if_equals(ar);
    print_ans(ans);
    return 0;
  }
  
  while ( (i <= j) && (max(ar.at(i), ar.at(j)) > last_el) ) {
    if ( ( (last_el < ar.at(i)) && (last_el  < ar.at(j) ) ||(  ( ar.at(j) < last_el) && ( last_el < ar.at(i) ))) {
	last_el = ar.at(i);
	moves += 'L'
	  i += 1
	  }
      else if (	last_el < ar.at(j) && last_el < ar.at(i)  || ar.at(i) < last_el  && last_el < ar.at(j)) {
	last_el = ar.at(j);
	moves += 'R';
	j -= 1;
      } else if( (ar.at(j) == ar.at(j)) and last_el < ar.at(i) ) {
	last_el = ar.at(j);
	moves += 'L';
	i += 1;
	
      } else {
	if_equals(ar[
      }

      }}

}
