#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m, s;
  vector<int>  ke[1002];
  int visited[1002];
  void nhap(){
   cin >> n >> m >> s;
   for (int i=0; i<m; i++){
      int x, y; cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
   }
   for (int i=1; i<=n; i++){
      sort (ke[i].begin(), ke[i].end());
   }
  }
  void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=1;
    while (!q.empty()){
      int v=q.front();
      q.pop();
      for (int x : ke[v]){
         if (!visited[x]){
            cout << v << "->" << x << endl;
            q.push(x);
            visited[x]=1;
         }
      }
    }
  }
int main() {
     nhap();
     bfs(s);
}
