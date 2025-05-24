#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
    int color[1002];
    int ok=1;
  void dfs(int u, int c){
    color[u]=c;
    for (int v : ke[u]){
      if (!color[v]){
        dfs(v, 3-c);
      }
      if (color[v]==color[u]) ok=0;
    }
  }
int main() {
  cin >> n >> m;
    while (m--){
      int x, y; cin >> x >>y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
    dfs(1, 1); 
   if (ok) cout << "YES";
   else cout << "NO";
}
