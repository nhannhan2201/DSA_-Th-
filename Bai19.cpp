#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
  int visited[1002];
 void nhap(){
    cin >> n >> m;
    while (m--){
      int x, y; 
      cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
 }
  void dfs(int u){
     visited[u]=1;
     for (int v : ke[u]){
       if (!visited[v]){
         dfs(v);
       }
     }
  }
int main() {
   int cnt=0;
   nhap();
   for (int i=1; i<=n; i++){
      if (!visited[i]){
         cnt++;
         dfs(i);
      }
   }
   int tru=0;
   for (int i=1; i<=n; i++){
      memset(visited, 0, sizeof(visited));
      visited[i]=1;
      int dem=0;
      for (int j=1; j<=n; j++){
         if (!visited[j]){
            dfs(j);
            dem++;
         }
      }
      if (dem>cnt) tru++;
   }
   cout << tru;
}


// cach 2:
 #include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
    int used[1002], AP[1002];
    int low[1002], disc[1002];
void nhap(){
    cin >> n >>m;
    while (m--){
      int x, y; cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
}
int timer;
 void dfs(int u, int par){
  timer++;
    used[u]=1;
    low[u]=disc[u]=timer;
    int dem=0;
    for (int v : ke[u]){
      if(v==par) continue;
      if (!used[v]){
        dfs(v, u);
        low[u]=min(low[v], low[u]);
        dem++;
        if(par != -1 && low[v] >= disc[u])
        AP[u]=1;
      }
      else {
        low[u]=min(low[u], disc[v]);
      }
    }
    if(par==-1 && dem>1 ) AP[u]=1;
 }
int main() {
    nhap();
    int cnt=0;
    for (int i=1; i<=n; i++){
      if (!used[i]){
        dfs(i, -1);
      }
    }
    for (int i=1; i<=n; i++){
      if (AP[i]) cnt++;
    }
    cout << cnt;
}

