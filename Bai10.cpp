#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 bool visited[1002];
 set<int> ke[1002];
  void dfs(int s){
      visited[s]=1;
      cout << s << " ";
      for (auto x : ke[s]){
        if (!visited[x]){
            dfs(x);
        }
      }
  }

int main() {
   int n, m, s;
   cin >> n >> m >> s;
   while (m--){
     int u, v;
     cin >> u >> v;
     ke[u].insert(v);
   }
   dfs(s);
}
