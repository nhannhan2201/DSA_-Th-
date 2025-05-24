#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

 int n, m;
 vector<int> ke[1002];
 int cnt=1;
 int tplt[1002];
  void dfs(int u){
        tplt[u]=cnt;
        for (int v : ke[u]){
         if (!tplt[v]){
            dfs(v);
         }
        }
  }
int main() {
   cin >> n >> m;
   while (m--){
      int u, v; cin >> u >> v;
      ke[u].push_back(v);
      ke[v].push_back(u);
   }
   int q; cin >> q;
   for (int i=1; i<=n; i++){
      if (!tplt[i]){
         dfs(i);
         cnt++;
      }
   }
   while (q--){
      int s,t; cin >> s >> t;
      if (tplt[s]==tplt[t]) cout << 1 << endl;
      else cout << -1 << endl;
   }
}
