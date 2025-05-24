#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 int n, m, s;
 set <int> ke [1002];
 int visited[1002];
  void bfs(){
     queue <int> q;
     q.push(s);
     visited[s]=1;
     while (q.size()){
        int u=q.front();
        q.pop();
        cout << u << " ";
        for (int v : ke[u]){
          if (!visited[v]){
            q.push(v);
            visited[v]=1;
          }
        }
     }
  }
int main() {
   cin >> n >> m >>s;
   while (m--){
    int u,v;
    cin >> u >> v;
    ke[u].insert(v);
   }
   bfs();
}
