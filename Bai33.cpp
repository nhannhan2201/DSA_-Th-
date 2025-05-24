#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[100002];
  int used[100002];
  int cnt=0;
  int t;
  void nhap(){
    cin >> n >> m;
     t=m;
    while (m--){
      int x, y; cin >> x >>y;
      ke[x].push_back(y);
      ke[y].push_back(x);
    }
  }
  void dfs(int u){
    cnt++;
    used[u]=1;
    for (int v : ke[u]){
      if (!used[v]){
        dfs(v);
      }
    }
  }
int main() {
  nhap();
  ll total=0;
  for (int i=1; i<=n; i++){
    if (!used[i]){
      dfs(i);
      total=total + 1ll*cnt*(cnt-1)/2;
      cnt=0;
    }
  }
   if (total==t) cout << "YES";
   else cout << "NO";
}
