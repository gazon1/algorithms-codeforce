// https://codeforces.com/contest/225/submission/2224868
// https://codeforces.com/contest/225/problem/D



#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define _DEBUG 1

#define DEBUG() if(_DEBUG)
#define PVAR(x) DEBUG(){ cout << (#x) << ": " << x << "; "; }

#define REP(x, n) for(int x = 0; x < (n); ++x)
#define elif(x) else if(x)
#define BTW(x, a, b) (x >= a && x <= b)


const int S_LEN = 9;


template<typename A, typename B>
ostream& operator <<(ostream& out, pair<A, B>& p){
    cout << "(" << p.first << "," << p.second << ") ";
}


int n, m;
vector<vector<int>> g;
vector<int> deg, used;
vector<pair<int, int>> ans;


void bfs(int u, vector<int> used, vector<int> p, vector<int> dist) {
  used[u] = true;
  p[u] = u;
  dist[u] = 0;
  queue<int> q;
  q.push(u);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < (int) g[u].size(); i++) {
      int v = g[u][i];
      if (!used[v]) {
        used[v] = true;
        p[v] = u;
        dist[v] = dist[u] + 1;
        q.push(v);
      }
    }
  }
}

typedef pair<int, int> Pnt;

int LEN, n, m;


struct Pos {
    Pnt t[S_LEN];
    Pnt& operator [](int i){ return t[i]; }
    const Pnt& operator [](int i) const { return t[i]; }
    bool operator <(const Pos& b) const {
        REP(i, LEN) if(t[i] != b[i]){
            return t[i] < b[i];
        }
        return false;
    }
    void print(){
        REP(i, LEN) cout << t[i] << "-";
        cout << endl;
    }
    Pnt nHead(Pnt mv){
        return Pnt(t[0].first+mv.first, t[0].second+mv.second);
    }
    bool valid(Pnt p){
        REP(i, LEN-1) if(p == t[i]) return false;
        return true;
    }
    Pos create(Pnt mv){
        Pos v = *this;
        REP(i, LEN-1) v[i+1] = t[i];
        v[0] = nHead(mv);
        return v;
    }
};

Pos start;
char Map[S_N][S_N];

void read(){
    cin >> n >> m;
    DEBUG() cout << n << "; " << m << endl;
    
    REP(r, n){
        string s;
	cin >> s;

	DEBUG() cout << s << endl;

	REP(c, m){
            char sign = s[c];
            Map[r][c] = sign;
            if(sign == '#') Map[r][c] = '#';
            else if(sign == '@') Map[r][c] = '@';
            else Map[r][c] = '.';
            if(BTW(sign, '1', '9')){
                start[sign-'1'] = Pnt(r, c);
                LEN = max(sign - '0', LEN);
            }
        }
    }
    PVAR(LEN);
    DEBUG() start.print();
}




class snake {
public:
  pair<int, int> headPos;
  bitset<3> bodyPos;
  snake() {

  }

  void read_table() {
    int n, m;
    scanf("%d %d", &n, &m);

  }
};


int main(int argc, char *argv[])
{
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	vector<vector<int>> table;

	

}

