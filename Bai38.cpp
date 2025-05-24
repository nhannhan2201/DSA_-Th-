#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  vector<int> ke[1002];
    int used[1002];
    int res=0;
    int a[1002];
 void dfs(int u, int cnt){
     if (a[u]) cnt++;
     else cnt=0;
     if (cnt>m) return;
     used[u]=1;
      if(ke[u].size()==1) res++;
      else{
      for (int v : ke[u]){
       if(!used[v]){
          dfs(v, cnt);
       }
     }
    }
 }
int main() {
     cin >> n >>m;
     for (int i=1; i<=n; i++){
      cin >> a[i];
     }
     for (int i=1; i<n; i++){
      int x,y; cin >> x >> y;
      ke[x].push_back(y);
      ke[y].push_back(x);
     }
     dfs(1,0);
     cout << res;
}
