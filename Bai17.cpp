#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 int n, m, s, t;
 int visited[1002];
 vector<int> ke[1002];
 int pre[1002];
 void bfs(){
    queue <int> q;
    q.push(s);
    visited[s]=1;
    pre[s]=-1;
    while (q.size()){
      int u=q.front();
     q.pop();
      if (u==t){
         string path="";
         while (u!=-1){
            path=to_string(u)+ " " +path;
            u=pre[u];
         }
         cout << path ; return;
      }
      for(int v : ke[u]){
           if (!visited[v]){
            pre[v]=u;
            visited[v]=1;
            q.push(v);
           }
      }
    }
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
   bfs();
   if (visited[t]==0){
      cout << -1;
   }
}
