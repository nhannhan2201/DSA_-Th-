#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  ll ans[102][102];
int main() {
   cin >> n >> m;
   for (int i=1; i<=n; i++){
      for (int j=1; j<=n; j++){
          if(i==j) ans[i][j]=0;
          else ans[i][j]=MOD;
      }
   }
   while (m--){
      int u, v, w;
      cin >> u >> v >> w;
      ans[u][v]=ans[v][u]=w;
   }
   for (int k=1; k<=n; k++){
      for (int i=1; i<=n; i++){
         for (int j=1; j<=n; j++){
            if (ans[i][j]>ans[i][k]+ans[k][j]){
                   ans[i][j]=ans[i][k]+ans[k][j];
            }
         }
      }
   }
   int q; cin >> q;
   while (q--){
      int x, y; cin >> x >> y;
      cout << ans[x][y] << endl;
   }
}
