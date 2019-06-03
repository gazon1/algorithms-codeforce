#include <bits/stdc++.h>
using namespace std;


int get_1_max_team(int n, int skills[]) {
  sort(skills, skills + n);

  int max_team = 0; // maximum size of a team
  int j = 1;

  int idx = 0; // index of skills array where a team starts
  for (int i = 0; i < n; i++) {
    if (skills[i] == -1) {
      ++j;
      continue;
    }
    while ( (j < n) && abs(skills[i] - skills[j] ) <= 5 ) {
      ++j;
    }
    if (j - i > max_team) {
      idx = i;
      max_team = j - i;
    }
  }

  for (int i = idx; i < max_team + idx; i++) {
    skills[i] = -1; // set flags indicating that we've alreade taken these guys in a maximum size team
  }
  
  return  max_team;

}

void print_skills(int skills[], int n) {
  for (int i = 0; i < n; ++i) cout << skills[i] << " ";
  cout << endl << endl;
}

int main() {
#ifdef _DEBUG
  freopen("input_E.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


  int n, m;

  cin >> n >> m;
  int skills[n];
  for (int i = 0; i < n; i++) {
    cin >> skills[i];
  }
  int cnt = 0;
  int temp;

  sort(skills, skills +n);
  #ifdef _DEBUG
  print_skills(skills, n);
  #endif
   for (int i = 0; i < m; ++i) {
     temp = get_1_max_team(n, skills);
     #ifdef _DEBUG
     print_skills(skills, n);
     #endif
     cnt += temp; 
   }
   cout << cnt << endl;
  return 0;

}
