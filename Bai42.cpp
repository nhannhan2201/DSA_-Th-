#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

  int n, m;
  int sz[200006];
  int parent[200006];
  int find(int u){
   if (u==parent[u]){
      return u;
   }
   else return parent[u]=find(parent[u]);
  }
  int res=0;
  bool Union(int u, int v){
       u=find(u);
       v=find(v);
      if (u==v) return false;
      else {
         if(sz[v]<sz[u]);
            swap(u, v);
            sz[v]+=sz[u];
            res=max(res, sz[v]);
            parent[u]=v;
            return true;
      }
  }
  void init(){
   for (int i=1; i<=n; i++){
      sz[i]=1;
      parent[i]=i;
   }
  }
int main() {
   cin >> n >> m;
   init();
   int cnt=n;
   while (m--){
      int x, y; cin >> x >> y;
      if (Union(x, y)) cnt--;
      cout << cnt << " " << res << endl;
   }
}
