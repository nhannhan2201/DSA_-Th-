#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
  int visited[1002];
  int parent[1002];
 void nhap(){
    cin >> n >> m;
    while (m--){
      int x, y; 
      cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
 }
  bool dfs(int u){
   visited[u]=1;
    for (int v : ke[u]){
       if (visited[v]==1 && v != parent[u]) return true;
       else if(!visited[v]){
          parent [v]=u;
          if (dfs(v)) return true;
       }
    }
    return false;
  }
int main() {
   nhap();
   for (int i=1; i<=n; i++){
      if (!visited[i]){
         if (dfs(i)){
            cout << 1;
            return 0;
         }
      }
   }
   cout << 0;
}
