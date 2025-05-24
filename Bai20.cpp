#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
  int visited[1002];
  vector<pair<int, int>> dscanh;
 void nhap(){
    cin >> n >> m;
    while (m--){
      int x, y; 
      cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
      dscanh.push_back({x, y});
    }
 }
  void dfs(int u, int x, int y){
     visited[u]=1;
     for (int v : ke[u]){
      if ((u==x && v==y) || (u==y && v==x)) continue;
       if (!visited[v]){
         dfs(v, x, y);
       }
     }
  }
int main() {
   int cnt=0;
   nhap();
   for (int i=1; i<=n; i++){
      if (!visited[i]){
         cnt++;
         dfs(i, 0, 0);
      }
   }
   int cau=0;
   for (auto e : dscanh){
      int x=e.first; int y=e.second;
      memset(visited, 0, sizeof(visited));
      int dem=0;
      for (int i=1; i<=n; i++){
         if (!visited[i]){
            dfs(i,x,y);
            dem++;
         }
      }
      if (dem>cnt) cau++;
   }
   cout << cau;
}
