#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m, s;
  vector <pair<int, int>> ke[1002];
  set<pair<int, int>> se;
  int ans[1002];
  void nhap(){
    cin >> n >> m >> s;
    for (int i=0; i<m; i++){
          int x, y, z;
          cin >> x >> y >> z;
          ke[x].push_back({y, z});
          ke[y].push_back({x, z});
    }
    se.insert({0, s});
    for (int i=1; i<=n; i++){
      ans[i]=MOD;
    }
    ans[s]=0;
  }
  void xuly(){
    while (se.size()){
      auto x=*se.begin();
      se.erase(se.begin());
      int u=x.second;
      for (auto y : ke[u]){
         int v=y.first, w=y.second;
         if(ans[v] > ans[u]+w){
            se.erase({ans[v], v});
            ans[v]=ans[u]+w;
            se.insert({ans[v], v});
         }
      }
    }
  }
  
int main() {
   nhap();
   xuly();
   for (int i=1; i<=n; i++){
      cout << ans[i] << " ";
   }
}
