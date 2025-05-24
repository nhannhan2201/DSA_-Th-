#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 int n, m, s, t;
 int visited[1002];
 vector<int> ke[1002];
 vector<int> path;
 void dfs(int u){
    if(visited[t]) return;
    path.push_back(u);
    visited[u]=1;
    if (u==t){
      for (int x : path){
         cout << x << " ";
      }
      return;
    }
     for (int v : ke[u]){
       if (!visited[v]){
         dfs(v);
       }
     }
    path.pop_back();
    visited[u]=0;
 }
int main() {
   cin >> n >> m >> s >> t;
   while (m--){
    int u, v;
    cin >> u >> v;
    ke[u].push_back(v);
   }
   for (int i=1; i<=n; i++){
      sort(ke[i].begin(), ke[i].end());
   }
   dfs(s);
   if (path.size()==0) cout << -1;
}
