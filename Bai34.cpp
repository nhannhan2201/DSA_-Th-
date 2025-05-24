#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int k,n, m;
  vector<int> ke[1002];
  int used[1002];
  int dem[1002];
  void dfs(int u){
    used[u]=1;
    dem[u]++;
    for (int v : ke[u]){
      if (!used[v]){
        dfs(v);
      }
    }
  }
int main() {
  cin >> k >> n >> m;
  int people[k];
    for (int &x : people) cin >> x;
    while (m--){
      int x, y; cin >> x >>y;
      ke[x].push_back(y);
    } 
   for (int x : people){
     memset(used, 0, sizeof(used));
     dfs(x);
   }
   int cnt=0;
   for (int i=1; i<=n; i++){
    if (dem[i]==k) cnt++;
   }
   cout << cnt;
}
