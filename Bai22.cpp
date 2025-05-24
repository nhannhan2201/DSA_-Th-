#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
  int color[1002];
  int parent[1002];
 void nhap(){
    cin >> n >> m;
    while (m--){
      int x, y; 
      cin >> x >> y;
      ke[x].push_back(y);
    }
 }
  bool dfs(int u){
    color[u]=1;
    for (int v : ke[u]){
      if (!color[v]){
         if (dfs(v)) return true;
      }
      if (color[v]==1) return true;
    }
    color[u]=2;
    return false;
  }
int main() {
    nhap();
    for (int i=1; i<=n; i++){
      if (color[i]==0){
         if (dfs(i)){
            cout << 1 ; return 0;
         }
      }
    }
    cout << 0;
}
