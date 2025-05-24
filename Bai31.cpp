#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n;
  vector<int> ke[1002];
    int used[1002];
    int ok=1;
    int sz[1002];
  int dfs(int u){
     used[u]=1;
     int res=1;
     for (int v : ke[u]){
      if (!used[v]){
        res+=dfs(v);
      }
     }
     sz[u]=res;
     return res;
  }
int main() {
  cin >> n;
    for (int i=0; i<n-1; i++){
      int x, y; cin >> x >>y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
    int cnt=0;
    dfs(1);
    for (int i=1; i<=n; i++){
        cnt +=sz[i];
    }
    cout << cnt;
}
