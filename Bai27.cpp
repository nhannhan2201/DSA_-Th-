#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int cnt =0;
  int n, m;
  vector<int> ke[1002];
  int used[1002];
  vector<int> v;
  void nhap(){
    cin >> n >> m;
    for (int i=0; i<m; i++){
      int x, y; cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
  }
  void dfs(int u){
   cnt++;
    used[u]=1;
    for (int x : ke[u]){
      if (!used[x]){
         dfs(x);
      }
    }
  }
int main() {
   int res=0;
   nhap();
   for (int i=1; i<=n; i++){
      if (!used[i]){
         dfs(i);
         res=max(res,cnt);
         cnt=0;
      }
   }
   cout << res; 
}
